#include "Button.h"
#include "Label.h"
#include "CheckBox.h"
#include "PickList.h"
#include "TextField.h"
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "GridLayout.h"
#include "Panel.h"
#include "ComboGroup.h"


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test WidgetSFML", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	sf::Image icon;
	icon.loadFromFile("../res/icon.png");

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::RectangleShape background(sf::Vector2f(window.getSize()));
	background.setFillColor(sf::Color(200, 200, 200));

	wsf::Button::Ptr testBouton = wsf::Button::create(&window, "Quitter");
	testBouton->setActionOnClick([&]()
	{
		window.close();
	});
	testBouton->setPosition(250, 250);

	wsf::Label::Ptr testLabel = wsf::Label::create(&window, "Test Label");
	testLabel->setPosition(150, 100);

	wsf::CheckBox::Ptr testCheckBox = wsf::CheckBox::create(&window, "Test CheckBox");
	testCheckBox->setActionOnClick([&]()
	{
		if (testCheckBox->isCheckActivated())
		{
			window.setTitle("Coche");
		}
		else
		{
			window.setTitle("Pas coche");
		}
	});
	testCheckBox->setPosition(20, 150);

	wsf::PickList<std::string>::Ptr testList = wsf::PickList<std::string>::create(&window);
	testList->addItem("Test1", new std::string("Coucou"));
	testList->addItem("Bonjour, ceci est un test a la con !", new std::string("Coucou"));
	testList->setPosition(200, 30);

	wsf::TextField::Ptr testField = wsf::TextField::create(&window, "Test Field");
	testField->setPosition(200, 200);

	wsf::Panel::Ptr testPanel = wsf::Panel::create(&window);
	testPanel->setPosition(450, 400);
	testPanel->setSize(300, 150);

	wsf::Button::Ptr testBouton1 = wsf::Button::create(&window, "Test 1");
	wsf::Button::Ptr testBouton2 = wsf::Button::create(&window, "Test 1");
	wsf::Button::Ptr testBouton3 = wsf::Button::create(&window, "Test 1");
	wsf::Button::Ptr testBouton4 = wsf::Button::create(&window, "Test 1");

	testPanel->setLayout(wsf::VerticalLayout::create(), sf::Vector2f(10, 10));

	testPanel->addWidget(testBouton1);
	testPanel->addWidget(testBouton2);
	testPanel->addWidget(testBouton3);
	testPanel->addWidget(testBouton4);

	wsf::Panel::Ptr testPanelH = wsf::Panel::create(&window);
	testPanelH->setPosition(450, 100);
	testPanelH->setSize(300, 150);

	wsf::Button::Ptr testBoutonH1 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonH2 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonH3 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonH4 = wsf::Button::create(&window, "Test");

	testPanelH->setLayout(wsf::HorizontalLayout::create(), sf::Vector2f(10, 10));

	testPanelH->addWidget(testBoutonH1);
	testPanelH->addWidget(testBoutonH2);
	testPanelH->addWidget(testBoutonH3);
	testPanelH->addWidget(testBoutonH4);

	wsf::Panel::Ptr testPanelG = wsf::Panel::create(&window);
	testPanelG->setPosition(50, 400);
	testPanelG->setSize(300, 150);

	wsf::Button::Ptr testBoutonG1 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonG2 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonG3 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonG4 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonG5 = wsf::Button::create(&window, "Test");
	wsf::Button::Ptr testBoutonG6 = wsf::Button::create(&window, "Test");

	testPanelG->setLayout(wsf::GridLayout::create(2, 3), sf::Vector2f(10, 10));

	testPanelG->addWidget(testBoutonG1);
	testPanelG->addWidget(testBoutonG2);
	testPanelG->addWidget(testBoutonG3);
	testPanelG->addWidget(testBoutonG4);
	testPanelG->addWidget(testBoutonG5);
	testPanelG->addWidget(testBoutonG6);

	wsf::ComboGroup<int>::Ptr combogroup = wsf::ComboGroup<int>::create(&window);
	combogroup->setPosition(20, 20);
	combogroup->addComboBox(0, "Test 1");
	combogroup->addComboBox(1, "Test 2");
	combogroup->addComboBox(2, "Test 3");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			wsf::Clickable::updateBy(event);
		}

		window.clear();

		window.draw(background);
		wsf::Drawable::drawBy(&window);

		window.display();
	}

	return 0;
}
