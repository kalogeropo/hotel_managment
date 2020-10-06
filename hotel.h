#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "reservation.h"
using namespace std;
class hotel
{
    public:
        hotel();
        virtual ~hotel();

        void printAllRooms();
        void printAllReservations();
        int no_of_res();

        friend ostream &operator<<(ostream&,room);

        void addRoom(room* newRoom);
        room getRoomByCode(int);
        reservation getReservationByCode(int myReservationCode);

        double pricing_calculator();
        double pricing_calculator(int);

        bool addReservationInRoom(reservation myRes, int myRoomCode);
        bool addReservationInRoom(reservation newRes);

        bool cancelReservation(int rescode);
        bool newavail(int);

        void graph_rep_hotel();
    protected:
    string name;
    private:
        class vector<room> rooms;
        class vector<reservation> reservations;
};

#endif // HOTEL_H
