#include "roomtypeD.h"

unsigned int roomtypeD::RoomtD_code=0;
roomtypeD::roomtypeD(int cap ,bool breakfast,bool launch,bool dinner ):roomtypeE(maxCapacity=cap)
{
    //ctor
    this->breakfast= breakfast;
    this->launch=launch;
    this->dinner=dinner;
    roomtypeD::RoomtD_code++;
    if(breakfast==true){
        pricePerPerson+=10;
    }
    if(launch==true){
        pricePerPerson+=10;
    }
    if(dinner==true){
        pricePerPerson+=10;
    }

}

roomtypeD::roomtypeD(int cap):roomtypeE(maxCapacity=cap)
{
    this->breakfast= false;
    this->launch=false;
    this->dinner=false;
    roomtypeD::RoomtD_code++;
    if(breakfast==true){
        pricePerPerson+=10;
    }
    if(launch==true){
        pricePerPerson+=10;
    }
    if(dinner==true){
        pricePerPerson+=10;
    }

}
