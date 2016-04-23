#pragma once

#include "TextableWidget.h"


namespace wsf
{

	class Label :
		public wsf::TextableWidget
	{
	public:
		
		using Ptr = std::shared_ptr<Label>;

		static Ptr create(sf::Window *parent, sf::String const& text);

		Label(sf::Window *parent, sf::String const& text = "");
		virtual ~Label();

	protected:
		virtual void adaptTextPosition();
	};

}