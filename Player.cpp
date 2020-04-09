#include "Player.h"
#include <iostream>

Player::Player(float iBet = 0, float iStartingScore = 1000)
{
	iBet = iBet;
	iScore = iStartingScore;
}
void Player::setBet(int iBet)
{
	iBet = iBet;
}

float Player::getBet()
{
	return iBet;
}
void Player::addScore(int userScore)
{
	iScore += userScore;
}
void Player::subtractScore()
{
	iScore -= iBet;
}
float Player::getCurrentScore()
{
	return iScore;
}
void Player::addGameWon()
{
	fWins++;
}
float Player::getCurrentWins()
{
	return fWins;
}
void Player::addGameLoss()
{
	fLosses++;
}
float Player::getCurrentLosses()
{
	return fLosses;

}
bool Player::playAgain(std::string sPlayAgain)
{
	if (sPlayAgain == "yes")
	{
		return true;
	}
	else
	{
		return false;
	}
}
