#include <chrono>
#include "Game.h"

int main()
{
	const float framesPerSecond = 25.0f;
	const float msPerFrame = 1.0f / framesPerSecond;
	float interpolation;

	std::chrono::steady_clock::time_point previousFrameTime = std::chrono::steady_clock::now();
	float frameLagTime = 0.0f;

	Game game( "Space Invaders", "", 800, 600 );

	while( game.Running() )
	{
		std::chrono::steady_clock::time_point currentFrameTime = std::chrono::steady_clock::now();
		std::chrono::duration< float > elapsedFrameTime = currentFrameTime - previousFrameTime;
		previousFrameTime = currentFrameTime;
		frameLagTime += elapsedFrameTime.count();

		while( frameLagTime >= msPerFrame )
		{
			frameLagTime -= msPerFrame;
			game.UpdateLogic( elapsedFrameTime.count() );
		}

		interpolation = frameLagTime / msPerFrame;
		game.Draw( interpolation );
	}

	return 0;
}