#pragma once

#include <vector>

#include "AbstractWidget.h"

namespace wsf
{

	class AbstractLayout
	{
	public:
		using Ptr = std::shared_ptr<AbstractLayout>;

		virtual void addWidget(AbstractWidget::Ptr widget);
		
		std::vector<AbstractWidget::Ptr> const& getWidgetList();

		void setGap(sf::Vector2f const& argGap);
		void setHGap(const float argHGap);
        void setVGap(const float argVGap);

		virtual void setPosition(sf::Vector2f const& position);
		virtual void setPosition(const float x, const float y);

		virtual void setSize(sf::Vector2f const& size);
		virtual void setSize(const float x, const float y);

		AbstractLayout();
		virtual ~AbstractLayout() = 0;

	protected:
		virtual void rearrange() = 0;

		std::vector<AbstractWidget::Ptr> m_widgetList;
		sf::Vector2f m_layeredPanelPosition;
		sf::Vector2f m_layeredPanelSize;
		sf::Vector2f m_gap;
	};

}
