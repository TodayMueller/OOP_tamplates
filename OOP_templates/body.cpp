#include "body.h"

int Body::getCost(Cars *value)
{
    int cost = 12000 * 1.4 * (value->getClass() + 1);
    return cost;
}
