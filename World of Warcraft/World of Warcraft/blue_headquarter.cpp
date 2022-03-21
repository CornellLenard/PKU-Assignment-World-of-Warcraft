/*********************************************************************************

  * FileName:       blue_headquarter.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class BlueHeadquarter
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "blue_headquarter.h"


BlueHeadquarter::BlueHeadquarter(int s, int data[]): Headquarter(s)
{
	warrior_creation_guide_type_[0] = "lion"; warrior_creation_guide_strength_[0] = data[3];
	warrior_creation_guide_type_[1] = "dragon"; warrior_creation_guide_strength_[1] = data[0];
	warrior_creation_guide_type_[2] = "ninja"; warrior_creation_guide_strength_[2] = data[1];
	warrior_creation_guide_type_[3] = "iceman"; warrior_creation_guide_strength_[3] = data[2];
	warrior_creation_guide_type_[4] = "wolf"; warrior_creation_guide_strength_[4] = data[4];
}


BlueHeadquarter::~BlueHeadquarter()
{
}


std::pair<int, std::string> BlueHeadquarter::CreateWarrior(const std::string& clock)
{
	// If res.first is 0, then it indicates the creation is failed
	std::pair<int, std::string> res = std::make_pair(0, "0");

	// Judges whether the headquarter can create a warrior
	if (strength_ >= warrior_creation_guide_strength_[creation_clock_])
	{
		std::cout << clock << " blue " << warrior_creation_guide_type_[creation_clock_];

		switch (creation_clock_)
		{
			case 0: lions_.insert(std::make_pair(number_record_ + 1, new Lion(number_record_ + 1, strength_ - Lion::GetLionStrength()))); break;
			case 1: dragons_.insert(std::make_pair(number_record_ + 1, new Dragon(number_record_ + 1,
				(strength_ - Dragon::GetDragonStrength()) / (double)(Dragon::GetDragonStrength())))); break;
			case 2: ninjas_.insert(std::make_pair(number_record_ + 1, new Ninja(number_record_ + 1))); break;
			case 3: icemans_.insert(std::make_pair(number_record_ + 1, new Iceman(number_record_ + 1))); break;
			case 4: wolfs_.insert(std::make_pair(number_record_ + 1, new Wolf(number_record_ + 1))); break;
		}

		res.first = number_record_ + 1;
		res.second = warrior_creation_guide_type_[creation_clock_];
		number_record_++;
		std::cout << ' ' << number_record_ << " born\n";

		// If the warrior type is dragon, then it needs to output morale
		if (warrior_creation_guide_type_[creation_clock_] == "dragon")
			std::cout << "Its morale is " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << dragons_[number_record_]->GetMorale() << std::resetiosflags(std::ios::fixed) << '\n';
		// If the warrior type is lion, the it needs to output loyalty
		else if (warrior_creation_guide_type_[creation_clock_] == "lion")
			std::cout << "Its loyalty is " << lions_[number_record_]->GetLoyalty() << '\n';

		strength_ -= warrior_creation_guide_strength_[creation_clock_];
		creation_clock_ = (creation_clock_ + 1) % 5;
	}
	return res;
}


