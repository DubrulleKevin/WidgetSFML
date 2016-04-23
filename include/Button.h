#pragma once

#include "TextableWidget.h"
#include "Clickable.h"

namespace wsf
{

	class WIDGETSFML_API Button :
		public TextableWidget, public Clickable
	{
	public:
		using Ptr = std::shared_ptr<Button>;

		static Ptr create(sf::Window *parent, sf::String const& text = "Button");

		virtual void handleAction(sf::Event const& event);

		Button(sf::Window *parent, sf::String const& text = "Button");
		virtual ~Button();
	};

}