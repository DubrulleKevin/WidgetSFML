#pragma once

#include "AbstractWidget.h"


namespace wsf
{

	class WIDGETSFML_API TextableWidget :
		public AbstractWidget
	{
	public:
		using Ptr = std::shared_ptr<TextableWidget>;

		std::string getText();
		virtual void setText(sf::String const& text);

		void setTextPosition(sf::Vector2f const& position);
		void setTextPosition(const float x, const float y);

		void setTextColor(const sf::Color color);

		void setFont(sf::String const& pathToFont);

		void setCharacterSize(const unsigned int size);

		void setStyle(const sf::Uint32 style);

		virtual void setPosition(sf::Vector2f const& position);
		virtual void setPosition(const float x, const float y);

		sf::Vector2f getTextSize();

		TextableWidget(sf::Window *parent, sf::String const& text = "");
		virtual ~TextableWidget() = 0;

	protected:
        sf::Vector2f getLocalTextSize() const;

		virtual void adaptTextPosition();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Text m_text;

	private:
		sf::Font m_font;
	};

}
