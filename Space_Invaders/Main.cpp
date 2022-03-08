#include <chrono>
using namespace std;

int main()
{
	const float framesPerSecond = 25.0f;
	const float msPerFrame = 1.0f / framesPerSecond;
	float interpolation;

	chrono::steady_clock::time_point previousFrameTime = chrono::steady_clock::now();
	float frameLagTime = 0.0f;

	while( true )
	{
		chrono::steady_clock::time_point currentFrameTime = chrono::steady_clock::now();
		chrono::duration< float > elapsedFrameTime = currentFrameTime - previousFrameTime;
		previousFrameTime = currentFrameTime;
		frameLagTime += elapsedFrameTime.count();

		while( frameLagTime >= msPerFrame )
		{
			frameLagTime -= msPerFrame;
		}

		interpolation = frameLagTime / msPerFrame;
	}

	return 0;
}