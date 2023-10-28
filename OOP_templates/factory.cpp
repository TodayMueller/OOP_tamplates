#include "factory.h"
#include "body.h"
#include "cosmetic.h"
#include "engine.h"
#include "overhaul.h"
#include "painting.h"

factory::factory(QObject *parent)
    : QObject{parent}
{}

Abstract *factory::createCalc(int type){
    switch (type){
    case 0:
        return new Painting();
    case 1:
        return new Overhaul();
    case 2:
        return new Body();
    case 3:
        return new Cosmetic();
    case 4:
        return new Engine();
    }
}
