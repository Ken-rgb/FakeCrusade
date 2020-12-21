#include "Kenster/TextButton.hpp"

#include <SFML/Graphics/RenderTarget.hpp> // for datatype sf::RenderTarget
#include <SFML/Window/Mouse.hpp>

#ifdef KENSTER_DEBUG
#include <iostream>
#endif // KENSTER_DEBUG

#include <SFML/Window/Event.hpp>

namespace kenster
{
	TextButton::TextButton(const std::string title, const float posX, const float posY)
	{
#ifdef KENSTER_DEBUG
		if (!_font.loadFromFile("media/font/trs-million.ttf"))
			std::cout << "couldn't load font file" << std::endl;
#else
		_font.loadFromFile("media/font/trs-million.ttf");
#endif
		_color = sf::Color(135, 168, 172);

		_text.setFont(_font);
		_text.setString(title);
		_text.setCharacterSize(30);
		_text.setPosition(posX, posY);
		_text.setFillColor(_color);

	}

	void TextButton::processEvent(sf::Event& event)
	{
		const sf::Vector2f mouse_pos(event.mouseMove.x, event.mouseMove.y);
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (event.key.code == sf::Mouse::Left)
				if (_text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					_on_click(); // replace this with some function that can use, once you use connect
				}
			break;
		case sf::Event::MouseMoved:
			float light;
			if (_text.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
			{
				light = 1.4;
				_text.setFillColor(sf::Color(_color.r*light, _color.g *light, _color.b * light));
			}
			else
			{
				light = 1;
				_text.setFillColor(sf::Color(_color.r*light, _color.g *light, _color.b * light));
			}
			break;
		}


	}

	void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		target.draw(_text, states);
	}
}