#include "Character.h"
#include <string>
#include <iostream>
void Character::monitoring_indicators()
{
	if (level_hunger > 10) {
		level_hunger = 10;
		level_health--;
	}
	if (level_hunger < 0) {
		level_hunger = 0;
		level_health--;
	}

	if (level_fatigue > 10) {
		level_fatigue = 10;
		level_health--;
	}

	if (level_health < 1) {
		// PET RIP
		throw std::string("THE_PET_DIED");
	}
	if (level_health > 10) level_health = 10;
}

Character::Character()
{
	level_fatigue = 0;
	level_health = 10;
	level_hunger = 0;
}

short Character::get_level_health() const
{
	return level_health;
}

short Character::get_level_hunger() const
{
	return level_hunger;
}

short Character::get_level_fatigue() const
{
	return level_fatigue;
}

void Character::feed(const short& quantity)
{
	level_hunger -= quantity;
	monitoring_indicators();
}

void Character::play(const short& quantity)
{
	level_fatigue += quantity;
	std::cout << level_fatigue << std::endl;
	monitoring_indicators();
}

void Character::cradle()
{
	level_fatigue = 0;
	level_health++;
	level_hunger++;
	monitoring_indicators();
}

void Character::healing(const short& quantity)
{
	level_health += quantity;
	monitoring_indicators();
}
