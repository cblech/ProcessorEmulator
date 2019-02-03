#pragma once
#include "MyDrawable.h"
#include "Beschreibung.h"
#include <string>

enum DescPos
{
	None,
	Left,
	Below,
	Above
};

class GrSignalGetIndicator :
	public MyDrawable
{
public:
	GrSignalGetIndicator(std::string description="", DescPos descPos = DescPos::None);
	GrSignalGetIndicator(sf::Vector2f position, std::string description = "", DescPos descPos = DescPos::None);
	~GrSignalGetIndicator();

	void draw(sf::RenderWindow * window)  override;

	void setActive(bool isActive);

private:
	

	Beschreibung descText;
	sf::CircleShape circle;

	void init(std::string description = "",DescPos descPos = DescPos::None);
};

