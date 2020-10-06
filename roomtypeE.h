#ifndef ROOMTYPEE_H
#define ROOMTYPEE_H

#include "room.h"


class roomtypeE : public room
{
    public:
        double pricing() override;
        double setprice(double r_price){return this->roomprice=r_price;}
        roomtypeE(int);
        virtual ~roomtypeE();

    protected:

    private:
        unsigned static int RoomtE_code;
        double discount_pers =0.1;
        double roomprice = 0;
};

#endif // ROOMTYPEE_H
