#include "GridLayout.h"


namespace wsf
{

    GridLayout::GridLayout(const unsigned int argRows, const unsigned int argCols) :
        rows(argRows == 0 ? 1 : argRows), cols(argCols == 0 ? 1 : argCols)
    {

    }

    GridLayout::~GridLayout() { }

	GridLayout::Ptr GridLayout::create(const unsigned int argRows, const unsigned int argCols)
	{
		return std::make_shared<GridLayout>(argRows, argCols);
	}

    void GridLayout::rearrange()
    {
        unsigned int i = 0;

        for (auto& el : m_widgetList)
		{
            el->setSize(
				( m_layeredPanelSize.x - ( cols + 1 ) * m_gap.x ) / cols,
				( m_layeredPanelSize.y - ( rows + 1 ) * m_gap.y ) / rows
            );

			el->setPosition(
				m_layeredPanelPosition.x + ( ( i % cols ) + 1 ) * m_gap.x + ( ( i % cols ) * el->getSize().x ),
				( m_layeredPanelPosition.y + ( i / cols ) * el->getSize().y ) + ( ( i / cols ) + 1 ) * m_gap.y
            );

			i++;
		}
    }

    void GridLayout::addWidget(AbstractWidget::Ptr widget)
    {
        if (m_widgetList.size() < cols * rows)
        {
            AbstractLayout::addWidget(widget);
        }
    }
}
