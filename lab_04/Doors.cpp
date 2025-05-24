//
// Created by Roman Kanterov on 23.05.2025.
//

#include "Doors.hpp"

#include <QDebug>
#include "Config.hpp"

Doors::Doors(QObject *parent) : QObject(parent), _state(CLOSED)
{
    _openingTimer.setSingleShot(true);
    _closingTimer.setSingleShot(true);
    _openDuration.setSingleShot(true);
    _openDuration.setInterval(DOOR_WAITING_TIME);

    connect(&_openingTimer, SIGNAL(timeout()), this, SLOT(openDoors()));
    connect(&_openDuration, SIGNAL(timeout()), this, SLOT(closingDoors()));
    // connect(this, SIGNAL(doorsOpened()), &_openDuration, SLOT(start()));
    connect(this, SIGNAL(doorsOpened()), &_openDuration, SLOT(start()));
    connect(&_closingTimer, SIGNAL(timeout()), this, SLOT(closeDoors()));
}

void Doors::openDoors()
{
    if (_state != OPENING)
        return;
    _state = OPENED;

    qDebug() << "Дверь лифта открыта";
    emit doorsOpened();
}

void Doors::closeDoors()
{
    if (_state != CLOSING)
        return;
    _state = CLOSED;

    qDebug() << "Дверь лифта закрыта.";
    emit doorsClosed();
}

void Doors::openingDoors()
{
    if (_state != CLOSING && _state != CLOSED)
        return;
    auto _prevState = _state;
    _state = OPENING;

    qDebug() << "Двери открываются...";
    if (_prevState == CLOSED)
    {
        _openingTimer.start(DOOR_OPENING_CLOSING_TIME);
    }
    else if (_prevState == CLOSING)
    {
        _openingTimer.stop();

        qDebug() << "Закрытие прервано";

        auto timeToOpen = DOOR_OPENING_CLOSING_TIME - _closingTimer.remainingTime();
        _openingTimer.start(timeToOpen);
    }
}

void Doors::closingDoors()
{
    if (_state != OPENED)
        return;
    _state = CLOSING;

    qDebug() << "Двери закрываются...";
    _closingTimer.start(DOOR_OPENING_CLOSING_TIME);
}