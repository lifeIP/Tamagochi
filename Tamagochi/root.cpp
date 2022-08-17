#include <iostream>
#include "Character.h"
#include <string>

int main() {
	Character pet;
	try {
		for (int i = 0; i <= 20; i++) {
			pet.play(1);
		}
	}
	catch (std::string a){
		std::cout << pet.get_level_health() << std::endl;
		std::cout << pet.get_level_hunger() << std::endl;
		std::cout << pet.get_level_fatigue() << std::endl;
		std::cout << a << std::endl;
	}
}