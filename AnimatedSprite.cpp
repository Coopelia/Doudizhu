#include "AnimatedSprite.hpp"
#include "Animation.hpp"

#include <cassert>
//动画播放类

AnimatedSprite::FuncType AnimatedSprite::defaultFunc = []()->void{};
//构造函数只初始化所有不同属性的正确值:
AnimatedSprite::AnimatedSprite(Animation* animation,Status status,const sf::Time& deltaTime,bool loop,int repeat) : on_finished(defaultFunc),_delta(deltaTime),_loop(loop), _repeat(repeat),_status(status)
{
    setAnimation(animation); 
}
//这个函数只在当前的纹理不同的情况下才会改变新的纹理，并将帧重设为新动画的第一个帧。注意，至少有一个帧必须存储在作为参数接收的新动画中。
void AnimatedSprite::setAnimation(Animation* animation)
{
    if(_animation != animation)
    {
        _animation = animation;
        _elapsed = sf::Time::Zero;
        _currentFrame = 0;
        setFrame(0,true);
    }
}

Animation* AnimatedSprite::getAnimation()const
{
    return _animation;
}

void AnimatedSprite::setFrameTime(sf::Time deltaTime)
{
    _delta = deltaTime;
}

sf::Time AnimatedSprite::getFrameTime()const
{
    return _delta;
}

void AnimatedSprite::setLoop(bool loop)
{
    _loop = loop;
}

bool AnimatedSprite::getLoop()const
{
    return _loop;
}
void AnimatedSprite::setRepeate(int nb)
{
    _repeat = nb;
}

int AnimatedSprite::getRepeate()const
{
    return _repeat;
}

void AnimatedSprite::play()
{
    _status = Playing;
}
void AnimatedSprite::pause()
{
    _status = Paused;
}

void AnimatedSprite::stop()
{
    _status = Stopped;
    _currentFrame = 0;
    setFrame(0,true);
}

AnimatedSprite::Status AnimatedSprite::getStatus()const
{
    return _status;
}
//此函数将当前帧更改为从内部动画类获取的新帧。
void AnimatedSprite::setFrame(size_t index)
{
    assert(_animation);
    _currentFrame = index % _animation->size();
    setFrame(_currentFrame,true);
}
//此函数改变显示图像的颜色掩码。为此，我们将每个内部顶点的颜色设置为作为参数接收的新颜色:
void AnimatedSprite::setColor(const sf::Color& color)
{
    _vertices[0].color = color;
    _vertices[1].color = color;
    _vertices[2].color = color;
    _vertices[3].color = color;
}
/////////////////////////////////////////////////////////////////////
//它的工作是在达到时间限制时从当前帧切换到下一帧。一旦我们到达动画的最后一帧，你可以做以下事情:
//(1)根据_loop值，重置第一个动画帧进行播放
//(2)如果_repeat值授权我们这样做，重置第一个动画帧进行播放
//(3)在所有其他情况下，我们通过调用内部回调来触发“on fnish”事件
void AnimatedSprite::update(const sf::Time& deltaTime)
{
    if(_status == Playing && _animation)
    {
        _elapsed += deltaTime;
        if(_elapsed > _delta)
        {//need to change frame
            _elapsed -= _delta;
            if(_currentFrame + 1 < _animation->size())
                ++_currentFrame;
            else
            {//end of frame list
                _currentFrame = 0;
                if(!_loop)
                {//can we make another loop an the frames?
                    --_repeat;
                    if(_repeat<=0)
                    {//no, so we stop
                        _status = Stopped;
                        on_finished();
                    }
                }
            }
        }
		//update the frame
        setFrame(_currentFrame,false);
    }
}
//该函数的目的是将不同顶点的属性更新为内部动画类的属性（即位置和纹理坐标）
void AnimatedSprite::setFrame(size_t index,bool resetTime)
{
    if(_animation)
    {
        sf::IntRect rect = _animation->getRect(index);

        _vertices[0].position = sf::Vector2f(0.f, 0.f);
        _vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
        _vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
        _vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

        float left = static_cast<float>(rect.left);
        float right = left + static_cast<float>(rect.width);
        float top = static_cast<float>(rect.top);
        float bottom = top + static_cast<float>(rect.height);

        _vertices[0].texCoords = sf::Vector2f(left, top);
        _vertices[1].texCoords = sf::Vector2f(left, bottom);
        _vertices[2].texCoords = sf::Vector2f(right, bottom);
        _vertices[3].texCoords = sf::Vector2f(right, top);
    }

    if(resetTime)
        _elapsed = sf::Time::Zero;
}
//因为该类继承了sf::Transformable，所以我们需要考虑可能的几何变换。我们设置要使用的纹理，并最终绘制内部顶点数组
void AnimatedSprite::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    if (_animation && _animation->_texture)
    {
        states.transform *= getTransform();
        states.texture = _animation->_texture;
        target.draw(_vertices, 4, sf::Quads, states);
    }
}