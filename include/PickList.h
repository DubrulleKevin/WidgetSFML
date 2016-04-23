#ifndef PICKLIST_H
#define PICKLIST_H

#include <map>

#include "Button.h"


namespace wsf
{
    template<typename T>
    class PickList : 
		public AbstractWidget, public Clickable
    {
        public:
			using Ptr = std::shared_ptr<PickList<T>>;

			static Ptr create(sf::Window *parent);

            virtual void setPosition(sf::Vector2f const& position);
            virtual void setPosition(const float x, const float y);

            void addItem(std::string const& key, T* value = nullptr);
			void handleAction(sf::Event const& event);

			std::shared_ptr<T> getSelectedItem();
			std::shared_ptr<T> getItem(std::string const& key);

			void deleteItem(std::string const& key);

			PickList(sf::Window *parent);
			virtual ~PickList();

		private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
			void setSelectedItem(std::string const& key);
			void deploy();
			void unDeploy();
			void adjustSize();
			void adaptArrowPosition();

            std::map<std::string, std::shared_ptr<T>> m_mapItems;
			std::map<std::string, Button::Ptr> m_mapButtons;
            std::string m_selectedItem;
			bool m_deployed;
			sf::CircleShape m_arrow;
	};

    #include "PickList.inl"

}

#endif // PICKLIST_H
