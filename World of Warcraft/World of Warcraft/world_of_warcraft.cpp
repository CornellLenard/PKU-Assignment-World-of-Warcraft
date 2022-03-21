/*********************************************************************************

  * FileName:       world_of_warcraft.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class WorldOfWarcraft
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "world_of_warcraft.h"


void WorldOfWarcraft::ClockGoNext()
{
	int digit_add = clock_[5] - '0' + 1;
	clock_[5] = (digit_add == 10) ? '0' : digit_add + '0';

	if (digit_add == 10)
	{
		digit_add = clock_[4] - '0' + 1;
		clock_[4] = (digit_add == 6) ? '0' : digit_add + '0';

		if (digit_add == 6)
		{
			digit_add = clock_[2] - '0' + 1;
			clock_[2] = (digit_add == 10) ? '0' : digit_add + '0';

			if (digit_add == 10)
			{
				digit_add = clock_[1] - '0' + 1;
				clock_[1] = (digit_add == 10) ? '0' : digit_add + '0';
				if (digit_add == 10)
					clock_[0]++;
			}
		}
	}
}


void WorldOfWarcraft::CreateWarrior()
{
	std::pair<int, std::string> red = rhq_->CreateWarrior(clock_);
	std::pair<int, std::string> blue = bhq_->CreateWarrior(clock_);

	if (red.second != "0")
		cities_[0].AddWarrior(red.first, "red", red.second);

	if (blue.second != "0")
		cities_[city_num_ + 1].AddWarrior(blue.first, "blue", blue.second);
}


void WorldOfWarcraft::LionsEscape()
{
	Warrior* warrior = nullptr;
	Lion* lion = nullptr;

	for (int i = 0; i < city_num_ + 2; i++)
	{
		if (i < city_num_ + 1)
		{
			if (cities_[i].GetWarriorNumber("red") != 0 && cities_[i].GetWarriorType("red") == "lion")
			{
				warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), "lion");
				lion = static_cast<Lion*>(warrior);
				if (lion->GetLoyalty() <= 0)
				{
					std::cout << clock_ << " red lion " << cities_[i].GetWarriorNumber("red") << " ran away\n";
					rhq_->RemoveWarrior(cities_[i].GetWarriorNumber("red"), "lion");
					cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("red"), "red");
				}
			}
		}
		if (i >= 1)
		{
			if (cities_[i].GetWarriorNumber("blue") != 0 && cities_[i].GetWarriorType("blue") == "lion")
			{
				warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), "lion");
				lion = static_cast<Lion*>(warrior);
				if (lion->GetLoyalty() <= 0)
				{
					std::cout << clock_ << " blue lion " << cities_[i].GetWarriorNumber("blue") << " ran away\n";
					bhq_->RemoveWarrior(cities_[i].GetWarriorNumber("blue"), "lion");
					cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("blue"), "blue");
				}
			}
		}
	}
	warrior = nullptr;
	lion = nullptr;
}


void WorldOfWarcraft::WarriorsMarchForward()
{
	Warrior* warrior = nullptr;
	for (int i = 0; i < city_num_ + 2; i++)
	{
		if (i == 0)
		{
			if (cities_[1].GetWarriorNumber("blue") != 0)
			{
				warrior = bhq_->GetWarrior(cities_[1].GetWarriorNumber("blue"), cities_[1].GetWarriorType("blue"));

				if (cities_[1].GetWarriorType("blue") == "iceman")
				{
					Iceman* iceman = static_cast<Iceman*>(warrior);
					iceman->IcemanSpecialGift();
				}

				std::cout << clock_ << " blue " << cities_[1].GetWarriorType("blue") << ' ' << warrior->GetNumber() << " reached red headquarter with ";
				std::cout << warrior->GetStrength() << " elements and force " << warrior->GetAttack() << '\n';

				red_headquarter_enemy_num_[red_headquarter_enemy_] = warrior->GetNumber();
				red_headquarter_enemy_type_[red_headquarter_enemy_] = cities_[1].GetWarriorType("blue");
				red_headquarter_enemy_++;

				if (red_headquarter_enemy_ >= 2)
				{
					std::cout << clock_ << " red headquarter was taken\n";
					game_over_ = true;
				}
			}
		}
		else if (i == city_num_ + 1)
		{
			if (cities_[city_num_].GetWarriorNumber("red") != 0)
			{
				warrior = rhq_->GetWarrior(cities_[city_num_].GetWarriorNumber("red"), cities_[city_num_].GetWarriorType("red"));

				if (cities_[city_num_].GetWarriorType("red") == "iceman")
				{
					Iceman* iceman = static_cast<Iceman*>(warrior);
					iceman->IcemanSpecialGift();
				}

				std::cout << clock_ << " red " << cities_[city_num_].GetWarriorType("red") << ' ' << warrior->GetNumber() << " reached blue headquarter with ";
				std::cout << warrior->GetStrength() << " elements and force " << warrior->GetAttack() << '\n';
				blue_headquarter_enemy_num_[blue_headquarter_enemy_] = warrior->GetNumber();
				blue_headquarter_enemy_type_[blue_headquarter_enemy_] = cities_[city_num_].GetWarriorType("red");
				blue_headquarter_enemy_++;

				if (blue_headquarter_enemy_ >= 2)
				{
					std::cout << clock_ << " blue headquarter was taken\n";
					game_over_ = true;
				}
			}
		}
		else
		{
			if (cities_[i - 1].GetWarriorNumber("red") != 0)
			{
				warrior = rhq_->GetWarrior(cities_[i - 1].GetWarriorNumber("red"), cities_[i - 1].GetWarriorType("red"));

				if (cities_[i - 1].GetWarriorType("red") == "iceman")
				{
					Iceman* iceman = static_cast<Iceman*>(warrior);
					iceman->IcemanSpecialGift();
				}

				std::cout << clock_ << " red " << cities_[i - 1].GetWarriorType("red") << ' ' << warrior->GetNumber() << " marched to city " << i << " with ";
				std::cout << warrior->GetStrength() << " elements and force " << warrior->GetAttack() << '\n';
			}
			if (cities_[i + 1].GetWarriorNumber("blue") != 0)
			{
				warrior = bhq_->GetWarrior(cities_[i + 1].GetWarriorNumber("blue"), cities_[i + 1].GetWarriorType("blue"));

				if (cities_[i + 1].GetWarriorType("blue") == "iceman")
				{
					Iceman* iceman = static_cast<Iceman*>(warrior);
					iceman->IcemanSpecialGift();
				}

				std::cout << clock_ << " blue " << cities_[i + 1].GetWarriorType("blue") << ' ' << warrior->GetNumber() << " marched to city " << i << " with ";
				std::cout << warrior->GetStrength() << " elements and force " << warrior->GetAttack() << '\n';
			}
		}
	}

	for (int i = city_num_; i >= 0; i--)
	{
		cities_[i + 1].SetWarriorNumber(cities_[i].GetWarriorNumber("red"), "red");
		cities_[i + 1].SetWarriorType(cities_[i].GetWarriorType("red"), "red");
	}

	cities_[0].SetWarriorNumber(0, "red");
	cities_[0].SetWarriorType("none", "red");

	for (int i = 1; i < city_num_ + 2; i++)
	{
		cities_[i - 1].SetWarriorNumber(cities_[i].GetWarriorNumber("blue"), "blue");
		cities_[i - 1].SetWarriorType(cities_[i].GetWarriorType("blue"), "blue");
	}

	cities_[city_num_ + 1].SetWarriorNumber(0, "blue");
	cities_[city_num_ + 1].SetWarriorType("none", "blue");
	warrior = nullptr;
}


void WorldOfWarcraft::CitiesProduceStrength()
{
	for (int i = 1; i < city_num_ + 1; i++)
		cities_[i].ProduceStrength();
}


void WorldOfWarcraft::WarriorsTakeStrength()
{
	for (int i = 1; i < city_num_ + 1; i++)
	{
		if (cities_[i].GetWarriorNumber("red") == 0 && cities_[i].GetWarriorNumber("blue") != 0)
		{
			std::cout << clock_ << " blue " << cities_[i].GetWarriorType("blue") << ' ' << cities_[i].GetWarriorNumber("blue");
			std::cout << " earned " << cities_[i].GetStrength() << " elements for his headquarter\n";
			bhq_->TakeStrength(cities_[i].BeTakenStrength());
		}
		else if (cities_[i].GetWarriorNumber("blue") == 0 && cities_[i].GetWarriorNumber("red") != 0)
		{
			std::cout << clock_ << " red " << cities_[i].GetWarriorType("red") << ' ' << cities_[i].GetWarriorNumber("red");
			std::cout << " earned " << cities_[i].GetStrength() << " elements for his headquarter\n";
			rhq_->TakeStrength(cities_[i].BeTakenStrength());
		}
		else
			continue;
	}
}


void WorldOfWarcraft::WarriorsShootArrows()
{
	Warrior* red_warrior = nullptr;
	Warrior* blue_warrior = nullptr;

	for (int i = 0; i < city_num_ + 1; i++)
	{
		if (i < city_num_)
		{
			if (cities_[i].GetWarriorNumber("red") != 0 && cities_[i + 1].GetWarriorNumber("blue") != 0)
			{
				red_warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
				blue_warrior = bhq_->GetWarrior(cities_[i + 1].GetWarriorNumber("blue"), cities_[i + 1].GetWarriorType("blue"));

				if (red_warrior->HasArrow() == true)
				{
					blue_warrior->BeAttacked(red_warrior->UseArrow());
					std::cout << clock_ << " red " << cities_[i].GetWarriorType("red") << ' ' << red_warrior->GetNumber() << " shot";

					if (blue_warrior->GetStrength() == 0)
						std::cout << " and killed blue " << cities_[i + 1].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber();
					std::cout << '\n';
				}
			}
		}
		if (i > 1)
		{
			if (cities_[i].GetWarriorNumber("blue") != 0 && cities_[i - 1].GetWarriorNumber("red") != 0)
			{
				blue_warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
				red_warrior = rhq_->GetWarrior(cities_[i - 1].GetWarriorNumber("red"), cities_[i - 1].GetWarriorType("red"));

				if (blue_warrior->HasArrow() == true)
				{
					red_warrior->BeAttacked(blue_warrior->UseArrow());
					std::cout << clock_ << " blue " << cities_[i].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber() << " shot";

					if (red_warrior->GetStrength() == 0)
						std::cout << " and killed red " << cities_[i - 1].GetWarriorType("red") << ' ' << red_warrior->GetNumber();
					std::cout << '\n';
				}
			}
		}
	}
	red_warrior = nullptr;
	blue_warrior = nullptr;
}


void WorldOfWarcraft::WarriorsUseBombs()
{
	Warrior* red_warrior = nullptr;
	Warrior* blue_warrior = nullptr;
	int red_warrior_total_attack = 0, blue_warrior_total_attack = 0;
	bool anyone_uses_bomb = false;

	for (int i = 1; i < city_num_ + 1; i++)
	{
		anyone_uses_bomb = false;
		if (cities_[i].GetWarriorNumber("red") != 0 && cities_[i].GetWarriorNumber("blue") != 0)
		{
			red_warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
			blue_warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));

			if (red_warrior->GetStrength() > 0 && blue_warrior->GetStrength() > 0)
			{
				if ((cities_[i].GetFlag() == "red") || (cities_[i].GetFlag() == "none" && i % 2 != 0))
				{
					red_warrior_total_attack = red_warrior->GetAttack() + (red_warrior->HasSword() == true ? red_warrior->GetSword()->GetAttack() : 0);
					blue_warrior_total_attack = blue_warrior->GetAttack() / 2 + (blue_warrior->HasSword() == true ? blue_warrior->GetSword()->GetAttack() : 0);

					if (red_warrior->HasBomb() == true && cities_[i].GetWarriorType("blue") != "ninja")
					{
						if (blue_warrior->GetStrength() > red_warrior_total_attack && red_warrior->GetStrength() <= blue_warrior_total_attack)
						{
							red_warrior->UseBomb();
							anyone_uses_bomb = true;
							std::cout << clock_ << " red " << cities_[i].GetWarriorType("red") << ' ' << red_warrior->GetNumber() << " used a bomb ";
							std::cout << "and killed blue " << cities_[i].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber() << '\n';
						}
					}
					if (anyone_uses_bomb == false && blue_warrior->HasBomb() == true)
					{
						if (blue_warrior->GetStrength() <= red_warrior_total_attack)
						{
							blue_warrior->UseBomb();
							anyone_uses_bomb = true;
							std::cout << clock_ << " blue " << cities_[i].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber() << " used a bomb ";
							std::cout << "and killed red " << cities_[i].GetWarriorType("red") << ' ' << red_warrior->GetNumber() << '\n';
						}
					}
				}
				else
				{
					blue_warrior_total_attack = blue_warrior->GetAttack() + (blue_warrior->HasSword() == true ? blue_warrior->GetSword()->GetAttack() : 0);
					red_warrior_total_attack = red_warrior->GetAttack() / 2 + (red_warrior->HasSword() == true ? red_warrior->GetSword()->GetAttack() : 0);

					if (blue_warrior->HasBomb() == true && cities_[i].GetWarriorType("red") != "ninja")
					{
						if (red_warrior->GetStrength() > blue_warrior_total_attack && blue_warrior->GetStrength() <= red_warrior_total_attack)
						{
							blue_warrior->UseBomb();
							anyone_uses_bomb = true;
							std::cout << clock_ << " blue " << cities_[i].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber() << " used a bomb ";
							std::cout << "and killed red " << cities_[i].GetWarriorType("red") << ' ' << red_warrior->GetNumber() << '\n';
						}
					}
					if (anyone_uses_bomb == false && red_warrior->HasBomb() == true)
					{
						if (red_warrior->GetStrength() <= blue_warrior_total_attack)
						{
							red_warrior->UseBomb();
							anyone_uses_bomb = true;
							std::cout << clock_ << " red " << cities_[i].GetWarriorType("red") << ' ' << red_warrior->GetNumber() << " used a bomb ";
							std::cout << "and killed blue " << cities_[i].GetWarriorType("blue") << ' ' << blue_warrior->GetNumber() << '\n';
						}
					}
				}
				if (anyone_uses_bomb == true)
				{
					rhq_->RemoveWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
					cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("red"), "red");
					bhq_->RemoveWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
					cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("blue"), "blue");
				}
			}
		}
	}
	red_warrior = nullptr;
	blue_warrior = nullptr;
}


void WorldOfWarcraft::WarriorsFightWars()
{
	int red_warrior_num = 0, blue_warrior_num = 0;
	std::string red_warrior_type = "", blue_warrior_type = "";
	Warrior* red_warrior = nullptr;
	Warrior* blue_warrior = nullptr;
	int red_temp = 0, blue_temp = 0;
	info_size_ = 0;

	for (int i = 1; i < city_num_ + 1; i++)
	{
		cities_[i].SetShouldAwardWarrior("false", "red");
		cities_[i].SetShouldAwardWarrior("false", "blue");
	}

	for (int i = 1; i < city_num_ + 1; i++)
	{
		// If there is no warrior in the city, then directly enters next iteration
		if (cities_[i].GetWarriorNumber("red") == 0 && cities_[i].GetWarriorNumber("blue") == 0)
			continue;
		// If there is only red warrior in the city
		else if (cities_[i].GetWarriorNumber("red") != 0 && cities_[i].GetWarriorNumber("blue") == 0)
		{
			red_warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
			if (red_warrior->GetStrength() == 0)
			{
				rhq_->RemoveWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
				cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("red"), "red");
			}
		}
		else if (cities_[i].GetWarriorNumber("red") == 0 && cities_[i].GetWarriorNumber("blue") != 0)
		{
			blue_warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
			if (blue_warrior->GetStrength() == 0)
			{
				bhq_->RemoveWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
				cities_[i].RemoveWarrior(cities_[i].GetWarriorNumber("blue"), "blue");
			}
		}
		else
		{
			red_warrior_num = cities_[i].GetWarriorNumber("red");
			red_warrior_type = cities_[i].GetWarriorType("red");
			blue_warrior_num = cities_[i].GetWarriorNumber("blue");
			blue_warrior_type = cities_[i].GetWarriorType("blue");
			red_warrior = rhq_->GetWarrior(red_warrior_num, red_warrior_type);
			blue_warrior = bhq_->GetWarrior(blue_warrior_num, blue_warrior_type);

			if (red_warrior->GetStrength() == 0 && blue_warrior->GetStrength() == 0)
			{
				rhq_->RemoveWarrior(red_warrior_num, red_warrior_type);
				cities_[i].RemoveWarrior(red_warrior_num, "red");
				bhq_->RemoveWarrior(blue_warrior_num, blue_warrior_type);
				cities_[i].RemoveWarrior(blue_warrior_num, "blue");
			}
			else if (red_warrior->GetStrength() == 0)
			{
				if (blue_warrior_type == "wolf")
				{
					Wolf* wolf = static_cast<Wolf*>(blue_warrior);
					wolf->TakeWeapon(red_warrior->GetSword(), red_warrior->GetBomb(), red_warrior->GetArrow());
				}
				if (((cities_[i].GetFlag() == "blue") || (cities_[i].GetFlag() == "none" && i % 2 == 0)) && (blue_warrior_type == "dragon"))
				{
					Dragon* dragon = static_cast<Dragon*>(blue_warrior);
					dragon->ChangeMorale("win");
					if (dragon->GetMorale() > 0.8)
						info_list_[info_size_++] = clock_ + " blue " + dragon->Yell() + "in city " + std::to_string(i);
				}
				if (cities_[i].GetStrength() != 0)
				{
					info_list_[info_size_] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " earned ";
					info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
					bhq_->TakeStrength(cities_[i].BeTakenStrength());
				}
				if (cities_[i].GetLastWin() == "blue" && cities_[i].GetFlag() != "blue")
					info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("blue") + "in city " + std::to_string(i);
				else
					cities_[i].SetLastWin("blue");
				cities_[i].SetShouldAwardWarrior("true", "blue");
				rhq_->RemoveWarrior(red_warrior_num, red_warrior_type);
				cities_[i].RemoveWarrior(red_warrior_num, "red");
			}
			else if (blue_warrior->GetStrength() == 0)
			{
				if (red_warrior_type == "wolf")
				{
					Wolf* wolf = static_cast<Wolf*>(red_warrior);
					wolf->TakeWeapon(blue_warrior->GetSword(), blue_warrior->GetBomb(), blue_warrior->GetArrow());
				}
				if (((cities_[i].GetFlag() == "red") || (cities_[i].GetFlag() == "none" && i % 2 != 0)) && (red_warrior_type == "dragon"))
				{
					Dragon* dragon = static_cast<Dragon*>(red_warrior);
					dragon->ChangeMorale("win");
					if (dragon->GetMorale() > 0.8)
						info_list_[info_size_++] = clock_ + " red " + dragon->Yell() + "in city " + std::to_string(i);
				}
				if (cities_[i].GetStrength() != 0)
				{
					info_list_[info_size_] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " earned ";
					info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
					rhq_->TakeStrength(cities_[i].BeTakenStrength());
				}
				if (cities_[i].GetLastWin() == "red" && cities_[i].GetFlag() != "red")
					info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("red") + "in city " + std::to_string(i);
				else
					cities_[i].SetLastWin("red");
				cities_[i].SetShouldAwardWarrior("true", "red");
				bhq_->RemoveWarrior(blue_warrior_num, blue_warrior_type);
				cities_[i].RemoveWarrior(blue_warrior_num, "blue");
			}
			else
			{
				if ((cities_[i].GetFlag() == "red") || (cities_[i].GetFlag() == "none" && i % 2 != 0))
				{
					info_list_[info_size_] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " attacked blue " + blue_warrior_type + " ";
					info_list_[info_size_] += std::to_string(blue_warrior_num) + " in city " + std::to_string(i) + " with " + std::to_string(red_warrior->GetStrength());
					info_list_[info_size_++] += " elements and force " + std::to_string(red_warrior->GetAttack());
					red_temp = red_warrior->GetStrength();
					blue_temp = blue_warrior->GetStrength();
					blue_warrior->BeAttacked(red_warrior->GetAttack() + (red_warrior->HasSword() == true ? red_warrior->UseSword() : 0));
					if (blue_warrior->GetStrength() == 0)
					{
						if (red_warrior_type == "wolf")
						{
							Wolf* wolf = static_cast<Wolf*>(red_warrior);
							wolf->TakeWeapon(blue_warrior->GetSword(), blue_warrior->GetBomb(), blue_warrior->GetArrow());
						}
						cities_[i].SetShouldAwardWarrior("true", "red");
						info_list_[info_size_++] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " was killed in city " + std::to_string(i);
						if (red_warrior_type == "dragon")
						{
							Dragon* dragon = static_cast<Dragon*>(red_warrior);
							dragon->ChangeMorale("win");
							if (dragon->GetMorale() > 0.8)
								info_list_[info_size_++] = clock_ + " red " + dragon->Yell() + "in city " + std::to_string(i);
						}
						if (cities_[i].GetStrength() != 0)
						{
							info_list_[info_size_] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " earned ";
							info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
							rhq_->TakeStrength(cities_[i].BeTakenStrength());
						}
						if (cities_[i].GetLastWin() == "red" && cities_[i].GetFlag() != "red")
							info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("red") + "in city " + std::to_string(i);
						else
							cities_[i].SetLastWin("red");
						if (blue_warrior_type == "lion")
							red_warrior->ReceiveStrength(blue_temp);
						cities_[i].RemoveWarrior(blue_warrior_num, "blue");
						bhq_->RemoveWarrior(blue_warrior_num, blue_warrior_type);
					}
					else
					{
						if (blue_warrior_type == "ninja")
						{
							cities_[i].SetLastWin("none");
							if (red_warrior_type == "dragon")
							{
								Dragon* dragon = static_cast<Dragon*>(red_warrior);
								dragon->ChangeMorale("win");
								if (dragon->GetMorale() > 0.8)
									info_list_[info_size_++] = clock_ + " red " + dragon->Yell() + "in city " + std::to_string(i);
							}
						}
						else
						{
							info_list_[info_size_] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " fought back against ";
							info_list_[info_size_++] += "red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " in city " + std::to_string(i);
							red_warrior->BeAttacked(blue_warrior->GetAttack() / 2 + (blue_warrior->HasSword() == true ? blue_warrior->UseSword() : 0));
							if (red_warrior->GetStrength() == 0)
							{
								if (blue_warrior_type == "wolf")
								{
									Wolf* wolf = static_cast<Wolf*>(blue_warrior);
									wolf->TakeWeapon(red_warrior->GetSword(), red_warrior->GetBomb(), red_warrior->GetArrow());
								}
								cities_[i].SetShouldAwardWarrior("true", "blue");
								info_list_[info_size_++] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " was killed in city " + std::to_string(i);
								if (blue_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(blue_warrior);
									dragon->ChangeMorale("win");
								}
								if (cities_[i].GetStrength() != 0)
								{
									info_list_[info_size_] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " earned ";
									info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
									bhq_->TakeStrength(cities_[i].BeTakenStrength());
								}
								if (cities_[i].GetLastWin() == "blue" && cities_[i].GetFlag() != "blue")
									info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("blue") + "in city " + std::to_string(i);
								else
									cities_[i].SetLastWin("blue");
								if (red_warrior_type == "lion")
									blue_warrior->ReceiveStrength(red_temp);
								cities_[i].RemoveWarrior(red_warrior_num, "red");
								rhq_->RemoveWarrior(red_warrior_num, red_warrior_type);
							}
							else
							{
								if (red_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(red_warrior);
									dragon->ChangeMorale("not win");
									if (dragon->GetMorale() > 0.8)
										info_list_[info_size_++] = clock_ + " red " + dragon->Yell() + "in city " + std::to_string(i);
								}
								if (blue_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(blue_warrior);
									dragon->ChangeMorale("not win");
								}
								if (red_warrior_type == "lion")
								{
									Lion* lion = static_cast<Lion*>(red_warrior);
									lion->ChangeLoyalty("not win");
								}
								if (blue_warrior_type == "lion")
								{
									Lion* lion = static_cast<Lion*>(blue_warrior);
									lion->ChangeLoyalty("not win");
								}
								cities_[i].SetLastWin("none");
							}
						}
					}
				}
				else
				{
					info_list_[info_size_] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " attacked red " + red_warrior_type + " ";
					info_list_[info_size_] += std::to_string(red_warrior_num) + " in city " + std::to_string(i) + " with " + std::to_string(blue_warrior->GetStrength());
					info_list_[info_size_++] += " elements and force " + std::to_string(blue_warrior->GetAttack());
					blue_temp = blue_warrior->GetStrength();
					red_temp = red_warrior->GetStrength();
					red_warrior->BeAttacked(blue_warrior->GetAttack() + (blue_warrior->HasSword() == true ? blue_warrior->UseSword() : 0));
					if (red_warrior->GetStrength() == 0)
					{
						if (blue_warrior_type == "wolf")
						{
							Wolf* wolf = static_cast<Wolf*>(blue_warrior);
							wolf->TakeWeapon(red_warrior->GetSword(), red_warrior->GetBomb(), red_warrior->GetArrow());
						}
						cities_[i].SetShouldAwardWarrior("true", "blue");
						info_list_[info_size_++] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " was killed in city " + std::to_string(i);
						if (blue_warrior_type == "dragon")
						{
							Dragon* dragon = static_cast<Dragon*>(blue_warrior);
							dragon->ChangeMorale("win");
							if (dragon->GetMorale() > 0.8)
								info_list_[info_size_++] = clock_ + " blue " + dragon->Yell() + "in city " + std::to_string(i);
						}
						if (cities_[i].GetStrength() != 0)
						{
							info_list_[info_size_] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " earned ";
							info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
							bhq_->TakeStrength(cities_[i].BeTakenStrength());
						}
						if (cities_[i].GetLastWin() == "blue" && cities_[i].GetFlag() != "blue")
							info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("blue") + "in city " + std::to_string(i);
						else
							cities_[i].SetLastWin("blue");
						if (red_warrior_type == "lion")
							blue_warrior->ReceiveStrength(red_temp);
						cities_[i].RemoveWarrior(red_warrior_num, "red");
						rhq_->RemoveWarrior(red_warrior_num, red_warrior_type);
					}
					else
					{
						if (red_warrior_type == "ninja")
						{
							cities_[i].SetLastWin("none");
							if (blue_warrior_type == "dragon")
							{
								Dragon* dragon = static_cast<Dragon*>(blue_warrior);
								dragon->ChangeMorale("win");
								if (dragon->GetMorale() > 0.8)
									info_list_[info_size_++] = clock_ + " blue " + dragon->Yell() + "in city " + std::to_string(i);
							}
						}
						else
						{
							info_list_[info_size_] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " fought back against ";
							info_list_[info_size_++] += "blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " in city " + std::to_string(i);
							blue_warrior->BeAttacked(red_warrior->GetAttack() / 2 + (red_warrior->HasSword() == true ? red_warrior->UseSword() : 0));
							if (blue_warrior->GetStrength() == 0)
							{
								if (red_warrior_type == "wolf")
								{
									Wolf* wolf = static_cast<Wolf*>(red_warrior);
									wolf->TakeWeapon(blue_warrior->GetSword(), blue_warrior->GetBomb(), blue_warrior->GetArrow());
								}
								cities_[i].SetShouldAwardWarrior("true", "red");
								info_list_[info_size_++] = clock_ + " blue " + blue_warrior_type + " " + std::to_string(blue_warrior_num) + " was killed in city " + std::to_string(i);
								if (red_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(red_warrior);
									dragon->ChangeMorale("win");
								}
								if (cities_[i].GetStrength() != 0)
								{
									info_list_[info_size_] = clock_ + " red " + red_warrior_type + " " + std::to_string(red_warrior_num) + " earned ";
									info_list_[info_size_++] += std::to_string(cities_[i].GetStrength()) + " elements for his headquarter";
									rhq_->TakeStrength(cities_[i].BeTakenStrength());
								}
								if (cities_[i].GetLastWin() == "red" && cities_[i].GetFlag() != "red")
									info_list_[info_size_++] = clock_ + " " + cities_[i].SetFlag("red") + "in city " + std::to_string(i);
								else
									cities_[i].SetLastWin("red");
								if (blue_warrior_type == "lion")
									red_warrior->ReceiveStrength(blue_temp);
								cities_[i].RemoveWarrior(blue_warrior_num, "blue");
								bhq_->RemoveWarrior(blue_warrior_num, blue_warrior_type);
							}
							else
							{
								if (blue_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(blue_warrior);
									dragon->ChangeMorale("not win");
									if (dragon->GetMorale() > 0.8)
										info_list_[info_size_++] = clock_ + " blue " + dragon->Yell() + "in city " + std::to_string(i);
								}
								if (red_warrior_type == "dragon")
								{
									Dragon* dragon = static_cast<Dragon*>(red_warrior);
									dragon->ChangeMorale("not win");
								}
								if (blue_warrior_type == "lion")
								{
									Lion* lion = static_cast<Lion*>(blue_warrior);
									lion->ChangeLoyalty("not win");
								}
								if (red_warrior_type == "lion")
								{
									Lion* lion = static_cast<Lion*>(red_warrior);
									lion->ChangeLoyalty("not win");
								}
								cities_[i].SetLastWin("none");
							}
						}
					}
				}
			}
		}
	}
	for (int i = city_num_; i >= 1; i--)
	{
		if (rhq_->GetStrength() < 8)
			break;
		if (cities_[i].ShouldAwardWarrior("red") == true)
		{
			red_warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
			red_warrior->ReceiveStrength(rhq_->AwardStrength());
		}
	}
	for (int i = 1; i < city_num_ + 1; i++)
	{
		if (bhq_->GetStrength() < 8)
			break;
		if (cities_[i].ShouldAwardWarrior("blue") == true)
		{
			blue_warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
			blue_warrior->ReceiveStrength(bhq_->AwardStrength());
		}
	}
	for (int i = 1; i < city_num_ + 1; i++)
	{
		if (cities_[i].GetStrength() > 0)
		{
			if (cities_[i].ShouldAwardWarrior("red") == true)
				rhq_->TakeStrength(cities_[i].BeTakenStrength());
			else if (cities_[i].ShouldAwardWarrior("blue") == true)
				bhq_->TakeStrength(cities_[i].BeTakenStrength());
			else
				continue;
		}
	}
	for (int i = 0; i < info_size_; i++)
		std::cout << info_list_[i] << '\n';
	red_warrior = nullptr;
	blue_warrior = nullptr;
}


void WorldOfWarcraft::HeadquartersReportStrength()
{
	std::cout << clock_ << ' ' << rhq_->ReportStrength() << " elements in red headquarter\n";
	std::cout << clock_ << ' ' << bhq_->ReportStrength() << " elements in blue headquarter\n";
}


void WorldOfWarcraft::WarriorsReportWeapons()
{
	Warrior* warrior = nullptr;
	for (int i = 0; i < city_num_ + 1; i++)
	{
		if (cities_[i].GetWarriorNumber("red") != 0)
		{
			warrior = rhq_->GetWarrior(cities_[i].GetWarriorNumber("red"), cities_[i].GetWarriorType("red"));
			std::cout << clock_ << " red " << cities_[i].GetWarriorType("red") << ' ' << warrior->GetNumber() << ' ';
			warrior->ReportWeapons();
			std::cout << '\n';
		}
	}
	for (int i = 0; i < blue_headquarter_enemy_; i++)
	{
		warrior = rhq_->GetWarrior(blue_headquarter_enemy_num_[i], blue_headquarter_enemy_type_[i]);
		std::cout << clock_ << " red " << blue_headquarter_enemy_type_[i] << ' ' << warrior->GetNumber() << ' ';
		warrior->ReportWeapons();
		std::cout << '\n';
	}
	for (int i = 0; i < red_headquarter_enemy_; i++)
	{
		warrior = bhq_->GetWarrior(red_headquarter_enemy_num_[i], red_headquarter_enemy_type_[i]);
		std::cout << clock_ << " blue " << red_headquarter_enemy_type_[i] << ' ' << warrior->GetNumber() << ' ';
		warrior->ReportWeapons();
		std::cout << '\n';
	}
	for (int i = 1; i < city_num_ + 2; i++)
	{
		if (cities_[i].GetWarriorNumber("blue") != 0)
		{
			warrior = bhq_->GetWarrior(cities_[i].GetWarriorNumber("blue"), cities_[i].GetWarriorType("blue"));
			std::cout << clock_ << " blue " << cities_[i].GetWarriorType("blue") << ' ' << warrior->GetNumber() << ' ';
			warrior->ReportWeapons();
			std::cout << '\n';
		}
	}
}


WorldOfWarcraft::WorldOfWarcraft(int s, int cn, int aa, int ld, int ec, int data[]): city_num_(cn), end_clock_(ec)
{
	Arrow::SetArrowAttack(aa);
	Dragon::SetDragonStrength(data[0]);
	Ninja::SetNinjaStrength(data[1]);
	Iceman::SetIcemanStrength(data[2]);
	Lion::SetLionStrength(data[3]);
	Wolf::SetWolfStrength(data[4]);
	Dragon::SetDragonAttack(data[5]);
	Ninja::SetNinjaAttack(data[6]);
	Iceman::SetIcemanAttack(data[7]);
	Lion::SetLionAttack(data[8]);
	Wolf::SetWolfAttack(data[9]);
	Lion::SetLionLoyaltyDecrease(ld);
	clock_ = "000:00";
	rhq_ = new RedHeadquarter(s, data);
	bhq_ = new BlueHeadquarter(s, data);
	cities_ = new City[city_num_ + 2];
	red_headquarter_enemy_ = 0;
	red_headquarter_enemy_num_[0] = 0;
	red_headquarter_enemy_num_[1] = 0;
	red_headquarter_enemy_type_[0] = "none";
	red_headquarter_enemy_type_[1] = "none";
	blue_headquarter_enemy_ = 0;
	blue_headquarter_enemy_num_[0] = 0;
	blue_headquarter_enemy_num_[1] = 0;
	blue_headquarter_enemy_type_[0] = "none";
	blue_headquarter_enemy_type_[1] = "none";
	game_over_ = false;
	info_list_ = new std::string[6 * city_num_];
	info_size_ = 0;
}


WorldOfWarcraft::~WorldOfWarcraft()
{
	delete rhq_;
	rhq_ = nullptr;
	delete bhq_;
	bhq_ = nullptr;
	delete[] cities_;
	cities_ = nullptr;
	delete[] info_list_;
	info_list_ = nullptr;
}


void WorldOfWarcraft::Run()
{
	int clock_by_minute = 0;

	while (clock_by_minute <= end_clock_)
	{
		switch (clock_by_minute % 60)
		{
			case 0: CreateWarrior(); break;
			case 5: LionsEscape(); break;
			case 10: WarriorsMarchForward(); break;
			case 20: CitiesProduceStrength(); break;
			case 30: WarriorsTakeStrength(); break;
			case 35: WarriorsShootArrows(); break;
			case 38: WarriorsUseBombs(); break;
			case 40: WarriorsFightWars(); break;
			case 50: HeadquartersReportStrength(); break;
			case 55: WarriorsReportWeapons(); break;
			default: break;
		}

		if (game_over_ == true)
			break;

		ClockGoNext();
		clock_by_minute++;
	}
}


