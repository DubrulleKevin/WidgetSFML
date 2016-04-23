    template<typename T>
    PickList<T>::PickList(sf::Window *parent) : AbstractWidget(parent)
    {
        setSize(150, 32);
        setFillColor(sf::Color::White);
		setOutlineColor(sf::Color(255, 0, 0, 128));
		setBaseOutlineThickness(2);
		setOutlineColor(sf::Color(255, 0, 0, 128));

		m_arrow.setPointCount(3);
		m_arrow.setRadius(getSize().y / ( /* 2 * sqrt(2) */ 2.828f ));
		m_arrow.setFillColor(sf::Color::Black);
		m_arrow.rotate(180);

		adaptArrowPosition();

		setActionOnClick([&](){ this->deploy(); });

		m_deployed = false;
    }

    template<typename T>
    PickList<T>::~PickList() { }

	template<typename T>
	typename PickList<T>::Ptr PickList<T>::create(sf::Window *parent)
	{
		return std::make_shared<PickList<T>>(parent);
	}

    template<typename T>
    void PickList<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        AbstractWidget::draw(target, states);

        if(!m_mapItems.empty())
        {
			if (!m_deployed)
			{
				target.draw(*m_mapButtons.at(m_selectedItem), states);
			}
			else
			{
				for (auto const& el : m_mapButtons)
				{
					target.draw(*el.second, states);
				}
			}
        }

		target.draw(m_arrow);
    }

	template<typename T>
	void PickList<T>::deploy()
	{
		float yPosCounter = getPosition().y;

		for (auto& el : m_mapButtons)
		{
			el.second->setPosition(el.second->getPosition().x, yPosCounter + el.second->getSize().y);
			yPosCounter += el.second->getSize().y;
			el.second->setInActivatedWidget(true);
		}

		m_deployed = true;
		m_zAxis += m_zAxis_deploy_increment;
	}

	template<typename T>
	void PickList<T>::unDeploy()
	{
		for (auto& el : m_mapButtons)
		{
			el.second->setPosition(getPosition());
			el.second->setInActivatedWidget(false);
		}

		m_deployed = false;
		m_zAxis -= m_zAxis_deploy_increment;
	}

    template<typename T>
    void PickList<T>::setPosition(sf::Vector2f const& position)
    {
        AbstractWidget::setPosition(position);

		for (auto& el : m_mapButtons)
		{
			el.second->setPosition(position);
		}

		adaptArrowPosition();
    }

    template<typename T>
    void PickList<T>::setPosition(const float x, const float y)
    {
        setPosition(sf::Vector2f(x, y));
    }

    template<typename T>
    void PickList<T>::addItem(std::string const& key, T* value)
    {
        if(m_mapItems.empty())
        {
            m_selectedItem = key;
        }
        m_mapItems.insert(std::pair<std::string, std::shared_ptr<T>>(key, std::move(std::shared_ptr<T>(value))));
		Button::Ptr buf = Button::create(m_parent, key);
		buf->setBaseOutlineThickness(0);
		buf->setActionOnClick(std::bind([]
            (PickList<T>* arg, std::string const& argKey)
            {
                arg->setSelectedItem(argKey);
				arg->unDeploy();
            }
            , this, key));
		m_mapButtons.insert(std::pair<std::string, Button::Ptr>(key, std::move(buf)));

		adjustSize();
    }

	template<typename T>
	void PickList<T>::handleAction(sf::Event const& event)
	{
		if (m_deployed)
		{
			for (auto& el : m_mapButtons)
			{
				el.second->handleAction(event);
			}
		}
		else if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.type == sf::Event::MouseButtonReleased)
			{
				setOutlineThickness(m_baseThickness);
				if (contains(sf::Mouse::getPosition(*m_parent)))
				{
                    actionOnClick();
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed && contains(sf::Mouse::getPosition(*m_parent)))
				setOutlineThickness(5);
		}
	}

	template<typename T>
	void PickList<T>::setSelectedItem(std::string const& key)
	{
		if (m_mapItems.count(key) > 0)
        {
            m_selectedItem = key;
        }
	}

	template<typename T>
	void PickList<T>::adjustSize()
	{
		float max = 0;

		for (auto const& el : m_mapButtons)
		{
			if (el.second->getSize().x > max)
			{
				max = el.second->getSize().x;
			}
		}

		for (auto& el : m_mapButtons)
		{
			el.second->setSize(max, el.second->getSize().y);
		}

		setSize(max, getSize().y);
	}

	template<typename T>
	std::shared_ptr<T> PickList<T>::getSelectedItem()
	{
		return m_mapItems.at(m_selectedItem);
	}

	template<typename T>
	std::shared_ptr<T> PickList<T>::getItem(std::string const& key)
	{
		return m_mapItems.at(key);
	}

	template<typename T>
	void PickList<T>::deleteItem(std::string const& key)
	{
		m_mapItems.erase(key);
		m_mapButtons.erase(key);

		if (m_selectedItem == key)
		{
			m_selectedItem = m_mapItems.begin()->first;
		}
	}

	template<typename T>
	void PickList<T>::adaptArrowPosition()
	{
		m_arrow.setPosition(getPosition().x + getSize().x,
							getPosition().y + ( ( getSize().y + m_arrow.getRadius() * 1.414f ) / 2 ) + 1 );
	}
