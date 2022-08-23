#include "ConsolGR.h"
#include <string>
#include <iostream>

ConsolGR::ConsolGR(const std::string& title){    
	SetConsoleTitle("title");
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}