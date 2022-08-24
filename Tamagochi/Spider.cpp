#include "Spider.h"
#include "Character.h"
#include "ConsolGR.h"

Spider::Spider(){
	texture = 
"\		   /\\\n\
                  /  \\\n\
                 |  _ \\                  _\n\
                 | / \\ \\                / \\\n\
                 |/   \\ \\              /   \\\n\
                 /     \\ |        /\\  /     \\\n\
                /|      \\| ~  ~  /  \\/       \\\n\
        _______/_|_______\\(o)(o)/___/\\_____   \\\n\
       /      /  |       (______)     \\    \\   \\_\n\
      /      /   |                     \\    \\\n\
     /      /    |                      \\    \\\n\
    /      /     |                       \\    \\\n\
   /     _/      |                        \\    \\\n\
  /             _|                         \\    \\_\n\
_/                                          \\\n\
                                             \\\n\
                                              \\_\n\
";
}
void Spider::draw(ConsolGR* GR){
	GR->set_Point_s(0, 3);
	GR->print(texture);
}