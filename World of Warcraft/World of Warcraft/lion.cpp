/*********************************************************************************

  * FileName:       lion.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Lion
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "lion.h"


int Lion::lion_strength_ = 0;
int Lion::lion_attack_ = 0;
int Lion::loyalty_decrease_ = 0;


Lion::Lion(int n, int l): Warrior(n), loyalty_(l)
{
	strength_ = lion_strength_;
	attack_ = lion_attack_;
}


int Lion::GetLionStrength()
{
	return lion_strength_;
}


void Lion::SetLionStrength(int lion_strength)
{
	lion_strength_ = lion_strength;
}


void Lion::SetLionAttack(int lion_attack)
{
	lion_attack_ = lion_attack;
}


void Lion::SetLionLoyaltyDecrease(int loyalty_decrease)
{
	loyalty_decrease_ = loyalty_decrease;
}


int Lion::GetLoyalty() const
{
	return loyalty_;
}


void Lion::ChangeLoyalty(const std::string& win)
{
	if (win != "win")
		loyalty_ -= loyalty_decrease_;
}


