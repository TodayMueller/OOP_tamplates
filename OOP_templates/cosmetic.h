#ifndef COSMETIC_H
#define COSMETIC_H

#include "abstract.h"
#include "owners.h"
#include "cars.h"

class Cosmetic : public Abstract
{
public:
    int getCost(Cars *value) override;
};

#endif // COSMETIC_H
