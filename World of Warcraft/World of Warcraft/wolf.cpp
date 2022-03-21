/*********************************************************************************

  * FileName:       wolf.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Wolf
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "wolf.h"


int Wolf::wolf_strength_ = 0;
int Wolf::wolf_attack_ = 0;


Wolf::Wolf(int n): Warrior(n)
{
	strength_ = wolf_strength_;
	attack_ = wolf_attack_;
}


int Wolf::GetWolfStrength()
{
	return wolf_strength_;
}


void Wolf::SetWolfStrength(int wolf_strength)
{
	wolf_strength_ = wolf_strength;
}


void Wolf::SetWolfAttack(int wolf_attack)
{
	wolf_attack_ = wolf_attack;
}


void Wolf::TakeWeapon(Sword* sword, Bomb* bomb, Arrow* arrow)
{
	if (sword != nullptr && sword_ == nullptr)
		sword_ = new Sword(*sword);
	if (bomb != nullptr && bomb_ == nullptr)
		bomb_ = new Bomb();
	if (arrow != nullptr && arrow_ == nullptr)
		arrow_ = new Arrow(*arrow);
}


