/*********************************************************************************

  * FileName:       headquarter.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Headquarter
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "headquarter.h"


Headquarter::Headquarter(int s): strength_(s)
{
	creation_clock_ = 0;
	number_record_ = 0;

	for (int i = 0; i < 5; i++)
		warrior_creation_guide_type_[i] = "";

	for (int i = 0; i < 5; i++)
		warrior_creation_guide_strength_[i] = 0;
}


Headquarter::~Headquarter()
{
	for (std::map<int, Dragon*>::iterator p = dragons_.begin(); p != dragons_.end(); p++)
		delete p->second;
	dragons_.clear();

	for (std::map<int, Ninja*>::iterator p = ninjas_.begin(); p != ninjas_.end(); p++)
		delete p->second;
	ninjas_.clear();

	for (std::map<int, Iceman*>::iterator p = icemans_.begin(); p != icemans_.end(); p++)
		delete p->second;
	icemans_.clear();

	for (std::map<int, Lion*>::iterator p = lions_.begin(); p != lions_.end(); p++)
		delete p->second;
	lions_.clear();

	for (std::map<int, Wolf*>::iterator p = wolfs_.begin(); p != wolfs_.end(); p++)
		delete p->second;
	wolfs_.clear();
}


int Headquarter::GetStrength() const
{
	return strength_;
}


void Headquarter::TakeStrength(int strength)
{
	strength_ += strength;
}


int Headquarter::ReportStrength() const
{
	return strength_;
}


int Headquarter::AwardStrength()
{
	strength_ -= 8;
	return 8;
}


Warrior* Headquarter::GetWarrior(int num, const std::string& type)
{
	switch (type[0])
	{
		case 'd': return dragons_[num];
		case 'n': return ninjas_[num];
		case 'i': return icemans_[num];
		case 'l': return lions_[num];
		case 'w': return wolfs_[num];
	}
}


void Headquarter::RemoveWarrior(int num, std::string type)
{
	switch (type[0])
	{
		case 'd': delete dragons_[num]; dragons_[num] = nullptr; dragons_.erase(num); break;
		case 'n': delete ninjas_[num]; ninjas_[num] = nullptr; ninjas_.erase(num); break;
		case 'i': delete icemans_[num]; icemans_[num] = nullptr; icemans_.erase(num); break;
		case 'l': delete lions_[num]; lions_[num] = nullptr; lions_.erase(num); break;
		case 'w': delete wolfs_[num]; wolfs_[num] = nullptr; wolfs_.erase(num); break;
	}
}


