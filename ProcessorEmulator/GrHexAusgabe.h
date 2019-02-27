#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MyDrawable.h"

class GrHexAusgabe: public MyDrawable
{
public:
	GrHexAusgabe() { init(); };
	GrHexAusgabe(sf::Vector2f position) : MyDrawable(position) { init(); };
	~GrHexAusgabe() {};

	void setText(unsigned short s);
	std::string getText();
	void draw (sf::RenderWindow * window)override;

private:
	std::shared_ptr < sf::Font> fontSegment = std::make_shared < sf::Font>();

	void init();
	sf::RectangleShape border;
	sf::Text text;
	sf::Text textBackground;
	std::string textString;
};

