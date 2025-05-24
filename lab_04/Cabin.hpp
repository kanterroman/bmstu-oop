//
// Created by Roman Kanterov on 23.05.2025.
//

#ifndef CABIN_HPP
#define CABIN_HPP
#include "Doors.hpp"

#include <QObject>
#include <QTimer>


class Cabin : public QObject {
    Q_OBJECT
    friend class Elevator;

public:
    enum CabinState { LOCKED, UNLOCKED, MOVING };
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabinLocked();
    void cabinUnlocked();

public slots:
    void lockCabin();
    void unlockCabin();
    void move();
private:
    CabinState _state;
    // QTimer _lockedTimer;
    QTimer _moveTimer;
    Doors _doors;
};



#endif //CABIN_HPP
