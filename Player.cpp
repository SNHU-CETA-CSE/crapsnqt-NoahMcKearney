#include "Player.h"
#include <iostream>

Player::Player(float iStartingScore)
{
	iScore = iStartingScore;
}
void Player::setBet(float startingBet)
{
	iBet = startingBet;
}

float Player::getBet()
{
	return iBet;
}
void Player::addScore(float userScore)
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

