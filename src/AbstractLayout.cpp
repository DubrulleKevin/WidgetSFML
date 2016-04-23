#include "AbstractLayout.h"

namespace wsf
{

	AbstractLayout::AbstractLayout() { }

	AbstractLayout::~AbstractLayout() { }

	void AbstractLayout::addWidget(AbstractWidget::Ptr widget)
	{
		m_widgetList.push_back(widget);
		rearrange();
	}

	std::vector<AbstractWidget::Ptr> const& AbstractLayout::getWidgetList()
	{
		return m_widgetList;
	}

	void AbstractLayout::setGap(sf::Vector2f const& argGap)
	{
        m_gap = argGap;
	}

    void AbstractLayout::setHGap(const float argHGap)
    {
        m_gap.x = argHGap;
    }

    void AbstractLayout::setVGap(const float argVGap)
    {
        m_gap.y = argVGap;
    }

	void AbstractLayout::setPosition(sf::Vector2f const& position)
	{
		m_layeredPanelPosition = position;

		rearrange();
	}

	void AbstractLayout::setPosition(const float x, const float y)
	{
		setPosition(sf::Vector2f(x, y));
	}

	void AbstractLayout::setSize(sf::Vector2f const& size)
	{
		m_layeredPanelSize = size;

		rearrange();
	}

	void AbstractLayout::setSize(const float x, const float y)
	{
		setSize(sf::Vector2f(x, y));
	}

}
