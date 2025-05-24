//
// Created by Roman Kanterov on 23.05.2025.
//

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include "Cabin.hpp"
#include "Controller.hpp"
#include "Doors.hpp"

#include <QObject>


class Elevator : public QObject {
    Q_OBJECT
    friend class MainWindow;
public:
    explicit Elevator(QObject *parent = nullptr);
signals:
    void newFloor(int floor);
public slots:
    void newRequest(int floor);
private:
    Cabin _cabin;
    Controller _controller;
};



#endif //ELEVATOR_HPP
