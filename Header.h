#include "stdafx.h"
#include "SFML\Graphics.hpp"
using namespace sf;

#define MAX 3

class Header
{
public:
	
	Header( float width, float height);

	void drawmenu(RenderWindow &window);
	void moveup();
	void movedown();



private:
		int selected;
	Font font;
	Text text[MAX];



};

