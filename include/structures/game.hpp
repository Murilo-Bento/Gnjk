#ifndef _GAME_HPP_
#define _GAME_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

// # Internal
#include "enums/textureindex.hpp"

#include "structures/texturemanager.hpp"
#include "entities/clock/clockhandler.hpp"
#include "entities/clock/generictimehandler.hpp"
#include "structures/dynamicgrid.hpp"
#include "entities/soundtable.hpp"
#include "structures/collisionhandler.hpp"
#include "enums/timehandlers.hpp"
#include "scenes/gamescene.hpp"
#include "structures/scenemanager.hpp"

class Game{

private:
	sf::RenderWindow gameScreen;

	int gameWidth;
	int gameHeight;

	ClockHandler clockHandler;
	TextureManager textureManager;
	GenericTimeHandler gameFrequency;

	SceneManager sceneManager;

public:
	/**
	 * Constructor.
	 * @param gameWidth the width of the window
	 * @param gameHeight the height of the window
	 * @param gameTitle the title of the window
	 */
	Game(int gameWidth, int gameHeight, std::string gameTitle);
	
	void gameStart();
	void processEvents();
	void clearNDraw();
	int getGameWidth();
	int getGameHeight();

	void handleTimeActions();
};

#endif
