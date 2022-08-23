#pragma once
#include <string>
#include <fstream>
class Loger
{
public:
	Loger() {
		file.open("pet_life.log", std::ios::app);
	}
	int log_send(const std::string& log) {
		file.write(log.c_str(), log.size());
		return file.is_open();
	}
	~Loger() {
		file.close();
	}
private:
	std::fstream file;
};

class Character
{
private:
	short level_health; 
	short level_hunger;
	short level_fatigue;
	Loger log;
	void monitoring_indicators();
public:
	void upload_past_save(const std::string& file_name);
	void save_change(const std::string& file_name);
	Character();
	short get_level_health()const;
	short get_level_hunger()const;
	short get_level_fatigue()const;
	void feed(const short& quantity);
	void play(const short& quantity);
	void cradle();
	void healing(const short& quantity);
};

