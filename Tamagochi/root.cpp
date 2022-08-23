#include "Character.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "ConsolGR.h"

int main() {
	bool start_gm;
	do {
		start_gm = false;
		Character pet;
		try {
			//actions with the character
			pet.upload_past_save("petNO1.svpt");
			
			
			
			
			pet.save_change("petNO1.svpt");
			std::cout << pet.get_level_fatigue() << "\t" << pet.get_level_health() << "\t" << pet.get_level_hunger() << std::endl;
		}
		catch (std::string a) {
			//character death
			
		}
	} while (start_gm);
}