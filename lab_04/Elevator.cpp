//
// Created by Roman Kanterov on 23.05.2025.
//

#include "Elevator.hpp"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(newFloor(int)), &_controller, SLOT(addNewTarget(int)));

    connect(&_controller, SIGNAL(openDoors()), &_cabin, SLOT(lockCabin()));
    connect(&_controller, SIGNAL(moveCabin()), &_cabin, SLOT(move()));

    connect(&_cabin._moveTimer, SIGNAL(timeout()), &_controller, SLOT(handleMovingToNext()));
    connect(&_cabin, SIGNAL(cabinUnlocked()), &_controller, SLOT(handleMovingToNext()));
}

void Elevator::newRequest(int floor)
{
    emit newFloor(floor);
}