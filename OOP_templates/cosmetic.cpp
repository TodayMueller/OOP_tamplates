#include "cosmetic.h"

int Cosmetic::getCost(Cars *value)
{
    int cost = 8000 * 1.4 * (value->getClass() + 1);
    return cost;
}
