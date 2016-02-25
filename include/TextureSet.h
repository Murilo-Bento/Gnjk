#ifndef _TEXTURESET_H_
#define _TEXTURESET_H_

#include <SFML/Graphics.hpp>
#include <string>

class TextureSet{
private:
	// The texture
	sf::Texture texture;

	/**
	 * Load the texture.
	 * @param pathToImage the path to the image
	 */
	void loadTexture(std::string pathToImage);

	/**
	 * Create the texture.
	 * @param w the width of the texture
	 * @param h the height of the texture
	 */
	void createTexture(int w, int h);

public:

	/**
	 * Constructor.
	 * @param pathToImage the path to the image
	 * @param w the width of the texture
	 * @param h the height of the texture
	 */
	TextureSet(std::string pathToImage, int w, int h);

	/**
	 * Get the texture.
	 * @return the texture
	 */
	sf::Texture* getTexture();
};

#endif
