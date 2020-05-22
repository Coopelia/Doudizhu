#include"game.h"

Game::Game()
{
	this->app = new RenderWindow(VideoMode(WIDTH, HEIGHT), "ChinesePoker", Uint32(5));
	this->app->setFramerateLimit(60);
	start_scene.app = this->app;
	game_scene.app = this->app;
	this->game_scene.Initial(app);
	this->start_scene.Initial(app);
	this->OnStartScene = true;
	this->OnPlayScene = false;
	this->isOvered = false;
	this->isOnWel = true;
	this->gameOver = 0;
	(*app).setFramerateLimit(60);
}

Game::~Game()
{
	delete this->app;
}

void Game::GameOver()
{
	if (gameOver == 1)
	{
		if (!isOvered)
		{
			game_scene.bgm.stop();
			isOvered = true;
		}
	}
	if (gameOver == 2)
	{
		if (!isOvered)
		{
			game_scene.bgm.stop();
			isOvered = true;
		}
	}
}

void Game::Update()
{
	if (OnStartScene)
	{
		if (start_scene.isExit)
		{
			OnStartScene = false;
			OnPlayScene = true;
			start_scene.isExit = false;
		}
		if (!start_scene.isRunning)
		{
			game_scene.SceneClose();
			start_scene.Start();
		}
		start_scene.Update();
	}
	if (OnPlayScene)
	{
		if (game_scene.isExit)
		{
			OnStartScene = true;
			OnPlayScene = false;
			game_scene.isExit = false;
		}
		if (!game_scene.isRunning)
		{
			start_scene.SceneClose();
			game_scene.Start();
		}
		game_scene.Update();
	}
}

void Game::Input(Event& e)
{
	if (OnStartScene)
		start_scene.Input(e);
	else if (OnPlayScene)
		game_scene.Input(e);
	e.type = Event::Count;
}

void Game::Draw()
{
	if (OnStartScene)
		start_scene.Draw();
	else if (OnPlayScene)
		game_scene.Draw();
}

void Game::show_Wel(int i)
{
	std::stringstream ss;
	ss << "assets/image/wel/ddz-wel_" << i << ".png";
	tWel.loadFromFile(ss.str());
	sWel.setTexture(tWel);
	sWel.setPosition(0, 0);
	(*app).draw(sWel);
}

void Game::Run()
{
	int i = 1000;
	while ((*app).isOpen())
	{
		Event e;
		(*app).pollEvent(e);
		if (e.type == Event::Closed)
			(*app).close();
		if (isOnWel)
		{
			show_Wel(i++);
			if (i == 1296)
				isOnWel = false;
		}
		if (!isOnWel)
		{
			Input(e);
			Update();
			Draw();
		}
		(*app).display();
	}
}