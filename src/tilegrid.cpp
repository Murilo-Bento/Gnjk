#include "structures/tilegrid.hpp"

sf::Vector2i TileGrid::checkCondition(sf::Vector2i before) const{
  if(before.x < 0){
    before.x = 0;
  }

  if(before.x > xCells){
    before.x = xCells;
  }

  if(before.y < 0){
    before.y = 0;
  }

  if(before.y > yCells){
    before.y = yCells;
  }

  return before;
}

TileGrid::TileGrid(int w, int h, int unitySize) : AbstractGrid::AbstractGrid(w, h, unitySize){
  this->unities.resize(this->xCells * this->yCells);
}

Unity* TileGrid::getUnity(int x, int y){
  return &this->unities[x + y * xCells];
}

void TileGrid::addTile(Tile tile){
  int tileX = tile.getPositionX();
  int tileY = tile.getPositionY();

  sf::Vector2i ul = sf::Vector2i((int) tileX/unitySize, (int) tileY/unitySize);
  sf::Vector2i ll = sf::Vector2i((int) tileX/unitySize, (int) (tileY + 32)/unitySize);
  sf::Vector2i ur = sf::Vector2i((int) (tileX + 32)/unitySize, (int) tileY/unitySize);
  sf::Vector2i lr = sf::Vector2i((int) (tileX + 32)/unitySize, (int) (tileY + 32)/unitySize);

  Unity* unityUl = getUnity(ul.x, ul.y);
  Unity* unityLl = getUnity(ll.x, ll.y);
  Unity* unityUr = getUnity(ur.x, ur.y);
  Unity* unityLr = getUnity(lr.x, lr.y);

  unityUl->tiles.push_back(tile);

  if(unityLl != unityUl){
    unityLl->tiles.push_back(tile);   
  }

  if(unityUr != unityLl && unityUr != unityUl){
    unityUr->tiles.push_back(tile);
  }

  if(unityLr != unityUr && unityLr != unityLl && unityLr != unityUl){
    unityLr->tiles.push_back(tile);
  }
}

std::vector<Unity> TileGrid::getUnitiesOnPosition(sf::Vector2f playerUpperLeft) const{
  std::vector<Unity> adjacent;

  sf::Vector2i ul = sf::Vector2i((int) playerUpperLeft.x/unitySize, (int) playerUpperLeft.y/unitySize);
  sf::Vector2i ll = sf::Vector2i((int) playerUpperLeft.x/unitySize, (int) (playerUpperLeft.y + 32)/unitySize);
  sf::Vector2i ur = sf::Vector2i((int) (playerUpperLeft.x + 32)/unitySize, (int) playerUpperLeft.y/unitySize);
  sf::Vector2i lr = sf::Vector2i((int) (playerUpperLeft.x + 32)/unitySize, (int) (playerUpperLeft.y + 32)/unitySize);

  ul = checkCondition(ul);
  ll = checkCondition(ll);
  ur = checkCondition(ur);
  lr = checkCondition(lr);

  int upperLeft = ul.x + ul.y * xCells;
  int lowerLeft = ll.x + ll.y * xCells;
  int upperRight = ur.x + ur.y * xCells;
  int lowerRight = lr.x + lr.y * xCells;

  adjacent.push_back(upperLeft >= (xCells * yCells) ? this->unities[xCells * yCells - 1] : this->unities[upperLeft]);

  if(lowerLeft != upperLeft){
    adjacent.push_back(lowerLeft >= (xCells * yCells) ? this->unities[xCells * yCells - 1] : this->unities[lowerLeft]);
  }

  if(upperRight != lowerLeft && upperRight != upperLeft){
    adjacent.push_back(upperRight >= (xCells * yCells) ? this->unities[xCells * yCells - 1] : this->unities[upperRight]);
  }

  if(lowerRight != upperRight && lowerRight != lowerLeft && lowerRight != upperLeft){
    adjacent.push_back(lowerRight >= (xCells * yCells) ? this->unities[xCells * yCells - 1] : this->unities[lowerRight]);
  }

  return adjacent;
}