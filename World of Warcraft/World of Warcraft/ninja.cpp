/*********************************************************************************

  * FileName:       ninja.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Ninja
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "ninja.h"


int Ninja::ninja_strength_ = 0;
int Ninja::ninja_attack_ = 0;


Ninja::Ninja(int n): Warrior(n)
{
	strength_ = ninja_strength_;
	attack_ = ninja_attack_;

	if (number_ % 3 == 0 && static_cast<int>(ninja_attack_ * 0.2) == 0)
		sword_ = nullptr;
	else
	{
		switch (number_ % 3)
		{
			case 0: sword_ = new Sword(static_cast<int>(ninja_attack_ * 0.2)); break;
			case 1: bomb_ = new Bomb(); break;
			case 2: arrow_ = new Arrow(); break;
		}
	}

	if ((number_ + 1) % 3 == 0 && static_cast<int>(ninja_attack_ * 0.2) == 0)
		sword_ = nullptr;
	else
	{
		switch ((number_ + 1) % 3)
		{
			case 0: sword_ = new Sword(static_cast<int>(ninja_attack_ * 0.2)); break;
			case 1: bomb_ = new Bomb(); break;
			case 2: arrow_ = new Arrow(); break;
		}
	}
}


int Ninja::GetNinjaStrength()
{
	return ninja_strength_;
}


void Ninja::SetNinjaStrength(int ninja_strength)
{
	ninja_strength_ = ninja_strength;
}


void Ninja::SetNinjaAttack(int ninja_attack)
{
	ninja_attack_ = ninja_attack;
}


