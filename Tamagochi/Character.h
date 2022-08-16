#pragma once
class Character
{
	short level_health; 
	short level_hunger;
	short level_fatigue;
public:
	short get_level_health()const;
	short get_level_hunger()const;
	short get_level_fatigue()const;
	void feed();
	void play();
	void cradle();
	void healing();
};

