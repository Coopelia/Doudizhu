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
	if (start_scene.isExit)
	{
		OnStartScene = false;
		OnPlayScene = true;
	}
	if (game_scene.isExit)
	{
		OnStartScene = true;
		OnPlayScene = false;
	}
	start_scene.Update();
	game_scene.Update();
}

void Game::Run()
{
	while ((*app).isOpen())
	{
		Update();
		Event e;
		while ((*app).pollEvent(e))
		{
			if (e.type == Event::Closed)
				(*app).close();
		}
		if (OnStartScene)
		{
			start_scene.isExit = false;
			if (!start_scene.isRunning)
			{
				game_scene.SceneClose();
				start_scene.Start();
			}
			start_scene.Input(e);
			start_scene.Draw();
		}
		else if (OnPlayScene)
		{
			game_scene.isExit = false;
			if (!game_scene.isRunning)
			{
				start_scene.SceneClose();
				game_scene.Start();
			}
			game_scene.Input(e);
			game_scene.Draw();
		}
		(*app).display();
	}
}