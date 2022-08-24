#include "Character.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "ConsolGR.h"
#include "CMNDarea.h"
#include "Spider.h"
#include <cstdlib>

void choice(CMNDarea *CM, ConsolGR *GR, Character* CH){
	std::string msg = "Your action (0 - exit, 1 - feed, 2 - play, 3 - cradle, 4 - healing): ";
	ptr_0:
	std::string msg_tmp = msg; 
	CM->clear(GR);
	CM->print_msg(GR, msg_tmp);
	char tmp;
   	std::string tmp_s;
	std::getline(std::cin, tmp_s);
 	if(tmp_s.size() > 1) tmp = 0;
    else tmp = tmp_s.c_str()[0];
	switch (tmp)
	{
	case '0':
		CM->clear(GR);
		if(CM->choise_YorN(GR, "Do you really want to get out of this wonderful game? (y or n): ")){
			CH->save_change("petNO1.svpt");
			_exit(0);
		}
		break;
	case '1':
		CH->feed(1);
		break;
	case '2':
		CH->play(1);
		break;
	case '3':
		CH->cradle();
		break;
	case '4':
		CH->healing(1);
		break;
	default:
		std::string tmp = "ERROR, Try again! ";
		msg_tmp = tmp + msg;
		goto ptr_0;
		break;
	}  
}

int getXcoord()
{
    CONSOLE_SCREEN_BUFFER_INFO info_x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_x);
    return info_x.dwCursorPosition.X;
}
 
int getYcoord()
{
    CONSOLE_SCREEN_BUFFER_INFO info_y;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info_y);
    return info_y.dwCursorPosition.Y;
}

int main() {
	ConsolGR GR("Tamagochi v-0.1");
	CMNDarea CM(GR);
	auto resad = [&GR, &CM]()->bool{CM.clear(&GR); return CM.choise_YorN(&GR,"Your pet is dead. Do you want to resurrect him? (y or n): ");};
	Spider pet;
	if(CM.choise_YorN(&GR, "Download the data of the last game? (y or n): ")){
		pet.upload_past_save("petNO1.svpt");
	}
	do {
		try {
			CM.clear(&GR);
			//actions with the character
			
			pet.draw(&GR);
			GR.set_Point_s(0, 21);
			GR.print("Spider: Velghelm 3");
			while(true){
				{
					GR.set_Point_s(0, 20);
					{
						COORD st;
						st.X = 0;
						st.Y = 20; 
						COORD end;
						end.X = 25;
						end.Y = 20; 
						GR.ClearCarnel(st, end);
					}
					std::string tmp = "FT "+std::to_string(pet.get_level_fatigue()) + "\t" + "HP "+std::to_string(pet.get_level_health()) + "\t" + "HNGP "+std::to_string(pet.get_level_hunger()); 
					GR.print(tmp);
				}
				choice(&CM, &GR, &pet);
				pet.save_change("petNO1.svpt");
			}
		}
		catch (std::string a) {
			//character death
			GR.set_Point_s(0, 20);
				{
					COORD st;
					st.X = 0;
					st.Y = 20; 
					COORD end;
					end.X = 25;
					end.Y = 20; 
					GR.ClearCarnel(st, end);
				}
				std::string tmp = "FT "+std::to_string(pet.get_level_fatigue()) + "\t" + "HP "+std::to_string(pet.get_level_health()) + "\t" + "HNGP "+std::to_string(pet.get_level_hunger()); 
				GR.print(tmp);
			pet.restart();
			pet.save_change("petNO1.svpt");			
		}

	} while (resad());
	GR.SetColor(LightRed, Black);
	pet.draw(&GR);
	CM.clear(&GR);
	CM.print_msg(&GR,"You didn't perform the resurrection ceremony. Velghelm 3 was offended and bit you at night.");
	bool tmp;
	std::cin >> tmp;
}