#include "GrSignalGetIndicator.h"
#include <string>



GrSignalGetIndicator::GrSignalGetIndicator(std::string description, DescPos descPos)
{
	init(description, descPos);
}

GrSignalGetIndicator::GrSignalGetIndicator(sf::Vector2f position, std::string description, DescPos descPos)
	:MyDrawable(position)
{
	init(description, descPos);
}

GrSignalGetIndicator::~GrSignalGetIndicator()
{
}

void GrSignalGetIndicator::draw(sf::RenderWindow * window)
{
	window->draw(circle);
	descText.draw(window);
}

void GrSignalGetIndicator::setActive(bool isActive)
{
	if (isActive)
		circle.setFillColor(colorActive);
	else
		circle.setFillColor(colorInactive);
}

void GrSignalGetIndicator::init(std::string description, DescPos descPos)
{
	circle = sf::CircleShape(5.f);
	circle.setFillColor(colorInactive);
	circle.setPosition(position);

	switch (descPos)
	{
	case None:
		descText = Beschreibung("", position);
		break;

	case Left:
		descText = Beschreibung(description, position + sf::Vector2f(-2.f, -1.f), DescFlags::rechtsBuendig);
		break;

	case Below:
		descText = Beschreibung(description, position + sf::Vector2f(-1.f, 12.f), DescFlags::rechtsBuendig | DescFlags::turned);
		break;

	case Above:
		descText = Beschreibung(description, position + sf::Vector2f(-1.f, -2.f), DescFlags::turned);
		break;

	default:
		descText = Beschreibung(description, position);
		break;
	}
}
