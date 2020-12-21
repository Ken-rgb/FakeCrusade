#include <SFML-Kenster/Configuration.hpp>
#include <SFML-Kenster/random.hpp>

namespace kenster
{
	ResourceManager<sf::Texture, int> Configuration::textures;
	ResourceManager<sf::Font, int> Configuration::fonts;

	ActionMap<int> Configuration::playerInputs;
	

	kenster::Player* Configuration::player = nullptr;
	int Configuration::lives;

	//init
	void Configuration::initialize()
	{
		initTextures();
		initFonts();
		initPlayerInputs();

		rand_init();
		lives = -1;
	}

	void Configuration::reset()
	{
		lives = 1;
	}

	bool Configuration::isGameOver()
	{
		return lives < 0;
	}
	/////////////Textures
	void Configuration::initTextures()
	{
		textures.load(Textures::Player, "media/Player/Ship.png");
		textures.load(Textures::BigMeteor1, "media/Meteor/Big1.png");
		textures.load(Textures::BigMeteor2, "media/Meteor/Big2.png");
		textures.load(Textures::BigMeteor3, "media/Meteor/Big3.png");
		textures.load(Textures::BigMeteor4, "media/Meteor/Big4.png");
	}
	///////////Fonts
	void Configuration::initFonts()
	{
		fonts.load(Fonts::Gui, "media/font/trs-million.ttf");
	}


	void Configuration::initPlayerInputs()
	{
		playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
		playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
		playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
	}
}