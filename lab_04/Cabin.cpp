//
// Created by Roman Kanterov on 23.05.2025.
//

#include "Cabin.hpp"
#include <QDebug>

#include "Config.hpp"

Cabin::Cabin(QObject *parent) : QObject(parent), _state(UNLOCKED)
{
    connect(&_doors, SIGNAL(doorsClosed()), this, SLOT(unlockCabin()));
    connect(this, SIGNAL(cabinLocked()), &_doors, SLOT(openingDoors()));

    _moveTimer.setSingleShot(true);
}

void Cabin::lockCabin()
{
    if (_state != UNLOCKED && _state != MOVING && _state != LOCKED)
        return;
    auto _prevState = _state;
    _state = LOCKED;

    if (_prevState != LOCKED)
        qDebug() << "Кабина заблокирована";
    emit cabinLocked();
}

void Cabin::unlockCabin()
{
    if (_state != LOCKED)
        return;
    _state = UNLOCKED;

    qDebug() << "Кабина разблокирована";
    emit cabinUnlocked();
}

void Cabin::move()
{
    if (_state == LOCKED)
        return;
    auto prevState = _state;
    _state = MOVING;

    if (prevState != MOVING)
        qDebug() << "Кабина начала движение";

    _moveTimer.start(ONE_FLOOR_MOVING_TIME);
}