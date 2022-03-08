#include "Game.h"

Game::Game( string windowName, string fontFileName, int screenWidth, int screenHeight )
{
    Initialize( windowName, screenWidth, screenHeight );
    stateHandler = new StateHandler( *window, screenWidth, screenHeight );
}

Game::~Game()
{
    CleanUp();
}

void Game::Initialize( string windowName, int screenWidth, int screenHeight )
{
    SetupWindow( windowName, screenWidth, screenHeight );
    isRunning = true;
}

void Game::SetupWindow( string windowName, int screenWidth, int screenHeight )
{
    window = new sf::RenderWindow( sf::VideoMode( screenWidth, screenHeight ), windowName );
    window->setFramerateLimit( frameRateLimit );
}

void Game::CleanUp()
{
    isRunning = false;

    delete stateHandler;
    stateHandler = nullptr;

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
            sf::FloatRect visibleArea( 0.0f, 0.0f, ( float )event.size.width, ( float )event.size.height );
            window->setView( sf::View( visibleArea ) );
        }
    }
    stateHandler->GetCurrentState().HandleInput();
}

void Game::UpdateLogic()
{
    HandleEvents();
    stateHandler->GetCurrentState().UpdateLogic();
}

void Game::Draw( float interpolation )
{
    window->clear();
    stateHandler->GetCurrentState().Render( interpolation );
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