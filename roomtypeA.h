#ifndef ROOMTYPEA_H
#define ROOMTYPEA_H

#include "room.h"


class roomtypeA : public room
{
    public:
        double pricing() override;
        roomtypeA(int);
        //virtual ~roomtypeA();

    protected:
        double pricePerDay = 60;

    private:
        unsigned static int RoomtA_code;


};

#endif // ROOMTYPEA_H
