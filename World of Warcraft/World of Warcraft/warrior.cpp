/*********************************************************************************

  * FileName:       warrior.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Warrior
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "warrior.h"


Warrior::Warrior(int n): number_(n)
{
	strength_ = 0;
	attack_ = 0;
	sword_ = nullptr;
	bomb_ = nullptr;
	arrow_ = nullptr;
}


Warrior::~Warrior()
{
	if (sword_ != nullptr)
	{
		delete sword_;
		sword_ = nullptr;
	}
	if (bomb_ != nullptr)
	{
		delete bomb_;
		bomb_ = nullptr;
	}
	if (arrow_ != nullptr)
	{
		delete arrow_;
		arrow_ = nullptr;
	}
}


int Warrior::GetNumber() const
{
	return number_;
}


int Warrior::GetStrength() const
{
	return strength_;
}


int Warrior::GetAttack() const
{
	return attack_;
}


bool Warrior::HasSword() const
{
	return sword_ != nullptr;
}


bool Warrior::HasBomb() const
{
	return bomb_ != nullptr;
}


bool Warrior::HasArrow() const
{
	return arrow_ != nullptr;
}


Sword* Warrior::GetSword() const
{
	return sword_;
}


Bomb* Warrior::GetBomb() const
{
	return bomb_;
}


Arrow* Warrior::GetArrow() const
{
	return arrow_;
}


void Warrior::BeAttacked(int damage)
{
	strength_ = (strength_ - damage <= 0) ? 0 : strength_ - damage;
}


void Warrior::ReceiveStrength(int strength)
{
	strength_ += strength;
}


int Warrior::UseSword()
{
	int res = sword_->UseSword();
	if (sword_->GetAttack() == 0)
	{
		delete sword_;
		sword_ = nullptr;
	}
	return res;
}


void Warrior::UseBomb()
{
	delete bomb_;
	bomb_ = nullptr;
}


int Warrior::UseArrow()
{
	int res = arrow_->UseArrow();
	if (arrow_->GetCapacity() == 0)
	{
		delete arrow_;
		arrow_ = nullptr;
	}
	return res;
}


void Warrior::ReportWeapons() const
{
	if (arrow_ == nullptr && bomb_ == nullptr && sword_ == nullptr)
		std::cout << "has no weapon";
	else
	{
		std::cout << "has ";
		if (arrow_ != nullptr)
			std::cout << "arrow(" << arrow_->GetCapacity() << ')';
		if (bomb_ != nullptr)
			std::cout << (arrow_ == nullptr ? "bomb" : ",bomb");
		if (sword_ != nullptr)
			std::cout << ((arrow_ == nullptr && bomb_ == nullptr) ? "sword(" : ",sword(") << sword_->GetAttack() << ')';
	}
}


