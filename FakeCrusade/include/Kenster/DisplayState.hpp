#ifndef KENSTER_DisplayState_HPP
#define KENSTER_DisplayState_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include <Kenster/TextButton.hpp>

//one Display represent one Interfacestate. All States are global
namespace kenster
{
	class DisplayState : public sf::Drawable
	{
		public:
			DisplayState(const DisplayState&) = delete;
			DisplayState& operator=(const DisplayState&) = delete;

			DisplayState();
			~DisplayState();

			//replace TextButtion later with UIElements
			void attach( TextButton* textbutton);


			void processEvent(sf::Event& event);

		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
			//I want to use polymorphism for  holding the UI-Elements
			//std::vector<UIElement*> _elements;
			std::vector<TextButton*> _elements;
	};
}

#endif // !KENSTER_DisplayState_HPP
