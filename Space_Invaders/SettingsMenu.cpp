#include "SettingsMenu.h"
#include "StateHandler.h"

SettingsMenu::SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight )
	:
	SettingsMenu( textureCodex, audioManagerIn, items, screenWidth, screenHeight, 0, 0 )
{}

SettingsMenu::SettingsMenu( TextureCodex& textureCodex, AudioManager& audioManagerIn, std::vector< std::string > items, float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
	:
	audioManager( &audioManagerIn )
{
	InitializeMenuItems( textureCodex, items );
	SetMenuItemPositions( screenWidth, screenHeight, xDisplacement, yDisplacement );
}

void SettingsMenu::HandleInput( StateHandler& handler )
{
	Menu::HandleInput( *audioManager );
	if( accumulatedFrameTime >= maxInputCooldown && currentItem == 0 && sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		accumulatedFrameTime = 0;
		ModifyVolume( -5.0f );
	}

	if( accumulatedFrameTime >= maxInputCooldown && currentItem == 0 && sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		accumulatedFrameTime = 0;
		ModifyVolume( 5.0f );
	}

	if( accumulatedFrameTime >= maxInputCooldown && currentItem == 1 && sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
	{
		handler.ChangeState( StateTypes::MAINMENUSTATE );
	}
}

void SettingsMenu::InitializeMenuItems( TextureCodex& textureCodex, std::vector< std::string > desiredItems )
{
	Menu::InitializeMenuItems( textureCodex, desiredItems );
	options.emplace_back( sf::Text() );
	options[ 0 ].setFont( textureCodex.GetFont() );
	options[ 0 ].setCharacterSize( 25 );
	options[ 0 ].setString( std::to_string( audioManager->GetCurrentVolume() ) );
}

void SettingsMenu::SetMenuItemPositions( float screenWidth, float screenHeight, float xDisplacement, float yDisplacement )
{
	float startingHeight = ( screenHeight / 2 ) - ( yDisplacement + items.size() * ( estimatedCharacterHeight + verticalSeparationDistance ) / 2 );
	float xPosition = ( screenWidth / 2 - float( items[ 0 ].getCharacterSize() ) ) - ( xDisplacement + horizontalSeparationDistance / 2 );
	items[ 0 ].setPosition( { xPosition, startingHeight } );
	options[ 0 ].setPosition( { xPosition + horizontalSeparationDistance / 2, startingHeight } );
	items[ 1 ].setPosition( { ( screenWidth / 2 - float( items[ 1 ].getCharacterSize() / 2 ) ), startingHeight + ( estimatedCharacterHeight + verticalSeparationDistance ) } );
}

void SettingsMenu::ModifyVolume( float volumeOffset )
{
	audioManager->ModifyVolume( volumeOffset );
	options[ 0 ].setString( std::to_string( audioManager->GetCurrentVolume() ) );
}