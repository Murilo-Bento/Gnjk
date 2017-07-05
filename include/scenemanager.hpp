#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include <iostream>

#include "scene.hpp"
#include "texturemanager.hpp"
#include "gamescene.hpp"

class SceneManager : public SSceneManager {
private:
	Scene& scene;
	TextureManager textureManager;

public:
	SceneManager(TextureManager& textureManager, Scene& scene);
	void setScene(Scene& scene);
	void changeScene();
	Scene& getScene() const;

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
};

#endif