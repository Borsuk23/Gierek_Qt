#include "pch.h"
#include "Game.h"


Game::Game()
{
}

Game::Game(int difficulty, int lenght)
{
	this->data = 0;
	this->gameID = 1;
	this->gameDifficulty = difficulty;
	this->gameLenght = lenght;
	this->numberOfMines = difficulty * 10;
}

