#include "GrHexAusgabe.h"
#include "Util.h"
#include "SFML\Graphics.hpp"


void GrHexAusgabe::setText(unsigned short s)
{
	//textString = ;
	text.setString(util::to_hex(s,false));
}

std::string GrHexAusgabe::getText()
{
	return text.getString();
}

void GrHexAusgabe::draw(sf::RenderWindow * window)
{
	window->draw(border);
	window->draw(textBackground);
	window->draw(text);
}

void GrHexAusgabe::init()
{

	fontSegment->loadFromFile("DSEG14Classic-Bold.ttf");

	border = sf::RectangleShape(sf::Vector2f(90.f, 22.f));
	border.setOutlineColor(sf::Color::Black);
	border.setOutlineThickness(5.f);
	border.setPosition(position + sf::Vector2f(5.f, 5.f));
	drawables.push_back(&border);

	textBackground = sf::Text("~~~~", *fontSegment, 20);
	textBackground.setFillColor(sf::Color(200,200,200));
	textBackground.setPosition(position + sf::Vector2f(15.f, 6.f));
	drawables.push_back(&textBackground);

	text = sf::Text();
	text.setFont(*fontSegment);
	text.setString("Test");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(position + sf::Vector2f(15.f, 6.f));
	drawables.push_back(&text);

}
