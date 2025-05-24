//
// Created by Roman Kanterov on 23.05.2025.
//

#ifndef DOORS_HPP
#define DOORS_HPP
#include <QObject>
#include <QTimer>


class Doors : public QObject {
    Q_OBJECT
public:
    enum DoorsState { OPENED, CLOSED, OPENING, CLOSING };
    explicit Doors(QObject *parent = nullptr);

signals:
    void doorsOpened();
    void doorsClosed();

public slots:
    void openDoors();
    void closeDoors();
    void openingDoors();
    void closingDoors();

private:
    DoorsState _state;
    QTimer _closingTimer;
    QTimer _openingTimer;
    QTimer _openDuration;
};



#endif //DOORS_HPP
