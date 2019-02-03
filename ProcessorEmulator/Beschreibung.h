#pragma once
#include "MyDrawable.h"
#include "SFML\Graphics.hpp"

enum DescFlags :int
{
	none = 0,
	turned = 1 << 0,
	rechtsBuendig = 1 << 1
};

inline DescFlags operator|(DescFlags a, DescFlags b)
{
	return static_cast<DescFlags>(static_cast<int>(a) | static_cast<int>(b));
}

class Beschreibung :
	public MyDrawable
{
public:
	Beschreibung() { init("", DescFlags::none); };

	Beschreibung(std::string text, sf::Vector2f pos, DescFlags flags = DescFlags::none)
		:MyDrawable(pos)
	{
		init(text, flags);
	};

	Beschreibung(std::string text, float x, float y, DescFlags flags = DescFlags::none)
		:MyDrawable(sf::Vector2f(x, y))
	{
		init(text, flags);
	};

	~Beschreibung();

	void draw(sf::RenderWindow * window) override;


private:


	void init(std::string text, DescFlags flags);
	DescFlags flags;
	std::shared_ptr < sf::Font> fontDesc;
	sf::Text text;

};

