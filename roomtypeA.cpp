#include "roomtypeA.h"

unsigned int roomtypeA::RoomtA_code=0;
//edw kaleitai o constractor tis room ara 8a ginei to room++ opote etsi kanw count ola ta room




roomtypeA::roomtypeA(int maxCap):room(maxCapacity=maxCap)
{      //this->maxCapacity = maxCap;
       roomtypeA::RoomtA_code++;

}

//roomtypeA::~roomtypeA()
//{
    //dtor
//}
double roomtypeA::pricing(){
    double cost = 0;
    for(int i = 0; i<30;i++){
        if(getAvailability(i)!= 0){
            cost +=pricePerDay;
        }
    }
    cout<<"\ncost of room type A "<<cost<<endl;
    return cost;
 }

