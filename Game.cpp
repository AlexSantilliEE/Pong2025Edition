#include <iostream>
#include <vector>
#include <random>
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
	this->window.create( sf::VideoMode( this->screenSizeX, this->screenSizeY ), this->title, sf::Style::Default, this->settings );
	
	cout << "Loading Font...\n";
	if ( !this->font.loadFromFile( "cour.ttf" ) )
	{
		cout << "Error loading font" << endl;
	}

	this->playerPaddle.setSize( sf::Vector2f( 50.0f, 10.0f ) );
	this->compPaddle.setSize( sf::Vector2f( 50.0f, 10.0f ) );
	this->playerPaddle.setPosition( sf::Vector2f( ( this->screenSizeX / 2 ) - 25.0f, this->screenSizeY - 10.0f ) );
	this->compPaddle.setPosition( sf::Vector2f( ( this->screenSizeX / 2 ) - 25.0f, 0.0f ) );
	
	this->ball.setRadius( 10.0f );
	this->ball.setPosition( sf::Vector2f( ( this->screenSizeX / 2 ), ( this->screenSizeY / 2 ) ) );

	this->gameState = GAME_START;

	return;
}

void Game::startGame() 
{
	this->gameState = GAME_RUNNING;
	
	// Give the ball a random direction:
	srand( time(0) );
	this->ball.theta = rand() % 360;
	this->ball.xSpeed = this->ball.speed * cosf( this->ball.theta );
	this->ball.ySpeed = this->ball.speed * sinf( this->ball.theta );

	return;
}
