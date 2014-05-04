#pragma once
#include "Market.h"
#include "AI.h"
class Game
{
public:
	int data;
	int gameID;
	int gameDifficulty;
	int gameLenght;
	int numberOfMines;
	Market *market;
	std::vector<AI> mines;
public:
	Game();
	Game(int difficulty, int lenght);
	void PlayTurn();
	void EndGame();

};

