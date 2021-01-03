#include "stdafx.h"
#include "blast.h"


blast::blast()
{

	rectangle.setFillColor(Color::Red);
	rectangle.setSize(Vector2f(5, 5));
	rectangle.setPosition(0, 5);




}

void blast::update()
{
	if (direction == 1)
	{
		rectangle.move(0, -1);
	}
	else
		if (direction == 2)
			rectangle.move(0, 1);
		else
			if (direction == 3)
				rectangle.move(-1, 0);
			else
				if (direction == 4)
					rectangle.move(1,0);


	

}
