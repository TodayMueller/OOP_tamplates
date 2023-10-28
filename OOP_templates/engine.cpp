#include "engine.h"

int Engine::getCost(Cars *value)
{
    int cost = 14000 * 1.4 * (value->getClass() + 1);
    return cost;
}
