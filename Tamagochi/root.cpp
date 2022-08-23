#include "Character.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "ConsolGR.h"


bool choise(ConsolGR* GR, const std::string& msg){
	GR->set_Point_s(0, 0);
	GR->print("This is test!");
	return 1;
}
int main() {
	ConsolGR GR("Tamagochi");
	bool start_gm;
	do {
		start_gm = false;
		Character pet;
		try {
			//actions with the character
			if(choise(&GR, "sad")){
				pet.upload_past_save("petNO1.svpt");
				std::cout << "\t101\t";
			}
			
			
			
			pet.save_change("petNO1.svpt");
			std::cout << pet.get_level_fatigue() << "\t" << pet.get_level_health() << "\t" << pet.get_level_hunger() << std::endl;
		}
		catch (std::string a) {
			//character death
			
		}
	} while (start_gm);
}