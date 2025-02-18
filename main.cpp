#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

int main()
{

    // Start the game, create gameclock, open the window
    Game game;

    while ( game.window.isOpen() )
    {
        // Poll events & react to events that occured in the window
        sf::Event event;
        while ( game.window.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
                game.window.close();
        }

        sf::Mouse mouse;
        sf::Keyboard keyboard;

        sf::Time elapsed = game.clock.restart();

        // before the game even begins
        if ( game.GetGameState() == GAME_START )
        {
            if ( mouse.isButtonPressed( sf::Mouse::Left ) ) 
            {
                game.startGame();
            }
        }

        // while the game is running (check collisions, update ball position, computer paddle position, player position)
        if ( game.GetGameState() == GAME_RUNNING )
        {
            // check for collisions and adjust velocity vectors accordingly
            if ( sf::FloatRect( game.playerPaddle.getGlobalBounds() ).intersects( game.ball.getGlobalBounds() ) )
            {
                game.ball.ySpeed *= -1;
            }

            if ( sf::FloatRect( game.compPaddle.getGlobalBounds() ).intersects( game.ball.getGlobalBounds() ) )
            {
                game.ball.ySpeed *= -1;
            }

            if ( ( game.ball.getPosition().x ) >= ( game.window.getSize().x ) )
            {
                game.ball.xSpeed *= -1;
            }
            if ( ( game.ball.getPosition().x ) <= ( 0 ) )
            {
                game.ball.xSpeed *= -1;
            }
            

            // update ball's position
            game.ball.move( sf::Vector2f( game.ball.xSpeed, game.ball.ySpeed ) );
            
            // update player's paddle position
            if ( keyboard.isKeyPressed( sf::Keyboard::Left ) )
            {
                game.playerPaddle.move( sf::Vector2f( game.playerPaddle.speed * cosf( 180.0f ), 0.0f ) );
            }
            else if ( keyboard.isKeyPressed( sf::Keyboard::Right ) )
            {
                game.playerPaddle.move( sf::Vector2f( game.playerPaddle.speed * cosf( 0.0f ), 0.0f ) );
            }

            // update computer paddle position (TODO: make the ai more sophisticated? lol, fine for testing purposes)
            game.compPaddle.setPosition( sf::Vector2f( game.ball.getPosition().x, game.compPaddle.getPosition().y ) );


        }

        // Clear the back buffer
        game.window.clear();

        game.window.draw( game.playerPaddle );
        game.window.draw( game.compPaddle );
        game.window.draw( game.ball );

        // Switch back buffer to the front buffer
        game.window.display();
    }

    return 0;
}