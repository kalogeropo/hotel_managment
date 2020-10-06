#ifndef ROOMTYPEC_H
#define ROOMTYPEC_H

#include "room.h"


class roomtypeC : public room
{
    public:
        bool addReservation(reservation* resobj)override;
        roomtypeC(int);//only with max capacity
        roomtypeC(int,int,int);//max capacity , min people , min days
        virtual ~roomtypeC();

    protected:

    private:
        int min_people =2;
        int min_days = 5;
        unsigned static int RoomtC_code;

};

#endif // ROOMTYPEC_H
