#ifndef ROOMTYPEB_H
#define ROOMTYPEB_H

#include "roomtypeA.h"
#include "room.h"
#include "reservation.h"


class roomtypeB : public roomtypeA
{
    public:
        bool roomCancelation(int resCode);
        double pricing() override;//override virtual function
        //roomtypeB(); default constructor
        roomtypeB(int, int);
        //virtual ~roomtypeB();

    protected:

    private:
        unsigned static int RoomtB_code;
        double discount = 0.1;
};

#endif // ROOMTYPEB_H
