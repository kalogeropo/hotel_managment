#include "roomtypeB.h"
#include "reservation.h"

unsigned int roomtypeB::RoomtB_code=0;


roomtypeB::roomtypeB(int maxcap,int discount):roomtypeA(maxCapacity=maxcap)
{
    //this->maxCapacity = maxcap;
    this->discount = discount;
    RoomtB_code++;
}

//roomtypeB::~roomtypeB()
//{
    //dtor
//}

double roomtypeB::pricing(){
    double cost=0;
    float low_bound = pricePerDay/2;
    double newprice = pricePerDay;
    int i=0;
    while(i<30){
        if(getAvailability(i)!=0){
            int no_of_days = getAvailability(i)->GetSd();
            //cout<<"Days"<<no_of_days<<endl;
            for(int j = 0 ; j<no_of_days; j++){
                newprice = pricePerDay - j*discount;
                if(newprice>low_bound){
                    cost+=newprice;
                }
                else{
                    cost+=(pricePerDay/2);

                }
            }
            i+=no_of_days;//move index to the end
        }
        i++;
    }
    return cost;
}

bool roomtypeB::roomCancelation(int resCode){
    return false;
}
