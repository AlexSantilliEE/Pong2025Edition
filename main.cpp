#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

int main()
{

    // Start the game, create gameclock, open the window
    Game game;

    sf::VertexArray triangle( sf::Triangles, 3 );
    triangle[0] = sf::Vector2f( 50.0f, 50.0f );
    triangle[1] = sf::Vector2f( 500.0f, 50.0f );
    triangle[2] = sf::Vector2f( 500.0f, 250.0f );
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Green;
    triangle[2].color = sf::Color::Blue;

    while ( game.window.isOpen() )
    {
        // Poll events & react to events that occured in the window
        sf::Event event;
        while ( game.window.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
                game.window.close();
        }

        sf::Time elapsed = game.clock.restart();

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