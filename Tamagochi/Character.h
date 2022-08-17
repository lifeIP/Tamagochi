#pragma once
class Character
{
	short level_health; 
	short level_hunger;
	short level_fatigue;
	void monitoring_indicators();
public:
	Character();
	short get_level_health()const;
	short get_level_hunger()const;
	short get_level_fatigue()const;
	void feed(const short& quantity);
	void play(const short& quantity);
	void cradle();
	void healing(const short& quantity);
};

