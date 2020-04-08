#pragma once
#ifndef CRAPS_DIE_H
#define CRAPS_DIE_H
#include <iostream>
#include <string>

class Die
{
private:
	int m_iNumberOfSides;
	int m_iIncrement;
	int m_iStartingValue;
	int m_iValue;
	
public:
	Die(int startingNumberOfSides, int startingIncrement, int beginningValue);
	int roll();
	void setNumberOfSides(int newNumberOfSides);
	int getNumberOfSides();
	void setIncrement(int newIncrement);
	int getIncrement();

	void setStartingValue(int newStartingValue);
	int getStartingValue();

	void setValue(int newValue);
	int getValue();
};

#endif //CRAPS_DIE_H