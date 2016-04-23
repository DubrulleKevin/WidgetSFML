#include "Panel.h"

namespace wsf 
{

	Panel::Panel(sf::Window *parent) : AbstractWidget(parent)
	{
		setFillColor(sf::Color::White);
		setSize(200, 100);
		setOutlineThickness(2);
		setOutlineColor(sf::Color::Black);
		m_layout = VerticalLayout::create();
		m_layout->setPosition(getPosition());
		m_layout->setSize(getSize());
	}

	Panel::~Panel() { }

	Panel::Ptr Panel::create(sf::Window *parent)
	{
		return std::make_shared<Panel>(parent);
	}

	AbstractLayout::Ptr Panel::getLayout()
	{
		return m_layout;
	}

	void Panel::setLayout(AbstractLayout::Ptr argLayout, sf::Vector2f const& gap)
	{
		m_layout = argLayout;
		m_layout->setGap(gap);
		m_layout->setPosition(getPosition());
		m_layout->setSize(getSize());
	}

	void Panel::addWidget(AbstractWidget::Ptr widget)
	{
		m_layout->addWidget(widget);
	}

	void Panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		AbstractWidget::draw(target, states);

		for (auto& el : m_layout->getWidgetList())
		{
			target.draw(*el, states);
		}
	}

	void Panel::setPosition(sf::Vector2f const& position)
	{
		AbstractWidget::setPosition(position);
		m_layout->setPosition(position);
	}

	void Panel::setPosition(const float x, const float y)
	{
		setPosition(sf::Vector2f(x, y));
	}

}
