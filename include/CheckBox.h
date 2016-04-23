#pragma once

#include "AbstractCheck.h"

#include <math.h>


namespace wsf
{

	class WIDGETSFML_API CheckBox :
		public AbstractCheck
	{
	public:
		using Ptr = std::shared_ptr<CheckBox>;

		static Ptr create(sf::Window *parent, sf::String const& text = "");

		virtual void handleAction(sf::Event const& event);

		CheckBox(sf::Window *parent, sf::String const& text = "");
		virtual ~CheckBox();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void adaptCheckPosition();

		sf::RectangleShape m_line1;
		sf::RectangleShape m_line2;
	};

}
