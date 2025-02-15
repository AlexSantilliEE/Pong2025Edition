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

class Game
{
	public:
		Game();

		GameStates GetGameState() { return gameState; };

		sf::RenderWindow window;
		sf::Clock clock;

		// Paddles:
		sf::RectangleShape playerPaddle;
		sf::RectangleShape compPaddle;

		// Ball:
		sf::CircleShape ball;

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
