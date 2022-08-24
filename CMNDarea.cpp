#include "CMNDarea.h"
#include <windows.h>
#include "ConsolGR.h"
#include <iostream>
#include <string>

#define CIN_FLUSH if(char(std::cin.peek()) == '\n')std::cin.ignore();if (std::cin.fail()) {std::cin.clear();std::cin.ignore(32767, '\n');}

CMNDarea::CMNDarea(ConsolGR& GR){
	COORD end;
	GR.GetBufferChars(&end); // получение размеров	
	auto print_horizontal = [&GR, &end](int start_end){
		COORD st;
	    st.Y = end.Y - start_end;
		st.X = 0;
		GR.ClearCarnel(st, end);
		for(int X = 0; X < end.X; X++){
    		GR.set_Point_s(X, st.Y);
			GR.print("O");
		}
	};
	auto print_vertical = [&GR, &end, this](int x_pos, int y_pos){
		COORD st;
		st.X = x_pos;
		st.Y = end.Y - y_pos;
		for(int Y = st.Y; Y < end.Y; Y++){
			GR.set_Point_s(st.X, Y);
			GR.print("O");
			size.X = x_pos - 1;
			size.Y = Y - 1;
		}
	};
	GR.SetColor(Red, Black);
	print_horizontal(6);
	position.X = 1;
	position.Y = end.Y - 5;
	print_vertical(0, 6);
	print_horizontal(1);
	print_vertical(end.X-1, 6);
	GR.SetColor(White, Black);
}

bool CMNDarea::choise_YorN(ConsolGR* GR, const std::string& msg){
	std::string msg_tmp = msg;	
	ptr_0:
	{
		COORD point_0;
		point_0 = position;
        point_0.X += 1;
		GR->set_Point_s(point_0);
		{
			COORD point_1;
			GR->GetBufferChars(&point_1);
			point_1.Y = 1;
			GR->ClearCarnel(point_0, point_1);
		}
		GR->print(msg_tmp);
	}
    
	char tmp;
    std::string tmp_s;
    std::getline(std::cin, tmp_s);
    if(tmp_s.size() > 1) tmp = 0;
    else tmp = tmp_s.c_str()[0];    
	if(tmp == 'Y' ||  tmp == 'y') return true;
	else if(tmp == 'N' ||  tmp == 'n') return false;
	msg_tmp = "ERROR, Try again! " + msg;
	clear(GR);
	goto ptr_0;
}
void CMNDarea::clear(ConsolGR* GR){
	GR->ClearCarnel(position, size);
}
void CMNDarea::print_msg(ConsolGR* GR, const std::string& msg){
	clear(GR);
	GR->set_Point_s(position);
	GR->print(msg);
}