#pragma once
#include "TextableWidget.h"
#include "Clickable.h"


namespace wsf
{

	class WIDGETSFML_API TextField :
		public TextableWidget, public Clickable
	{
	public:
		using Ptr = std::shared_ptr<TextField>;

		static Ptr create(sf::Window *parent, sf::String const& text = "");

		virtual void setText(sf::String const& text);

		virtual void handleAction(sf::Event const& event);

		TextField(sf::Window *parent, sf::String const& text = "");
		~TextField();

	private:
		virtual void adaptTextPosition();
		void focus();
		void unfocus();

		bool m_focused;
	};

}
