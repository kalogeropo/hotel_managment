#ifndef ROOMTYPED_H
#define ROOMTYPED_H

#include "roomtypeE.h"

/* that room has a menu service for each menu chosen each person must pay 10€ more for each person we support
a 10% deiscount ->inheritance of roomtypeD  */
class roomtypeD : public roomtypeE
{
    public:
        roomtypeD(int,bool,bool,bool);
         roomtypeD(int);
        //virtual ~roomtypeD();

    protected:

    private:
        bool breakfast,launch,dinner;
        unsigned static int RoomtD_code;
};

#endif // ROOMTYPED_H
