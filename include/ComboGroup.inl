	template<typename T>
	ComboGroup<T>::ComboGroup(sf::Window *parent) : m_parent(parent)
	{
		m_gap.x = 10.f;
		m_gap.y = 10.f;
		m_panel = Panel::create(parent);
		m_panel->setSize(0.f, 0.f);
	}

	template<typename T>
	ComboGroup<T>::~ComboGroup() { }

	template<typename T>
	typename ComboGroup<T>::Ptr ComboGroup<T>::create(sf::Window *parent)
	{
		return std::make_shared<ComboGroup<T>>(parent);
	}

	template<typename T>
	sf::Vector2f ComboGroup<T>::getPosition()
	{
		return m_position;
	}

	template<typename T>
	void ComboGroup<T>::setPosition(sf::Vector2f const& position)
	{
		m_position = position;
		m_panel->setPosition(position.x - m_gap.x, position.y - m_gap.y);
	}

	template<typename T>
	void ComboGroup<T>::setPosition(const float x, const float y)
	{
		setPosition(sf::Vector2f(x, y));
	}

	template<typename T>
	sf::Vector2f ComboGroup<T>::getGap()
	{
		return m_gap;
	}

	template<typename T>
	void ComboGroup<T>::setGap(sf::Vector2f const& gap)
	{
		m_gap = gap;
	}

	template<typename T>
	void ComboGroup<T>::setHGap(const float argHGap)
	{
		m_gap.x = argHGap;
	}

	template<typename T>
	void ComboGroup<T>::setVGap(const float argVGap)
	{
		m_gap.y = argVGap;
	}

	template<typename T>
	void ComboGroup<T>::setSelectedBox(T const& box)
	{
		m_selectedBox = box;
		for (auto const& el : m_box_map)
		{
			if (el.first != box)
			{
				el.second->desactivate();
			}
		}
	}

	template<typename T>
	void ComboGroup<T>::addComboBox(T const& id, sf::String const& text)
	{
		bool alreadyIn = false;
		for (auto const& el : m_box_map)
		{
			if (el.first == id)
			{
				alreadyIn = true;
			}
		}
		
		if (!alreadyIn)
		{
			ComboBox::Ptr buffer = ComboBox::create(m_parent, text);
			buffer->setPosition(m_position.x, m_position.y + (buffer->getSize().y + m_gap.y) * m_box_map.size());
			buffer->setActionOnClick(std::bind<void>([](ComboGroup* group, T const& argId) {
				group->setSelectedBox(argId);
			}, this, id));
			m_box_map[id] = std::move(buffer);

			float max = 0.f;

			for (auto const& el : m_box_map)
			{
				if (el.second->getSizeWithText().x > max)
				{
					max = el.second->getSizeWithText().x;
				}
			}

			m_panel->setSize(max + 2.f * m_gap.x, m_box_map.size() * ( m_box_map[id]->getSize().y + m_gap.y ) + m_gap.y);
		}
	}

	template<typename T>
	void ComboGroup<T>::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*m_panel, states);

		for (auto const& el : m_box_map)
		{
			target.draw(*(el.second), states);
		}
	}

	template<typename T>
	T const& ComboGroup<T>::getSelectedBoxId()
	{
		return m_selectedBox;
	}
