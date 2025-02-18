#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

enum GameStates
{
	GAME_STOPPED,
	GAME_START,
	GAME_RUNNING
};

class Paddle : public sf::RectangleShape
{
	public: 

		Paddle() : speed( 0.15f ) {};
		
		float speed;

};

class Ball : public sf::CircleShape
{
public:

	Ball() : speed( 0.05f ), theta( 0.0f ) {};

	float speed;
	float theta;
	float xSpeed;
	float ySpeed;

};

class Game
{
	public:
		Game();

		GameStates GetGameState() { return gameState; };
		void startGame();

		sf::RenderWindow window;
		sf::Clock clock;

		// Paddles:
		Paddle playerPaddle;
		Paddle compPaddle;

		// Ball:
		Ball ball;

	private:
		// states:
		GameStates gameState;

		// window settings:
		int screenSizeX;
		int screenSizeY;
		string title;
		sf::ContextSettings settings;

		// font:
		sf::Font font;
		
};
