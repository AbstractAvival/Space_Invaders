#pragma once

class GameState
{
protected:
	GameState() {};

public:
	virtual void InitializeState() = 0;
	virtual void ResetState() = 0;
	virtual void Enter() = 0;

	virtual void UpdateLogic() = 0;
	virtual void Render() = 0;

protected:
	bool isInitialized = false;
	int stateWidth;
	int stateHeight;
};