#include "AbstractWidget.h"


namespace wsf
{
	AbstractWidget::AbstractWidget(sf::Window *parent) : m_parent(parent) { }

	AbstractWidget::~AbstractWidget() {}

	sf::Vector2f AbstractWidget::getPosition()
	{ 
		return m_shape.getPosition(); 
	}

	sf::Vector2f AbstractWidget::getSize()
	{ 
		return m_shape.getSize(); 
	}

	void AbstractWidget::setSize(sf::Vector2f const& size)
	{ 
		m_shape.setSize(size); 
	}

	sf::FloatRect AbstractWidget::getBounds()
	{
		return m_shape.getGlobalBounds(); 
	}

	void AbstractWidget::setOutlineThickness(const float thickness)
	{
		m_shape.setOutlineThickness(thickness);
	}

	void AbstractWidget::setFillColor(const sf::Color color)
	{
		m_shape.setFillColor(color);
	}

	void AbstractWidget::setOutlineColor(const sf::Color color)
	{
		m_shape.setOutlineColor(color);
	}

	void AbstractWidget::setBaseOutlineThickness(const float thickness)
	{
		m_baseThickness = thickness;
		setOutlineThickness(thickness);
	}

	void AbstractWidget::setSize(const float x, const float y)
	{
		setSize(sf::Vector2f(x, y)); 
	}

	void AbstractWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_shape, states);
	}

	void AbstractWidget::setPosition(sf::Vector2f const& position){ m_shape.setPosition(position); }

	void AbstractWidget::setPosition(const float x, const float y) { m_shape.setPosition(sf::Vector2f(x, y)); }

	bool AbstractWidget::contains(sf::Vector2i const& point)
	{
		if (point.x > getPosition().x && point.x < getPosition().x + getSize().x && 
			point.y > getPosition().y && point.y < getPosition().y + getSize().y)
		{
			return true;
		}

		return false;
	}

	sf::Color AbstractWidget::getColor()
	{
		return m_shape.getFillColor();
	}

}
