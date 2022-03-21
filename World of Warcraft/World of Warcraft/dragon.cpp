/*********************************************************************************

  * FileName:       dragon.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Dragon
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "dragon.h"


int Dragon::dragon_strength_ = 0;
int Dragon::dragon_attack_ = 0;


Dragon::Dragon(int n, double m): Warrior(n), morale_(m)
{
	strength_ = dragon_strength_;
	attack_ = dragon_attack_;

	if (number_ % 3 == 0 && static_cast<int>(dragon_attack_ * 0.2) == 0)
		sword_ = nullptr;
	else
	{
		switch (number_ % 3)
		{
			case 0: sword_ = new Sword(static_cast<int>(dragon_attack_ * 0.2)); break;
			case 1: bomb_ = new Bomb(); break;
			case 2: arrow_ = new Arrow(); break;
		}
	}
}


int Dragon::GetDragonStrength()
{
	return dragon_strength_;
}


void Dragon::SetDragonStrength(int dragon_strength)
{
	dragon_strength_ = dragon_strength;
}


void Dragon::SetDragonAttack(int dragon_attack)
{
	dragon_attack_ = dragon_attack;
}


double Dragon::GetMorale() const
{
	return morale_;
}


void Dragon::ChangeMorale(const std::string& win)
{
	morale_ += (win == "win") ? 0.2 : -0.2;
}


std::string Dragon::Yell() const
{
	return "dragon " + std::to_string(number_) + " yelled ";
}


