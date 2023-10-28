#ifndef PAINTING_H
#define PAINTING_H

#include "abstract.h"
#include "owners.h"
#include "cars.h"

class Painting : public Abstract
{
public:
    int getCost(Cars *value) override;
};

#endif // PAINTING_H
