#pragma once
#include "SFML\Graphics.hpp"
#include <list>

#define colorPositive sf::Color(59, 235, 0,255)
#define colorActive sf::Color(235, 23, 0,255)
#define colorInactive sf::Color(100,100,100,255)
#define colorDataBus sf::Color(112,112,112,255)
#define colorAddressBus sf::Color(180,180,180,255)


class MyDrawable
{
public:
	MyDrawable();
	MyDrawable(sf::Vector2f position);
	~MyDrawable();

	virtual void draw(sf::RenderWindow * window);
	std::list<sf::Drawable *> * getDrawables();

protected:
	//sf::Font fontSegment;
	//sf::Font fontDescription;

	sf::Vector2f position;
	std::list<sf::Drawable *> drawables;

private:
	void init();
};

