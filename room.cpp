#include "room.h"
#include <iostream>
#include "reservation.h"

#include <typeinfo>
using namespace std;

unsigned int room::Room_code=0;
//constructors
room::room()
{
    this->maxCapacity = 9999;
}

room::room(int maxcapacity){
    room::Room_code++;
    this->maxCapacity = maxcapacity;
    this->id=Room_code;


}
room::~room()
{
    //dtor
}
void room::To_String(){
    if (maxCapacity!=9999){
    cout<<"\nRoom Num " <<this->id << endl;
    //cout<<"test " <<typeid(this->availability).name() << endl; //testing that the availability array is the right type
    cout<<"Room Cap " <<this->maxCapacity << endl;
    for (int i=0;i<30;i++){
            //if(availability[i]== 0){
                cout<<availability[i]<<"|";//}
        }
    }
    else{
        cout<<"\nError or Null room\n";
        cout<<maxCapacity<<endl;
    }

}

bool room::addReservation(reservation* resObj){
    int arrival = resObj->GetDoa();
    int days = resObj->GetSd();
    int cust = resObj->GetNoC();
    //cout<< "\narrival " << arrival <<"\nstay days "<<days<<"\ncustomers "<<cust<<endl;
    if (arrival+days<=29){
            if(cust <= maxCapacity){
                bool flag  = false;
                for (int i = arrival-1; i<arrival+days-1; i++){
                        if(availability[i]!=0){
                            //cout<<"test \n";
                            flag = true;
                        }


                }//for
                //cout<<"flag "<<flag<<endl;
                if (flag == false){
                    //cout<<"Room is free--Reservation success"<<endl;
                    for (int i = arrival-1; i<arrival+days-1; i++){
                        this->availability[i]=resObj;

                    }
                return true;
                }
                else{
                    cout<<" this room is reserved for those days "<<endl;
                    return false;
                    }
            }
            else{
                cout<<" cant support that many customers "<<endl;
                return false;
                }

    }
    else{
        cout<<"month limit exceeded"<<endl;
        return false;

    }

}


double room::pricing(){
    double cost = 0;
    for (int i =0; i<30; i++){
        if (availability[i]== 0 ){
            cost+=0;
        }
        else{
            cost = cost + availability[i]->GetNoC()*pricePerPerson;
        }
    }
    return cost;
}

bool room::roomCancelation(int resCode){
    for(int i=0;i<30;i++){
        if(availability[i]!=0){
            if(availability[i]->getRes_code()==resCode){
                availability[i]=0;
                //cout<<"canceling"<<endl;
            }
        }
    }
    cout<<"Reservation "<<resCode<<" canceled"<<endl;
    return true;
}


double room::completeness(){
        float pososto;
        int avg=0;

        for( int i=0; i<30; i++)
        {
            if (availability[i]!= NULL )
                avg++;
        }
        pososto =( (float) avg/30)*100;
        return pososto;
}

