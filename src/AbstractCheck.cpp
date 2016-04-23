#include "AbstractCheck.h"


namespace wsf
{

	AbstractCheck::AbstractCheck(sf::Window *parent, sf::String const& text) : TextableWidget(parent, text)
	{
		setSize(20, 20);

		setOutlineColor(sf::Color(255, 0, 0, 128));
		setOutlineThickness(2);

		m_checkActivated = false;
		m_gap = 10.f;
	}

	void AbstractCheck::adaptTextPosition()
	{
		setTextPosition(getPosition() + sf::Vector2f(getSize().x + m_gap, getSize().y / 2 - getLocalTextSize().y / 2));
	}

	void AbstractCheck::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		TextableWidget::draw(target, states);
	}

	void AbstractCheck::setPosition(sf::Vector2f const& position)
	{
		TextableWidget::setPosition(position);
		adaptCheckPosition();
	}

	void AbstractCheck::setPosition(float x, float y)
	{
		setPosition(sf::Vector2f(x, y));
	}

	bool AbstractCheck::isCheckActivated()
	{ 
		return m_checkActivated;
	}

}