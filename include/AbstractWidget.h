#pragma once

#include <memory>

#include "Drawable.h"


namespace wsf
{

	class WIDGETSFML_API AbstractWidget :
		public Drawable
	{
	public:

		using Ptr = std::shared_ptr<AbstractWidget>;

		sf::Vector2f getPosition();
		virtual void setPosition(sf::Vector2f const& position);
		virtual void setPosition(const float x, const float y);

		sf::Vector2f getSize();
		virtual void setSize(sf::Vector2f const& size);
		virtual void setSize(const float x, const float y);

		sf::FloatRect getBounds();

		void setOutlineThickness(const float thickness);

		void setBaseOutlineThickness(const float thickness);

		void setOutlineColor(const sf::Color color);

		void setFillColor(const sf::Color color);

		bool contains(sf::Vector2i const& point);

		sf::Color getColor();

		AbstractWidget(sf::Window *parent);
		virtual ~AbstractWidget() = 0;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		float m_baseThickness;

		sf::Window *m_parent;

	private:
		sf::RectangleShape m_shape;
	};

}
