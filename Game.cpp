#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

Game::Game()
{
	cout << "Launching Window...\n";
	this->screenSizeX = 800;
	this->screenSizeY = 600;
	this->title = "PONG: 2025 Edition";
	this->settings.antialiasingLevel = 8;
	create( sf::VideoMode( this->screenSizeX, this->screenSizeY ), this->title, sf::Style::Default, this->settings );
	
	cout << "Loading Font...\n";
	if ( !this->font.loadFromFile( "cour.ttf" ) )
	{
		cout << "Error loading font" << endl;
	}

	return;
}

GameStates Game::getGameState() 
{
	return this->gameState;
}
