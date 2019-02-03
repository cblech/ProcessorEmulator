#include "Beschreibung.h"
#include "ProcessorEmulator.h"




Beschreibung::~Beschreibung()
{
}

void Beschreibung::draw(sf::RenderWindow * window)
{
	window->draw(text);
}

void Beschreibung::init(std::string text, DescFlags flags)
{
	this->flags = flags;
	fontDesc = std::make_shared < sf::Font>();
	if (!fontDesc->loadFromFile("Montserrat-Regular.ttf"))
		g::debug.error("Montserrat Font failed to load!");

	this->text.setString(text);

	this->text.setFont(*fontDesc);
	this->text.setCharacterSize(10);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(position);
	if ((flags&DescFlags::rechtsBuendig) == DescFlags::rechtsBuendig)
	{
		this->text.setOrigin((this->text.getLocalBounds().width), 0.f);
		//this->text.move(-(this->text.getLocalBounds().width), 0.f);
	}
	if ((flags&DescFlags::turned)==DescFlags::turned)
	{
		this->text.setRotation(-90.f);
	}

}
