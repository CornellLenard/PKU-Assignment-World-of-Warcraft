/*********************************************************************************

  * FileName:       world_of_warcraft.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class WorldOfWarcraft
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "red_headquarter.h"
#include "blue_headquarter.h"
#include "city.h"


class WorldOfWarcraft
{
private:
	// The clock
	std::string clock_;
	// Points to the red headquarter
	RedHeadquarter* rhq_;
	// Points to the blue headquarter
	BlueHeadquarter* bhq_;
	// The number of cities that are between the 2 headquarters
	int city_num_;
	// Points to the cities
	City* cities_;
	// When ends the simulation
	int end_clock_;
	// How many blue warriors have entered red headquarter
	int red_headquarter_enemy_;
	// The number of blue warriors entering red headquarter
	int red_headquarter_enemy_num_[2];
	// The type of blue warriors entering red headquarter
	std::string red_headquarter_enemy_type_[2];
	// How many red warriors have entered blue headquarter
	int blue_headquarter_enemy_;
	// The number of red warriors entering blue headquarter
	int blue_headquarter_enemy_num_[2];
	// The type of red warriors entering blue headquarter
	std::string blue_headquarter_enemy_type_[2];
	// Whether the game is over
	bool game_over_;
	// The information list that is to be displayed for WarriorsFightWars()
	std::string* info_list_;
	// The size of info_list
	int info_size_;

	/*
	* The clock goes on a unit
	*/
	void ClockGoNext();

	/*
	* Headquarters create warriors
	*/
	void CreateWarrior();

	/*
	* Lions escape
	*/
	void LionsEscape();

	/*
	* Warriors march forward
	*/
	void WarriorsMarchForward();

	/*
	* Cities produce strength
	*/
	void CitiesProduceStrength();

	/*
	* Warriors take strength from cities
	*/
	void WarriorsTakeStrength();

	/*
	* Warriors shoot arrows
	*/
	void WarriorsShootArrows();

	/*
	* Warriors use bomb
	*/
	void WarriorsUseBombs();

	/*
	* Warriors fight wars
	*/
	void WarriorsFightWars();

	/*
	* Headquarters report strength
	*/
	void HeadquartersReportStrength();

	/*
	* Warriors report weapons
	*/
	void WarriorsReportWeapons();

public:
	WorldOfWarcraft(int s, int cn, int aa, int ld, int ec, int data[]);
	~WorldOfWarcraft();

	/*
	* Runs World of Warcraft
	*/
	void Run();
};


