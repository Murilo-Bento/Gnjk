#ifndef _COLLISIONHANDLER_HPP_
#define _COLLISIONHANDLER_HPP_

#include <vector>

#include "player.hpp"
#include "enemy.hpp"
#include "dynamicgrid.hpp"

class CollisionHandler{
private:
	DynamicGrid dynaGrid;

public:
	CollisionHandler(DynamicGrid dynaGrid);
	CollisionHandler();
	bool collisionBetweenPAndE(Player player, Enemy enemy);
};

#endif