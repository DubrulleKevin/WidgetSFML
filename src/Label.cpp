#include "Label.h"


namespace wsf
{

	Label::Label(sf::Window *parent, sf::String const& text) : TextableWidget(parent, text)
	{
		setFillColor(sf::Color(0, 0 ,0, 0));
	}

	Label::~Label() {}

	Label::Ptr Label::create(sf::Window *parent, sf::String const& text)
	{
		return std::make_shared<Label>(parent, text);
	}

	void Label::adaptTextPosition()
	{
		setTextPosition(getPosition().x + getSize().x / 2 - getLocalTextSize().x / 2, getPosition().y + getSize().y / 2 - getLocalTextSize().y / 2);
	}

}