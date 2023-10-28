#ifndef OVERHAUL_H
#define OVERHAUL_H

#include "abstract.h"
#include "owners.h"
#include "cars.h"

class Overhaul : public Abstract
{
public:
    int getCost(Cars *value) override;
};

#endif // OVERHAUL_H
