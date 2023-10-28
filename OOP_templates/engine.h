#ifndef ENGINE_H
#define ENGINE_H

#include "abstract.h"
#include "owners.h"
#include "cars.h"

class Engine : public Abstract
{
public:
    int getCost(Cars *value) override;
};

#endif // ENGINE_H
