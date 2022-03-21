/*********************************************************************************

  * FileName:       sword.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Sword
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "sword.h"


Sword::Sword(int a): attack_(a)
{
}


Sword::Sword(const Sword& s): attack_(s.attack_)
{
}


int Sword::GetAttack() const
{
	return attack_;
}


int Sword::UseSword()
{
	int res = attack_;
	attack_ *= 0.8;
	return res;
}


