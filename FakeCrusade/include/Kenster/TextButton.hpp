#ifndef KENSTER_TEXTBUTTON_HPP
#define KENSTER_TEXTBUTTON_HPP

#include <functional>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Kenster/UIElement.hpp>

namespace kenster
{
	class TextButton : public sf::Drawable, public UIElement
	{
		public:
			TextButton(const TextButton&) = delete;
			TextButton& operator=(const TextButton&) = delete;

			using FuncType = std::function<void()>;

			TextButton(const std::string title, const float posX, const float posY);

			void processEvent(sf::Event& event);


			FuncType _on_click;

		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

			sf::Text _text;
			sf::Font _font;
			sf::Color _color;
	};
}

#endif // !KENSTER_TEXTBUTTON_HPP
