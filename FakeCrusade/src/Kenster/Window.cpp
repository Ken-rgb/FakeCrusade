#include <Kenster/Window.hpp>
#include <Kenster/Setting.hpp>
#include <iostream>

namespace kenster
{
	Window::Window(const std::string& title) :
		_window(sf::VideoMode(setting::resolutionX, setting::resolutionY), title),
		_status(Status::StatusMenu),
		_gameworld(_window)
	{

		//create UI for menu
		TextButton* start_button = new TextButton("Start", 100.f, 300.f);
		start_button->_on_click = [this]() {
			std::cout << "start ullulu\n";
			_status = Status::StatusGameworld;
		};
		TextButton* exit_button = new TextButton("Exit", 100.f, 400.f);
		exit_button->_on_click = [this]() {
			_window.close();
		};
		TextButton* host_button = new TextButton("Host", 100.f, 500.f);
		host_button->_on_click = [this]() {
			// host game: open server 
			_status = Status::StatusHost;
			openServer();
			
		};
		TextButton* join_button = new TextButton("Join", 100.f, 600.f);
		join_button->_on_click = [this]() {
			//join game
		};

		_menu.attach(host_button);
		_menu.attach(join_button);
		_menu.attach(start_button);
		_menu.attach(exit_button);

		//Gameworld stuff and shit
		
		
	}

	void Window::inputCases(const sf::Event& event)
	{
		if (event.type == sf::Event::Closed)//Close window
			_window.close();
		else if (event.type == sf::Event::KeyPressed) //keyboard input
		{
			if (event.key.code == sf::Keyboard::Escape)
				_window.close();
		}
	}

	void Window::processEvent(sf::Event& event)
	{
		inputCases(event);

		switch (_status)
		{
		case Status::StatusMenu:
			_menu.processEvent(event);
			break;
		case Status::StatusGameworld:
			_gameworld.controlInput();
			break;
		default:
			break;
		}
	}

	void Window::update(sf::Time deltaTime)
	{
		switch (_status)
		{
		case kenster::Window::StatusMenu:
			break;
		case kenster::Window::StatusGameworld:
			_gameworld.update(deltaTime);
			break;
		default:
			break;
		}
	}

	
	void Window::render()
	{
		_window.clear();

		switch (_status)
		{
		case Status::StatusMenu:
			_window.draw(_menu);
			break;
		case Status::StatusGameworld:
			_window.draw(_gameworld);
			break;
		case Status::StatusHost:
			_window.draw(_host);
			break;
		default:
			break;
		}

		_window.display();
	}

	bool Window::isOpen()
	{
		return _window.isOpen();
	}

	bool Window::pollEvent(sf::Event& event)
	{
		return _window.pollEvent(event);
	}

	void Window::openServer()
	{
		//use server class here
	}

}