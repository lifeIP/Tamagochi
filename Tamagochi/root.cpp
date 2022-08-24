﻿#include "Character.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "ConsolGR.h"
#include "CMNDarea.h"


int main() {
	ConsolGR GR("Tamagochi");
	CMNDarea CM(GR);
	bool start_gm;
	do {
		start_gm = false;
		Character pet;
		try {
			//actions with the character
			if(CM.choise_YorN(&GR, "Download the data of the last game? (y or n): ")){
				pet.upload_past_save("petNO1.svpt");
			}
			
			
			pet.save_change("petNO1.svpt");
			std::cout << pet.get_level_fatigue() << "\t" << pet.get_level_health() << "\t" << pet.get_level_hunger() << std::endl;
		}
		catch (std::string a) {
			//character death
			
		}
	} while (start_gm);
}