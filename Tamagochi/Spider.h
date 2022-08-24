#pragma once
#include <string>
#include "ConsolGR.h"
#include "Character.h"

class Spider: public Character 
{
	std::string texture;
public:
	Spider();
	void draw(ConsolGR* GR);
};