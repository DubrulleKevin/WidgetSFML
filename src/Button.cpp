#include "Button.h"


namespace wsf
{

	Button::Button(sf::Window *parent, sf::String const& text) : TextableWidget(parent, text)
	{
		setFillColor(sf::Color::White);
		setBaseOutlineThickness(2);
		setOutlineColor(sf::Color(255, 0, 0, 128));
	}

	Button::~Button() { }

	Button::Ptr Button::create(sf::Window *parent, sf::String const& text)
	{
		return std::make_shared<Button>(parent, text);
	}

	void Button::handleAction(sf::Event const& event)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{
				setOutlineThickness(m_baseThickness);
				if (contains(sf::Mouse::getPosition(*m_parent)))
				{
                    actionOnClick();
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed && contains(sf::Mouse::getPosition(*m_parent)))
            {
                setOutlineThickness(5);
            }
		}
	}

}
