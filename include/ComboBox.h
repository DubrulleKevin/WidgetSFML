#ifndef HEADER_COMBOBOX
#define HEADER_COMBOBOX

#include "AbstractCheck.h"


namespace wsf
{

    class ComboBox
        : public AbstractCheck
    {
    public:
        
		using Ptr = std::shared_ptr<ComboBox>;

		static Ptr create(sf::Window *parent, sf::String const& text = "");

		sf::Vector2f getSizeWithText();

		virtual void handleAction(sf::Event const& event);
		
		void desactivate();

		const std::string getId();

		ComboBox(sf::Window *parent, sf::String const& text = "");
		virtual ~ComboBox();

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void adaptCheckPosition();

		sf::RectangleShape m_rect;
    };
	
}

#endif
