#ifndef KENSTER_CONFIGURATION_HPP
#define KENSTER_CONFIGURATION_HPP

#include <SFML/Graphics.hpp>

#include <SFML-Kenster/ResourceManager.hpp>
#include <SFML-Kenster/ActionMap.hpp>

namespace kenster
{
	class Player;
	class Configuration
	{
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;

		////////////////////Texture
		enum Textures : int { 
			Player,
			BigMeteor1,
			BigMeteor2,
			BigMeteor3,
			BigMeteor4
		};
		static ResourceManager<sf::Texture, int> textures;
		////////////////////Fonts
		enum Fonts : int {
			Gui
		};
		static ResourceManager<sf::Font, int> fonts;
		///////////////////PlayerInputs
		enum PlayerInputs : int { 
			Up, 
			Left, 
			Right 
		};

		static ActionMap<int> playerInputs;
		
		static void initialize();

		static void reset();

		static bool isGameOver();

		static kenster::Player* player;
		static int lives;

	private:

		static void initTextures();
		static void initFonts();

		static void initPlayerInputs();
	};
}

#endif // !KENSTER_CONFIGURATION_HPP
