#ifndef ROOM_H
#define ROOM_H

#include <string>


#include <iostream>
#include <cstdlib>
#include "reservation.h"

using namespace std;

class room
{
    public:
        //methods
        void setavail(int index){this->availability[index]=0;}
        int getcap(){return maxCapacity; }
        reservation* getAvailability(int index){return availability[index];}
        double completeness();
        bool roomCancelation(int );
        virtual double pricing();
        virtual bool addReservation(reservation* resObj);
        int getRoomCode(){return id;}
        void To_String();
        //constructors
        room(); //default constructor
        room( int maxcapacity);
        //deconstructors
        virtual ~room();
        //variables
        class reservation* resObj;
    protected:
        int maxCapacity;
        double pricePerPerson=40;

    private:
        reservation *availability[30]={0};
        unsigned static int Room_code;
        int id;


};

#endif // ROOM_H
