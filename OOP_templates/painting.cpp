#include "painting.h"

int Painting::getCost(Cars *value)
{
    int cost = 10000 * 1.4 * (value->getClass() + 1);
    return cost;
}
