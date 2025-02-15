#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

enum GameStates
{
	MAIN_MENU,
	GAME_STOPPED,
	GAME_RUNNING
};

class Game : public sf::RenderWindow, public sf::Clock
{
	public:
		Game();

		GameStates getGameState();
		void startPong();

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
