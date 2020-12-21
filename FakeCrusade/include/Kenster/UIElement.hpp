#ifndef KENSTER_UIELEMENT_HPP
#define KENSTER_UIELEMENT_HPP

#include <SFML/Graphics.hpp>

namespace kenster
{
	class UIElement 
	{
		public:
			UIElement(const UIElement&) = delete;
			UIElement& operator=(const UIElement&) = delete;

			UIElement() = default;

			void processEvent(sf::Event& event);
			void update();

			bool isHovered(sf::Event& event)const;

		private:
			

	};
}

#endif // !KENSTER_UIELEMENT_HPP

