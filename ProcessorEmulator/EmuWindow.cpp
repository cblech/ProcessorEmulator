#include "EmuWindow.h"
#include "SFML/Graphics.hpp"
#include <list>
#include "MyDrawable.h"
#include "GrHexAusgabe.h"
#include <thread>
#include <chrono>
#include "ProcessorEmulator.h"
#include "Beschreibung.h"
#define vec2f sf::Vector2f

EmuWindow::EmuWindow(WindowData * d)
{
	windowData = d;

	std::shared_ptr < sf::Font> fontSegment = std::make_shared < sf::Font>();
	std::shared_ptr < sf::Font> fontDescription = std::make_shared < sf::Font>();

	if (!fontSegment->loadFromFile("DSEG14Classic-Bold.ttf"))
		g::debug.error("DSEG Font failed to load!");

	if (!fontDescription->loadFromFile("Montserrat-Regular.ttf"))
		g::debug.error("Montserrat Font failed to load!");

	//RAM
	const vec2f ramPos = {105.f,105.f};

	ramBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	ramBorder.setOutlineColor(sf::Color::Black);
	ramBorder.setOutlineThickness(5.f);
	ramBorder.setPosition(ramPos);
	allDrawables.push_back(&ramBorder);

	ramAddress = GrHexAusgabe(ramPos+ vec2f(78.f, 2.f));
	auto ramAddressPointer = &ramAddress;
	allMyDrawables.push_back(ramAddressPointer);

	ramAddrDesc = Beschreibung("Addr:",ramPos+ vec2f( 45.f, 18.f));
	allMyDrawables.push_back(&ramAddrDesc);

	ramData = GrHexAusgabe(ramPos+ vec2f(78.f, 36.f));
	allMyDrawables.push_back(&ramData);

	ramDataDesc = Beschreibung("Data:", ramPos + vec2f(45.f, 52.f));
	allMyDrawables.push_back(&ramDataDesc);

	ramReadIndicator = GrSignalGetIndicator(ramPos + vec2f(5.f, 5.f),"RD",DescPos::Below);
	allMyDrawables.push_back(&ramReadIndicator);

	ramWriteIndicator = GrSignalGetIndicator(ramPos + vec2f(25.f, 5.f), "WR", DescPos::Below);
	allMyDrawables.push_back(&ramWriteIndicator);
	
	//end RAM

	//RECHENWERK
	const vec2f rechenwerkPos = { 495.f,305.f};

	rechenwerkBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	rechenwerkBorder.setOutlineColor(sf::Color::Black);
	rechenwerkBorder.setOutlineThickness(5.f);
	rechenwerkBorder.setPosition(rechenwerkPos);
	allDrawables.push_back(&rechenwerkBorder);

	rechenwerkAusgabe = GrHexAusgabe(rechenwerkPos+vec2f(40.f, 2.f));
	allMyDrawables.push_back(&rechenwerkAusgabe);

	rechenwerkReadIndicator = GrSignalGetIndicator(rechenwerkPos + vec2f(5.f, 55.f), "RD", DescPos::Above);
	allMyDrawables.push_back(&rechenwerkReadIndicator);

	rechenwerkWriteIndicator = GrSignalGetIndicator(rechenwerkPos + vec2f(25.f, 55.f), "WR", DescPos::Above);
	allMyDrawables.push_back(&rechenwerkWriteIndicator);


	//end RECHENWERK

	//IOEINGABE
	const vec2f eingabePos = { 300.f,105.f };

	eingabeBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	eingabeBorder.setOutlineColor(sf::Color::Black);
	eingabeBorder.setOutlineThickness(5.f);
	eingabeBorder.setPosition(eingabePos);
	allDrawables.push_back(&eingabeBorder);

	//end IOEINGABE

	//IOAUSGABE
	const vec2f ausgabePos = { 495.f,15.f };

	ausgabeBorder = sf::RectangleShape(vec2f(570.f, 160.f)); 
	ausgabeBorder.setOutlineColor(sf::Color::Black);
	ausgabeBorder.setOutlineThickness(5.f);
	ausgabeBorder.setPosition(ausgabePos);
	allDrawables.push_back(&ausgabeBorder);

	//end IOAUSGABE

	//REGISTER A
	const vec2f registAPos = { 105.f,305.f };

	registABorder = sf::RectangleShape(vec2f(180.f, 70.f));
	registABorder.setOutlineColor(sf::Color::Black);
	registABorder.setOutlineThickness(5.f);
	registABorder.setPosition(registAPos);
	allDrawables.push_back(&registABorder);

	//end REGISTER A

	//REGISTER B
	const vec2f registBPos = { 300.f,305.f };

	registBBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	registBBorder.setOutlineColor(sf::Color::Black);
	registBBorder.setOutlineThickness(5.f);
	registBBorder.setPosition(registBPos);
	allDrawables.push_back(&registBBorder);

	//end REGISTER B

	//INSTRUCTION COUNTER
	const vec2f instCountPos = { 690.f,305.f };

	instCountBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	instCountBorder.setOutlineColor(sf::Color::Black);
	instCountBorder.setOutlineThickness(5.f);
	instCountBorder.setPosition(instCountPos);
	allDrawables.push_back(&instCountBorder);

	//end INSTRUCTION COUNTER

	//INSTRUCTION REGISTER
	const vec2f instRegisterPos = { 885.f,305.f };

	instRegisterBorder = sf::RectangleShape(vec2f(180.f, 70.f));
	instRegisterBorder.setOutlineColor(sf::Color::Black);
	instRegisterBorder.setOutlineThickness(5.f);
	instRegisterBorder.setPosition(instRegisterPos);
	allDrawables.push_back(&instRegisterBorder);

	//end INSTRUCTION REGISTER

	//ADDRESS BUS
	addressBusRect1 = sf::RectangleShape(vec2f(820.f, 40.f));
	addressBusRect1.setFillColor(colorAddressBus);
	addressBusRect1.setPosition( 200.f, 195.f);
	allDrawables.push_back(&addressBusRect1);

	addressBusRect2 = sf::RectangleShape(vec2f(40.f, 120.f));
	addressBusRect2.setFillColor(colorAddressBus);
	addressBusRect2.setPosition(ramPos.x+95, 180.f);
	allDrawables.push_back(&addressBusRect2);

	addressBusRect3 = sf::RectangleShape(vec2f(40.f, 120.f));
	addressBusRect3.setFillColor(colorAddressBus);
	addressBusRect3.setPosition(eingabePos.x+95, 180.f);
	allDrawables.push_back(&addressBusRect3);

	addressBusRect4 = sf::RectangleShape(vec2f(40.f, 105.f));
	addressBusRect4.setFillColor(colorAddressBus);
	addressBusRect4.setPosition(rechenwerkPos.x + 95, 195.f);
	allDrawables.push_back(&addressBusRect4);

	addressBusRect5 = sf::RectangleShape(vec2f(40.f, 105.f));
	addressBusRect5.setFillColor(colorAddressBus);
	addressBusRect5.setPosition(instCountPos.x + 95, 195.f);
	allDrawables.push_back(&addressBusRect5);

	addressBusRect6 = sf::RectangleShape(vec2f(40.f, 15.f));
	addressBusRect6.setFillColor(colorAddressBus);
	addressBusRect6.setPosition(instRegisterPos.x + 95, 180.f);
	allDrawables.push_back(&addressBusRect6);

	addressBusAusgabe = GrHexAusgabe(vec2f(rechenwerkPos.x-25, 199.f));
	allMyDrawables.push_back(&addressBusAusgabe);
	//end ADDRESS BUSS

	//DATA BUS
	dataBusRect1 = sf::RectangleShape(vec2f(820.f, 40.f));
	dataBusRect1.setFillColor(colorDataBus);
	dataBusRect1.setPosition(150.f, 245.f);
	allDrawables.push_back(&dataBusRect1);

	dataBusRect2 = sf::RectangleShape(vec2f(40.f, 120.f));
	dataBusRect2.setFillColor(colorDataBus);
	dataBusRect2.setPosition(ramPos.x + 45, 180.f);
	allDrawables.push_back(&dataBusRect2);

	dataBusRect3 = sf::RectangleShape(vec2f(40.f, 120.f));
	dataBusRect3.setFillColor(colorDataBus);
	dataBusRect3.setPosition(eingabePos.x + 45, 180.f);
	allDrawables.push_back(&dataBusRect3);

	dataBusRect4 = sf::RectangleShape(vec2f(40.f, 15.f));
	dataBusRect4.setFillColor(colorDataBus);
	dataBusRect4.setPosition(rechenwerkPos.x + 45, 285.f);
	allDrawables.push_back(&dataBusRect4);

	dataBusRect5 = sf::RectangleShape(vec2f(40.f, 15.f));
	dataBusRect5.setFillColor(colorDataBus);
	dataBusRect5.setPosition(instCountPos.x + 45, 285.f);
	allDrawables.push_back(&dataBusRect5);

	dataBusRect6 = sf::RectangleShape(vec2f(40.f, 120.f));
	dataBusRect6.setFillColor(colorDataBus);
	dataBusRect6.setPosition(instRegisterPos.x + 45, 180.f);
	allDrawables.push_back(&dataBusRect6);

	dataBusAusgabe = GrHexAusgabe(vec2f(rechenwerkPos.x - 25, 249.f));
	allMyDrawables.push_back(&dataBusAusgabe);
	//end DATA BUSS
}

EmuWindow::~EmuWindow()
{
}



void EmuWindow::run()
{
#define windowWidth 1080
#define windowHeight 650

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Awesome Processor");

	sf::View defaultView(sf::FloatRect(0,0, windowWidth, windowHeight));

	window.setView(defaultView);

	while (window.isOpen())
	{
			ramAddress.setText(windowData->addressBus);
			ramData.setText(windowData->ram);
			dataBusAusgabe.setText(windowData->dataBus);
			addressBusAusgabe.setText(windowData->addressBus);
			rechenwerkAusgabe.setText(windowData->rechenwerk);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::Resized)
			{
				float relativeWidth=event.size.width / float (windowWidth);
				float relativeHeigth = event.size.height / float (windowHeight);
				
				bool widthIsBigger = relativeWidth > relativeHeigth;

				if (widthIsBigger)
				{
					defaultView.setSize((relativeWidth/relativeHeigth)*windowWidth,windowHeight);
				}
				else
				{
					defaultView.setSize(windowWidth, ( relativeHeigth/relativeWidth)*windowHeight);
				}
				window.setView(defaultView);

			}
		}
		window.clear(sf::Color::White);

		for (sf::Drawable * d : allDrawables)
		{
			window.draw(*d);
		}

		for (MyDrawable * d : allMyDrawables)
		{
			d->draw(&window);
		}

		window.display();
	}
}
