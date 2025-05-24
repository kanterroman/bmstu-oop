//
// Created by Roman Kanterov on 23.05.2025.
//

#include "Controller.hpp"
#include "Config.hpp"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent), _state(PENDING), _direction(UP), _currentFloor(INITIAL_FLOOR)
{
    connect(this, SIGNAL(noTargets()), this, SLOT(toPending()));
    connect(this, SIGNAL(floorReached()), this, SLOT(handleArrival()));
    connect(this, SIGNAL(moveToTarget()), this, SLOT(handleMovingToNext()));
}

void Controller::handleMovingToNext()
{
    if (_state == PENDING)
        return;

    auto prevState = _state;
    _state = HANDLING_MOVING;

    if (_queue.empty())
    {
        qDebug() << "Задач нет";
        emit noTargets();
    }
    else if (_currentFloor == _queue.front())
    {
        emit floorReached();
    }
    else
    {
        if (prevState == HANDLING_MOVING) {
            determineDirection(_currentFloor);
            _currentFloor += _direction;
            qDebug() << "Лифт на этаже №" << _currentFloor;
            emit onFloor(_currentFloor);
        }

        if (_currentFloor != _queue.front())
            emit moveCabin();
        else
            emit floorReached();
    }
}

void Controller::handleArrival()
{
    if (_state != ADDING_TARGET && _state != HANDLING_MOVING)
        return;

    _state = HANDLING_OPEN_CLOSE;
    if (_currentFloor == _queue.front())
    {
        _queue.pop_front();
        qDebug() << "Лифт приехал к точке назначения";
        emit openDoors();
    }
}

void Controller::toPending()
{
    if (_state == PENDING)
        return;
    _state = PENDING;
    qDebug() << "Лифт перешел в состояние ожидания";
}

void Controller::addNewTarget(int floor)
{
    _state = ADDING_TARGET;
    if (std::ranges::find(_queue, floor) != _queue.end())
        return;

    determineDirection(_currentFloor);
    addToQueue(floor);
    emit moveToTarget();
}

void Controller::determineDirection(int currentFloor)
{
    if (currentFloor < _queue.front())
        _direction = UP;
    else
        _direction = DOWN;
}

void Controller::addToQueue(int floor)
{
    if (_queue.empty())
    {
        _queue.push_back(floor);
        return;
    }
    auto fst = _queue.begin();
    auto snd = ++_queue.begin();
    while (snd != _queue.end() && (*snd - *fst) * _direction > 0) ++fst, ++snd;
    auto end = snd;

    if ((floor - _currentFloor) * _direction > 0)
    {
        auto it = _queue.begin();
        for (; it != end && (floor - *it) * _direction > 0; ++it);
        _queue.insert(it, floor);
    }
    else
    {
        auto it = end;
        for (; it != _queue.end() && (floor - *it) * -_direction > 0; ++it);
        _queue.insert(it, floor);
    }
}