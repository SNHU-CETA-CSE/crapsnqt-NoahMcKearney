#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
	int iBet;
	float iScore = 0;
	float fWins = 0, fLosses = 0;

public:
	Player(float iStartingScore);
	void setBet(float startingBet);
	float getBet();
	void addScore(float userScore);
	void subtractScore();
	float getCurrentScore();
	void addGameWon();
	float getCurrentWins();
	void addGameLoss();
	float getCurrentLosses();
};

#endif //CRAPS_PLAYER_H
