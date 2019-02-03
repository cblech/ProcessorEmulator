#include "MyDrawable.h"
#include "SFML\Graphics.hpp"


MyDrawable::MyDrawable()
{
	init();
}

MyDrawable::MyDrawable(sf::Vector2f pos):
	position(pos)
{
	init();
}


MyDrawable::~MyDrawable()
{
}

void MyDrawable::draw(sf::RenderWindow * window)
{

}

std::list<sf::Drawable *> * MyDrawable::getDrawables()
{
	return &drawables;
}


void MyDrawable::init()
{
	//fontSegment.loadFromFile("DSEG14Classic-Bold.ttf");
	//fontDescription.loadFromFile("Montserrat-Regular.ttf");
}
