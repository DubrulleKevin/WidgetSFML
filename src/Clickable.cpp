#include "Clickable.h"


namespace wsf
{

	std::vector<Clickable*> Clickable::m_instanciatedClickables;

	Clickable::Clickable() : m_activated(true), m_inActivatedWidget(false)
	{
		m_instanciatedClickables.push_back(this);

	    m_onClick = [](){};
	}

	Clickable::~Clickable() 
	{
		auto it = m_instanciatedClickables.begin();

		while(it != m_instanciatedClickables.end())
		{
			if (*it == this)
			{
				it = m_instanciatedClickables.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	void Clickable::setActionOnClick(std::function<void()> const& action)
	{
		m_onClick = action;
	}

	void Clickable::actionOnClick()
	{
		if (isActivated())
		{
			m_onClick();
		}
	}

	void Clickable::updateBy(sf::Event const& event)
	{
		for (auto el : m_instanciatedClickables)
		{
			if (el->isActivated())
			{
				el->handleAction(event);
			}
		}
	}

	void Clickable::setActivated(bool arg)
	{
		m_activated = arg;
	}

	bool Clickable::isActivated()
	{
		return m_activated;
	}

	void Clickable::setInActivatedWidget(bool arg)
	{
		m_inActivatedWidget = arg;
	}

	bool Clickable::isInActivatedWidget()
	{
		return m_inActivatedWidget;
	}

}
