#include "overhaul.h"

int Overhaul::getCost(Cars *value)
{
    int cost = 16000 * 1.4 * (value->getClass() + 1);
    return cost;
}
