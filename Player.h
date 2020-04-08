#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
	float iBet;
	float iScore;
	float fWins = 0, fLosses = 0;

public:
	Player(float iBet, float iStartingScore);
	bool setBet(int iBet);
	float getBet();
	void addScore(int userScore);
	void subtractScore();
	float getCurrentScore();
	void addGameWon();
	float getCurrentWins();
	void addGameLoss();
	float getCurrentLosses();
	bool playAgain(std::string sPlayAgain);
};

#endif //CRAPS_PLAYER_H
