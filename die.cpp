#include "die.h"
#include <random>
#include <iostream>
#include <string>

Die::Die(int iStartingNumberOfSides, int iStartingIncrement, int iBeginningValue)
{
    m_iNumberOfSides = iStartingNumberOfSides;
    m_iIncrement = iStartingIncrement;
    m_iStartingValue = iBeginningValue;
}
int Die::roll()
{
    // Generate Random Numbers between 1 and 6
    m_iStartingValue = (rand() % 6) + 1;
    return m_iStartingValue;
}
void Die::setNumberOfSides(int newNumberOfSides)
{
    m_iNumberOfSides = newNumberOfSides;
}
int Die::getNumberOfSides() {
    return m_iNumberOfSides;
}
void Die::setIncrement(int iNewIncrement)
{
    m_iIncrement = iNewIncrement;
}
int Die::getIncrement()
{
    return m_iIncrement;
}

void Die::setStartingValue(int newStartingValue)
{
    m_iStartingValue = newStartingValue;
}
int Die::getStartingValue()
{
    return m_iStartingValue;
}

void Die::setValue(int newValue)
{
    m_iValue = newValue;
}
int Die::getValue()
{
    return m_iValue;
}