#ifndef BODY_H
#define BODY_H

#include "abstract.h"
#include "owners.h"
#include "cars.h"

class Body : public Abstract
{
public:
    int getCost(Cars *value) override;
};

#endif // BODY_H
