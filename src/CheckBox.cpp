#include "CheckBox.h"


namespace wsf
{

	CheckBox::CheckBox(sf::Window *parent, sf::String const& text) : AbstractCheck(parent, text)
	{
		m_line1.setSize(sf::Vector2f(sqrt(getSize().x * getSize().x + getSize().y * getSize().y), 2));
		m_line2.setSize(m_line1.getSize());
		m_line1.rotate(45);
		m_line2.rotate(-45);
		m_line1.setFillColor(getColor());
		m_line2.setFillColor(getColor());
		m_line2.setPosition(0, getSize().y);
	}

	CheckBox::~CheckBox() { }

	CheckBox::Ptr CheckBox::create(sf::Window *parent, sf::String const& text)
	{
		return std::make_shared<CheckBox>(parent, text);
	}

	void CheckBox::handleAction(sf::Event const& event)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{
				setOutlineThickness(2);

				if (contains(sf::Mouse::getPosition(*m_parent)))
				{
					if (m_checkActivated)
					{
						m_line1.setFillColor(getColor());
						m_line2.setFillColor(getColor());
						m_checkActivated = false;
					}
					else
					{
						m_line1.setFillColor(sf::Color::Black);
						m_line2.setFillColor(sf::Color::Black);
						m_checkActivated = true;
					}

                    actionOnClick();
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed && contains(sf::Mouse::getPosition(*m_parent)))
			{
				setOutlineThickness(5);
			}
		}
	}

	void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		AbstractCheck::draw(target, states);
		target.draw(m_line1, states);
		target.draw(m_line2, states);
	}

	void CheckBox::adaptCheckPosition()
	{
		m_line1.setPosition(getPosition());
		m_line2.setPosition(getPosition().x, getPosition().y  + getSize().y);
	}

}
