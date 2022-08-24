#include "ConsolGR.h"
#include <string>
#include <iostream>
#include <windows.h>

ConsolGR::ConsolGR(const std::string& title){    
	SetConsoleTitle("SUPER Spider");
    system("color 07");
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
}
void ConsolGR::set_Point_s(const int& x, const int& y){
	coords.X = x;
	coords.Y = y;
}
void ConsolGR::set_Point_s(COORD coord){
	coords = coord;
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
void ConsolGR::SetWindowSize(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;
    SetConsoleScreenBufferSize(hd, coord);            // Set Buffer Size
    SetConsoleWindowInfo(hd, TRUE, &Rect);            // Set Window Size
}
void ConsolGR::SetWindowSize(COORD coord){
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = coord.Y - 1;
    Rect.Right = coord.X - 1;
    SetConsoleScreenBufferSize(hd, coord);            // Set Buffer Size
    SetConsoleWindowInfo(hd, TRUE, &Rect);            // Set Window Size
}