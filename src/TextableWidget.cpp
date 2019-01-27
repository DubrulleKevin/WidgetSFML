#include "TextableWidget.h"


namespace wsf
{

	TextableWidget::TextableWidget(sf::Window *parent, sf::String const& text) : AbstractWidget(parent)
	{
        setFont("../res/arial.ttf");
		setCharacterSize(18);
		setTextColor(sf::Color::Black);
        setText(text);
	}

	TextableWidget::~TextableWidget() {}

	void TextableWidget::setText(sf::String const& text)
	{
		m_text.setString(text);
		setSize(getTextSize() + sf::Vector2f(getTextSize().x * 0.5f, getTextSize().y * 0.5f));
		adaptTextPosition();
	}

	void TextableWidget::setTextPosition(sf::Vector2f const& position)
	{
        m_text.setPosition(position);
	}

	void TextableWidget::adaptTextPosition()
	{
		setTextPosition(getPosition().x + getSize().x / 2.f - getLocalTextSize().x / 2.f, getPosition().y + getSize().y / 2.f - getLocalTextSize().y / 2.f);
	}

	void TextableWidget::setTextPosition(const float x, const float y)
	{
		setTextPosition(sf::Vector2f(x, y));
	}

    void TextableWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        AbstractWidget::draw(target, states);

        target.draw(m_text, states);
	}

	void TextableWidget::setPosition(sf::Vector2f const& position)
	{
		AbstractWidget::setPosition(position);
		adaptTextPosition();
	}

	void TextableWidget::setPosition(const float x, const float y) 
	{ 
		setPosition(sf::Vector2f(x, y)); 
	}

	void TextableWidget::setTextColor(sf::Color const color)
	{ 
        m_text.setFillColor(color);
	}

	void TextableWidget::setFont(sf::String const& pathToFont)
	{
		m_font.loadFromFile(pathToFont);
        m_text.setFont(m_font);
	}

	void TextableWidget::setCharacterSize(const unsigned int size)
	{
        m_text.setCharacterSize(size);
	}

	void TextableWidget::setStyle(const sf::Uint32 style)
	{
        m_text.setStyle(style);
		adaptTextPosition();
	}

	sf::Vector2f TextableWidget::getTextSize()
	{
		return getLocalTextSize();
	}

	std::string TextableWidget::getText()
	{
		return m_text.getString().toAnsiString();
	}

    sf::Vector2f TextableWidget::getLocalTextSize() const
	{
		sf::String const& str = m_text.getString() + '\n';

		float maxLineWidth = 0.f;
		float lineWidth = 0.f;
		unsigned int lines = 0;

		for (sf::String::ConstIterator itr = str.begin(); itr != str.end(); ++itr)
		{
			if (*itr == '\n')
			{
				++lines;
				maxLineWidth = std::max(maxLineWidth, lineWidth);
				lineWidth = 0.f;
			}
			else
			{
				lineWidth += m_text.getFont()->getGlyph(*itr, m_text.getCharacterSize(), m_text.getStyle() & sf::Text::Bold).advance;
			}
		}

		const float lineHeight = static_cast<float>(m_text.getFont()->getLineSpacing(m_text.getCharacterSize()));
		return sf::Vector2f(maxLineWidth, lines * lineHeight);
	}

}
