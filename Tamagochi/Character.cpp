#include "Character.h"
#include <iostream>
#include <string>
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
		log.log_send(std::string("*****\tPET RIP\t*****\n"));
		throw std::string("THE_PET_DIED");
	}
	if (level_health > 10) level_health = 10;

	log.log_send(std::string("Indicators changes! (health = " + std::to_string(level_health) +
		" hunger = " + std::to_string(level_hunger) + " fatigue = " + std::to_string(level_fatigue) +
		")\n"));
}

Character::Character()
{
	level_fatigue = 0;
	level_health = 10;
	level_hunger = 0;
	log.log_send(std::string("*****\tNEW PET\t*****\n"));
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
	log.log_send(std::string("feed (hunger - " + std::to_string(quantity))+")\n");
	monitoring_indicators();
}

void Character::play(const short& quantity)
{
	level_fatigue += quantity;
	log.log_send(std::string("play (fatigue + " + std::to_string(quantity)) + ")\n");
	monitoring_indicators();
}

void Character::cradle()
{
	level_fatigue = 0;
	level_health++;
	level_hunger++;
	log.log_send(std::string("cradle (fatigue = 0)\n"));
	monitoring_indicators();
}

void Character::healing(const short& quantity)
{
	level_health += quantity;
	log.log_send(std::string("healing (health + " + std::to_string(quantity)) + ")\n");
	monitoring_indicators();
}

