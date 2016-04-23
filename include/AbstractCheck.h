#pragma once

#include "TextableWidget.h"
#include "Clickable.h"


namespace wsf
{

	class WIDGETSFML_API AbstractCheck :
		public TextableWidget, public Clickable
	{
	public:
		AbstractCheck(sf::Window *parent, sf::String const& text = "");

		virtual void setPosition(sf::Vector2f const& position);
		virtual void setPosition(const float x, const float y);

		bool isCheckActivated();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void adaptTextPosition();
		virtual void adaptCheckPosition() = 0;

		bool m_checkActivated;
		float m_gap;
	};

}