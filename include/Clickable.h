#pragma once

#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>

#include "config.h"


namespace wsf
{

	class WIDGETSFML_API Clickable
	{
	public:
		void setActionOnClick(std::function<void()> const& action);
		void actionOnClick();
		static void updateBy(sf::Event const& event);
		void setActivated(bool arg);
		bool isActivated();
		void setInActivatedWidget(bool arg);
		bool isInActivatedWidget();

		Clickable();
		virtual ~Clickable() = 0;

	protected:
		virtual void handleAction(sf::Event const& event) = 0;

	private:
		std::function<void()> m_onClick;
		static std::vector<Clickable*> m_instanciatedClickables;
		bool m_activated;
		bool m_inActivatedWidget;
	};

}