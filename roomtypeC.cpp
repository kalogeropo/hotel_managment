#include "roomtypeC.h"

unsigned int roomtypeC::RoomtC_code = 0 ;
roomtypeC::roomtypeC(int maxCap):room(maxCapacity = maxCap)
{      this->maxCapacity = maxCap;
       roomtypeC::RoomtC_code++;

}
roomtypeC::roomtypeC(int maxCap,int min_p,int min_d):room(maxCapacity=maxCap)
{
    //this->maxCapacity = maxCap;
    this->min_days=min_d;
    this->min_people=min_p;
    roomtypeC::RoomtC_code++;
}

roomtypeC::~roomtypeC()
{
    //dtor
}
//new and improved addreservation method
bool roomtypeC::addReservation(reservation* resobj){
    cout<<"adding reservation to Room C\n";
    int days = resObj->GetSd();
    int cust = resObj->GetNoC();
    if(days>=min_days && cust>=min_people){
        return room::addReservation(resobj);

    }
    else{
        cout<<"Cant support that number of people\n";
        return false;
    }
}
