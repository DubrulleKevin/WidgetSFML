#include "TextField.h"


namespace wsf
{

	TextField::TextField(sf::Window *parent, sf::String const& text) : TextableWidget(parent, text)
	{
		setOutlineColor(sf::Color(0, 0, 0, 128));
		unfocus();
	}

	TextField::~TextField() { }

	TextField::Ptr TextField::create(sf::Window *parent, sf::String const& text)
	{
		return std::make_shared<TextField>(parent, text);
	}

	void TextField::handleAction(sf::Event const& event)
	{
		if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
		{
			if (contains(sf::Mouse::getPosition(*m_parent)))
			{
				focus();
                originalText = getText();
			}
			else
			{
				unfocus();
			}
		}
        else if (event.type == sf::Event::LostFocus ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			unfocus();
		}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            unfocus();
            setText(originalText);
        }

		if (m_focused && event.type == sf::Event::TextEntered)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !getText().empty())
			{
				std::string buf = getText();
				buf.pop_back();
				setText(buf);
			}
			else if ((event.text.unicode > 30 && (event.text.unicode < 128 || event.text.unicode > 159)) && getLocalTextSize().x < getSize().x)
			{
				setText(getText() + static_cast<char>(event.text.unicode));
			}
		}
	}

	void TextField::adaptTextPosition()
	{
		setTextPosition(getPosition().x, getPosition().y + getSize().y / 2.f - getLocalTextSize().y / 2.f);
	}

	void TextField::setText(sf::String const& text)
	{
		if (getLocalTextSize().x < getSize().x || text.getSize() < m_text.getString().getSize())
		{
			m_text.setString(text);
			adaptTextPosition();
		}
	}

	void TextField::focus()
	{
		m_focused = true;
		setBaseOutlineThickness(5);
	}

	void TextField::unfocus()
	{
		m_focused = false;
		setBaseOutlineThickness(2);
	}

}
