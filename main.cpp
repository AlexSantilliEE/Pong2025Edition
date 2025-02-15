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
    triangle[0] = sf::Vector2f( 50.0f, 50.0f );
    triangle[0] = sf::Vector2f( 50.0f, 50.0f );

    while ( game.isOpen() )
    {
        // Poll events & react to events that occured in the window
        sf::Event event;
        while ( game.pollEvent( event ) )
        {
            if ( event.type == sf::Event::Closed )
                game.close();
        }

        sf::Time elapsed = game.restart();

        // Clear the back buffer
        game.clear();

        // Draw stuff:

        // Switch back buffer to the front buffer
        game.display();
    }

    return 0;
}