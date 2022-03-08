#include "Game.h"

Game::Game( int screenWidth, int screenHeight, string windowName, string fontFileName )
{
    Initialize( screenWidth, screenHeight, windowName );
}

Game::~Game()
{
    CleanUp();
}

void Game::Initialize(int screenWidth, int screenHeight, string windowName)
{
    SetupWindow( screenWidth, screenHeight, windowName );
    isRunning = true;
}

void Game::SetupWindow(int screenWidth, int screenHeight, string windowName)
{
    window = new sf::RenderWindow( sf::VideoMode( screenWidth, screenHeight ), windowName );
    window->setFramerateLimit( frameRateLimit );
}

void Game::CleanUp()
{
    isRunning = false;

    window->close();
    delete window;
    window = nullptr;
}

void Game::HandleEvents()
{
    sf::Event event;
    while( window->pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed )
            Quit();

        if( event.type == sf::Event::Resized )
        {
            sf::FloatRect visibleArea( 0, 0, event.size.width, event.size.height );
            window->setView( sf::View( visibleArea ) );
        }
    }
}

void Game::UpdateLogic()
{
    HandleEvents();
}

void Game::Draw()
{
    window->clear();
    window->display();
}

bool Game::Running()
{
    return isRunning;
}

void Game::Quit()
{
    isRunning = false;
}