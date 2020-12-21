#include <Kenster/DisplayState.hpp>

namespace kenster
{
	DisplayState::DisplayState()
	{

	}

	DisplayState::~DisplayState()
	{
		for (TextButton* element : _elements)
			delete element;
	}

	void DisplayState::attach( TextButton* textButton)
	{
		_elements.emplace_back(textButton);
	}

	void DisplayState::processEvent(sf::Event& event)
	{
		for (TextButton* element : _elements)
		{
			element->processEvent(event);
		}
	}

	void DisplayState::draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		/*for (auto it_i = _elements.begin(); it_i != _elements.end(); it_i++)
			target.draw(*it_i, states);*/
		for (TextButton* element : _elements)
			target.draw(*element, states);
	}
}