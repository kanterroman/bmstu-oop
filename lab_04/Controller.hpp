//
// Created by Roman Kanterov on 23.05.2025.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <QObject>


class Controller : public QObject {
    Q_OBJECT
public:
    enum ControllerState { PENDING, HANDLING_MOVING, HANDLING_OPEN_CLOSE, ADDING_TARGET };
    enum Direction { UP = 1, DOWN = -1, STOP = 0 };
    explicit Controller(QObject *parent = nullptr);

signals:
    void moveCabin();
    void openDoors();
    void onFloor(int floor);

    void noTargets();
    void floorReached();
    void moveToTarget();

public slots:
    void handleMovingToNext();
    void handleArrival();
    void toPending();
    void addNewTarget(int floor);
private:
    void determineDirection(int currentFloor);
    void addToQueue(int floor);
    std::list<int> _queue;
    ControllerState _state;
    Direction _direction;
    int _currentFloor;
};



#endif //CONTROLLER_HPP
