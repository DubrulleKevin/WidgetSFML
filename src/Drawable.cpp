#include "Drawable.h"

namespace wsf
{

	std::vector<Drawable*> Drawable::m_instanciatedDrawables;

	Drawable::Drawable() : m_zAxis(0)
	{
		m_instanciatedDrawables.push_back(this);
	}

	Drawable::~Drawable()
	{
		auto it = m_instanciatedDrawables.begin();

		while (it != m_instanciatedDrawables.end())
		{
			if (*it == this)
			{
				it = m_instanciatedDrawables.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	void Drawable::drawBy(sf::RenderWindow* window)
	{
		std::sort(m_instanciatedDrawables.begin(), m_instanciatedDrawables.end(), [](Drawable* left, Drawable* right)
        {
			return (left->getZAxis() < right->getZAxis());
		});

		std::vector<Clickable*> clickableList;
		std::vector<Drawable*> clickableDrawableList;

		for (auto el : m_instanciatedDrawables)
		{
			Clickable* clickable = dynamic_cast<Clickable*>(el);
			if (clickable)
			{
				clickableList.push_back(clickable);
				clickableDrawableList.push_back(el);
			}
		}

		if (clickableDrawableList.size() > 1)
		{
			if (clickableDrawableList.at(clickableDrawableList.size() - 1)->getZAxis() >
				clickableDrawableList.at(clickableDrawableList.size() - 2)->getZAxis())
			{
				if (clickableList.at(0)->isActivated())
				{
					for (auto el : clickableList)
					{
						if (!el->isInActivatedWidget())
						{
							el->setActivated(false);
						}
					}

					clickableList.at(clickableList.size() - 1)->setActivated(true);
				}
			}
			else if(!clickableList.at(0)->isActivated())
			{
				for (auto el : clickableList)
				{
					el->setActivated(true);
				}
			}
		}

		for (auto const& el : m_instanciatedDrawables)
		{
			window->draw(*el);
		}
	}

	int Drawable::getZAxis() const
	{
		return m_zAxis;
	}

}
