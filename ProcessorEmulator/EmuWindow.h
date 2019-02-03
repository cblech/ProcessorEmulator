#pragma once
#include "SFML\Graphics.hpp"
#include <list>
#include "MyDrawable.h"
#include "GrHexAusgabe.h"
#include "Beschreibung.h"
#include "GrSignalGetIndicator.h"

struct WindowData {
	unsigned short addressBus;
	unsigned short dataBus;
	unsigned short ram;
	unsigned short rechenwerk;
};

class EmuWindow
{
public:
	EmuWindow(WindowData * d);
	~EmuWindow();

	void run();

private:
	WindowData * windowData;

	std::list<sf::Drawable *> allDrawables;
	std::list<MyDrawable *> allMyDrawables;

	///////////////////////
	//RAM
	sf::RectangleShape ramBorder;

	GrHexAusgabe ramAddress;
	GrHexAusgabe ramData;

	Beschreibung ramDataDesc;
	Beschreibung ramAddrDesc;

	GrSignalGetIndicator ramReadIndicator;
	GrSignalGetIndicator ramWriteIndicator;

	//END RAM
	////////////////////////

	////////////////////////
	//RECHENWERK

	sf::RectangleShape rechenwerkBorder;
	GrHexAusgabe rechenwerkAusgabe;

	GrSignalGetIndicator rechenwerkReadIndicator;
	GrSignalGetIndicator rechenwerkWriteIndicator;

	//END RECHENWERK
	////////////////////////

	////////////////////////
	//IOEINGABE

	sf::RectangleShape eingabeBorder;

	//END IOEINGABE
	////////////////////////

	////////////////////////
	//IOAUSGABE

	sf::RectangleShape ausgabeBorder;

	//END IOAUSGABE
	////////////////////////

	////////////////////////
	//REGISTER A

	sf::RectangleShape registABorder;

	//END REGISTER A
	////////////////////////

	////////////////////////
	//REGISTER B

	sf::RectangleShape registBBorder;

	//END REGISTER B
	////////////////////////

	////////////////////////
	//INSTRUCTION COUNTER

	sf::RectangleShape instCountBorder;

	//END INSTRUCTION COUNTER
	////////////////////////

	////////////////////////
	//INSTRUCTION REGISTER
	sf::RectangleShape instRegisterBorder;

	//END INSTRUCTION REGISTER
	////////////////////////

	////////////////////////
	//ADDRESS BUS
	sf::RectangleShape addressBusRect1;
	sf::RectangleShape addressBusRect2;
	sf::RectangleShape addressBusRect3;
	sf::RectangleShape addressBusRect4;
	sf::RectangleShape addressBusRect5;
	sf::RectangleShape addressBusRect6;

	GrHexAusgabe addressBusAusgabe;

	//END ADDRESS BUS
	////////////////////////

	////////////////////////
	//DATA BUS
	sf::RectangleShape dataBusRect1;
	sf::RectangleShape dataBusRect2;
	sf::RectangleShape dataBusRect3;
	sf::RectangleShape dataBusRect4;
	sf::RectangleShape dataBusRect5;
	sf::RectangleShape dataBusRect6;

	GrHexAusgabe dataBusAusgabe;

	//END DATA BUS
	////////////////////////
};


