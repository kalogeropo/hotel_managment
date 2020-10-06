#include "roomtypeE.h"
unsigned int roomtypeE::RoomtE_code = 0;
roomtypeE::roomtypeE(int cap):room(maxCapacity = cap)
{
    roomtypeE::RoomtE_code++;
}

roomtypeE::~roomtypeE()
{
    //dtor
}
double roomtypeE::pricing(){

    double newprice, cost = 0;
    int cap , i=0;

    while(i<30){
        if(getAvailability(i)!=0){
            int no_of_days = getAvailability(i)->GetSd();
            cap = getAvailability(i)->GetNoC();
            double pricePerDay = 0;
            if (roomprice==0){
            newprice = pricePerPerson;
            }
            else{
            newprice = roomprice;
            }
            for (int j =0; j<cap; j++ ){
                newprice -=(j*discount_pers*newprice);
                pricePerDay+=newprice;
            }
            cout<<newprice<<endl;

            cost = pricePerDay*no_of_days;
            i+=no_of_days;
        }

       i++;
    }


    return cost;}
