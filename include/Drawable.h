#pragma once

#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "Clickable.h"

namespace wsf
{

	class WIDGETSFML_API Drawable :
		public sf::Drawable
	{
	public:
		Drawable();
		virtual ~Drawable();

		static void drawBy(sf::RenderWindow* window);

		int getZAxis() const;

	protected:
		static std::vector<Drawable*> m_instanciatedDrawables;

		int m_zAxis;
		const int m_zAxis_deploy_increment = 1;
	};

}
