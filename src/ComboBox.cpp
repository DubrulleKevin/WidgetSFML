#include "ComboBox.h"


namespace wsf
{

    ComboBox::ComboBox(sf::Window *parent, sf::String const& text) : AbstractCheck(parent, text)
    {
        m_rect.setSize(sf::Vector2f(10.f, 10.f));
        m_rect.setFillColor(getColor());
    }

    ComboBox::~ComboBox() { }

	ComboBox::Ptr ComboBox::create(sf::Window *parent, sf::String const& text)
	{
		return std::make_shared<ComboBox>(parent, text);
	}

	sf::Vector2f ComboBox::getSizeWithText()
	{
		return getSize() + getTextSize() + sf::Vector2f(m_gap, 0.f);
	}

    void ComboBox::handleAction(sf::Event const& event)
    {
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{
				setOutlineThickness(2);

				if (contains(sf::Mouse::getPosition(*m_parent)))
				{
					m_rect.setFillColor(sf::Color::Black);
					m_checkActivated = true;
					actionOnClick();
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed && contains(sf::Mouse::getPosition(*m_parent)))
			{
				setOutlineThickness(5);
			}
		}
    }

    void ComboBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        AbstractCheck::draw(target, states);
        target.draw(m_rect, states);
    }

	void ComboBox::adaptCheckPosition()
	{
        m_rect.setPosition(getPosition().x + (getSize().x - m_rect.getSize().x ) / 2,
			getPosition().y + (getSize().y - m_rect.getSize().y) / 2);
	}

	const std::string ComboBox::getId()
	{
		return getText();
	}

	void ComboBox::desactivate()
	{
		m_checkActivated = false;
		m_rect.setFillColor(getColor());
	}
}
