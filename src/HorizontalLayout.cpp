#include "HorizontalLayout.h"

namespace wsf
{

    HorizontalLayout::HorizontalLayout() { }

    HorizontalLayout::~HorizontalLayout() { }

	HorizontalLayout::Ptr HorizontalLayout::create()
	{
		return std::make_shared<HorizontalLayout>();
	}

    void HorizontalLayout::rearrange()
    {
        int i = 0;

		for (auto& el : m_widgetList)
		{
			el->setSize(
				( m_layeredPanelSize.x - ( m_widgetList.size() + 1 ) * m_gap.x ) / m_widgetList.size(),
				m_layeredPanelSize.y - 2 * m_gap.y
				);

			el->setPosition(
				( m_layeredPanelPosition.x + i * el->getSize().x ) + ( i + 1 ) * m_gap.x,
				m_layeredPanelPosition.y + m_gap.y
				);
			i++;
		}
    }

}
