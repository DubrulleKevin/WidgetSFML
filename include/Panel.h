#pragma once

#include "AbstractWidget.h"
#include "VerticalLayout.h"

namespace wsf
{

	class WIDGETSFML_API Panel :
		public AbstractWidget
	{
	public:
		using Ptr = std::shared_ptr<Panel>;

		static Ptr create(sf::Window *parent);
		
		AbstractLayout::Ptr getLayout();
		void setLayout(AbstractLayout::Ptr argLayout, sf::Vector2f const& gap = sf::Vector2f(0.f, 0.f));

		void addWidget(AbstractWidget::Ptr widget);

		virtual void setPosition(sf::Vector2f const& position);
		virtual void setPosition(const float x, const float y);

		Panel(sf::Window *parent);
		virtual ~Panel();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		AbstractLayout::Ptr m_layout;
	};

}