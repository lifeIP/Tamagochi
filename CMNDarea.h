#pragma once
#include <windows.h>
#include "ConsolGR.h"
#include <iostream>
#include <string>

class CMNDarea{
	COORD position;
	COORD size;
public:
	CMNDarea(ConsolGR& GR);
	
	bool choise_YorN(ConsolGR* GR, const std::string& msg);
	void clear(ConsolGR* GR);
	void print_msg(ConsolGR* GR, const std::string& msg);
};