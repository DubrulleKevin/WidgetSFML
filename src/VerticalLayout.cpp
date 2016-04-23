#include "VerticalLayout.h"

namespace wsf
{

	VerticalLayout::VerticalLayout() { }

	VerticalLayout::~VerticalLayout() { }

	VerticalLayout::Ptr VerticalLayout::create()
	{
		return std::make_shared<VerticalLayout>();
	}

	void VerticalLayout::rearrange()
	{
		int i = 0;

		for (auto& el : m_widgetList)
		{
			el->setSize(
				m_layeredPanelSize.x - 2 * m_gap.x,
				( m_layeredPanelSize.y - ( m_widgetList.size() + 1 ) * m_gap.y ) / m_widgetList.size()
				);

			el->setPosition(
				m_layeredPanelPosition.x + m_gap.x,
				( m_layeredPanelPosition.y + i * el->getSize().y ) + ( i + 1 ) * m_gap.y
				);
			i++;
		}
	}

}
