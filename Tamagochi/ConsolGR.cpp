#include "ConsolGR.h"
#include <string>
#include <iostream>

ConsolGR::ConsolGR(const std::string& title){    
	SetConsoleTitle("title");
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
}
void ConsolGR::set_Point_s(const int& x, const int& y){
	coords.X = x;
	coords.Y = y;
}
void ConsolGR::print(const std::string& msg){
	SetConsoleCursorPosition(hd, coords);
	std::cout << msg;
}
void ConsolGR::SetColor(ConsoleColor text, ConsoleColor background){
	SetConsoleTextAttribute(hd, (WORD)((background << 4) | text));
}
void ConsolGR::GetBufferChars(COORD *Size){
	GetConsoleScreenBufferInfo(hd, &csbInfo);
    Size->X = csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1;
    Size->Y = csbInfo.srWindow.Bottom - csbInfo.srWindow.Top + 1;
}
void ConsolGR::ClearCarnel(COORD startCLS, COORD endCLS){
	COORD coords;
	for(int X = startCLS.X; X <= endCLS.X; X++){
		coords.X = X;
		for(int Y = startCLS.Y; Y <= endCLS.Y; Y++){
			coords.Y = Y;
			SetConsoleCursorPosition(hd, coords);
			std::cout << " ";
		}
	}
}