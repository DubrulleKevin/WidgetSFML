#ifndef HEADER_COMBOGROUP
#define HEADER_COMBOGROUP

#include <vector>
#include "Panel.h"
#include "ComboBox.h"

namespace wsf
{
	template<typename T>
	class WIDGETSFML_API ComboGroup :
		public Drawable
	{
	public:
		
		using Ptr = std::shared_ptr<ComboGroup<T>>;

		static Ptr create(sf::Window *parent);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f const& position);
		void setPosition(const float x, const float y);

		sf::Vector2f getGap();
		void setGap(sf::Vector2f const& gap);
		void setHGap(const float argHGap);
		void setVGap(const float argVGap);

		void addComboBox(T const& id, sf::String const& text = "");

		void setSelectedBox(T const& box);

		T const& getSelectedBoxId();

		ComboGroup(sf::Window *parent);
		virtual ~ComboGroup();

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		std::map<T, ComboBox::Ptr> m_box_map;
		sf::Window *m_parent;
		sf::Vector2f m_position;
		sf::Vector2f m_gap;
		T m_selectedBox;
		Panel::Ptr m_panel;
	};

	#include "ComboGroup.inl"

}

#endif
