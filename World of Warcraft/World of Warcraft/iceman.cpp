/*********************************************************************************

  * FileName:       iceman.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Iceman
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "iceman.h"


int Iceman::iceman_strength_ = 0;
int Iceman::iceman_attack_ = 0;


Iceman::Iceman(int n): Warrior(n)
{
	strength_ = iceman_strength_;
	attack_ = iceman_attack_;

	if (number_ % 3 == 0 && static_cast<int>(iceman_attack_ * 0.2) == 0)
		sword_ = nullptr;
	else
	{
		switch (number_ % 3)
		{
			case 0: sword_ = new Sword(static_cast<int>(iceman_attack_ * 0.2)); break;
			case 1: bomb_ = new Bomb(); break;
			case 2: arrow_ = new Arrow(); break;
		}
	}

	march_record_ = 0;
}


int Iceman::GetIcemanStrength()
{
	return iceman_strength_;
}


void Iceman::SetIcemanStrength(int iceman_strength)
{
	iceman_strength_ = iceman_strength;
}


void Iceman::SetIcemanAttack(int iceman_attack)
{
	iceman_attack_ = iceman_attack;
}


void Iceman::IcemanSpecialGift()
{
	march_record_++;

	if (march_record_ == 2)
	{
		strength_ = (strength_ - 9 <= 0) ? 1 : strength_ - 9;
		attack_ += 20;
		march_record_ = 0;
	}
}


