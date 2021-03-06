#ifndef _TILE_HPP_
#define _TILE_HPP_

// # External
#include <SFML/Graphics.hpp>

class Tile{
private:
  // The position of the tile
  sf::Vector2f tilePosition;

  // The rect of the tile
  sf::FloatRect tileRect;

public:
  int id;
  /**
   * Constructor.
   * @param tilePosition the position of the tile
   */
  Tile(sf::Vector2f tilePosition, int id);

  /**
   * Get the position of the tile.
   * @return the position of the tile
   */
  sf::Vector2f getPosition() const;

  /**
   * Get the position in x axis.
   * @return the position in x axis
   */
  float getPositionX() const;

  /**
   * Get the position in y axis.
   * @return the position in y axis
   */
  float getPositionY() const;

  /**
   * Get the tile rect.
   * @return the tile rect
   */
  sf::FloatRect getTileRect() const;
};

#endif
