#pragma once
#include <windows.h>
#include <string>

enum ConsoleColor
{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};
class ConsolGR{
	HANDLE hd;
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	COORD coords;
public:
	ConsolGR(const std::string& title);
	void set_Point_s(const int& x, const int& y);
	void print(const std::string& msg);
	void SetColor(ConsoleColor text, ConsoleColor background);
    void GetBufferChars(COORD *Size);
    void ClearCarnel(COORD startCLS, COORD endCLS);
};
