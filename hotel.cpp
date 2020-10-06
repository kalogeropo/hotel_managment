#include "hotel.h"
#include <string>
#include <iomanip>

using namespace std;

ostream &operator<<(ostream &output , room ptr)
{
    return output;
}
hotel::hotel()
{
    //ctor
}
hotel::~hotel(){}


void hotel::addRoom(room* newRoom){
    cout<<newRoom->getRoomCode()<<endl;
    rooms.push_back(*newRoom);
}

room hotel::getRoomByCode(int myRoomCode)
{
for (size_t i = 0 ; i != rooms.size(); i++) {
                //cout<<"la8os edw? Rooms code: "<<rooms[i].getRoomCode();//oxi la8os edw
                //cout<<"input code "<<myRoomCode<<endl;
                if (rooms[i].getRoomCode()==myRoomCode){
                //cout<<"\n"<<rooms[i].getRoomCode()<<"here\n"; // prepei na kanoyme overload tous operators <<
                //rooms[i].To_String();
                return rooms[i];
                }
    }
                cout<<"\nnot found creating error room\n";
                room test;
                return test;

}

reservation hotel::getReservationByCode(int myReservationCode) {
        for (size_t i = 0; i < reservations.size(); i++) {
            if (reservations[i].getRes_code() == myReservationCode){
                //reservations[i].ToString();
                return reservations[i];}
        }
                  reservation errorres;
                  return errorres;
}



bool hotel::addReservationInRoom(reservation myRes, int myRoomCode) {
        for (size_t i = 0 ; i != rooms.size(); i++) {
            cout<<"\nRoom " <<rooms[i].getRoomCode()<<endl;
            cout<<"\nRoom cap :" <<rooms[i].getcap()<<endl;
        }//debug
        room myRoom = getRoomByCode(myRoomCode);
        //myRoom.To_String();
        if (myRoom.getcap()!=9999 ) {
            reservation* resptr = &myRes;
            //bool apotelesma = myRoom.addReservation(resptr);
            if (myRoom.addReservation(&myRes)==true) {
                reservations.push_back(myRes);
                cout << "ADD Reservation Success!!!\n";
                myRoom.To_String();
                return true;
            } else {
                cout << "\nOooops something went wrong\n";
                return false;
            }
        } else {
            cout << "\nWrong Room code\n";
            return false;
        }
    }
bool hotel::addReservationInRoom(reservation newRes){
    for (size_t i = 0 ; i != rooms.size(); i++) {
        //cout<<"\nChecking room "<<rooms[i].getRoomCode()<<endl;
        if(rooms[i].addReservation(&newRes)==true){
            reservations.push_back(newRes);
            cout<<"res success"<<endl;
            newRes.ToString();
            break;
        }


    }
}
bool hotel::cancelReservation(int rescode) {
        reservation testres = getReservationByCode(rescode);
        //testres.ToString();
        string n = testres.GetName();
        if ( n != "error" ) {
            for (size_t i = 0 ; i != rooms.size(); i++) {
                if(rooms[i].roomCancelation(rescode) == true){
                    cout<<"cancel successfull!!"<<endl;
                    reservations.erase((reservations.begin() + i));
                    return true;
                }
                else{
                    cout<<"Room Cancelation unsuccessfull"<<endl;
                    return false;
                }
            }
        }
        else{
            cout<<"Room Cancelation unsuccessfull:WRONG RESERVATION CODE!!"<<endl;
            return false;
                }
}

double hotel::pricing_calculator(){
    double cost = 0;
    for (size_t i = 0 ; i != rooms.size(); i++) {
        cost+=pricing_calculator(rooms[i].getRoomCode());
        }


return cost;}

double hotel::pricing_calculator(int rcode){
    room roomtoprice = getRoomByCode(rcode);
        if (roomtoprice.getcap()!=9999 ) {
            return roomtoprice.pricing();
        }else{
        cout<<"\nerror room\n";}
}

void  hotel::graph_rep_hotel(){
    cout<<"\n==================Hotel============================="<<endl;

        cout<<"room\t";
        for (int i = 1; i<=30; i++)
        {
            if (i<10)
                cout<< "0"<< i <<" ";
            else
                cout<<i<<" ";
        }

        for (int i=0; i < rooms.size(); i++)
        {
            cout<<"\n" << rooms[i].getRoomCode() << "\t";
            for (int j=0; j<30; j++ )
            {
                if (rooms[i].getAvailability(j)==0)
                    cout<<" _ ";
                else
                    cout<<" * ";
            }
        }
        cout<<" ";
    }

void hotel::printAllRooms(){
cout<<"\n\t\t====================="<<endl;
cout<<"Room ID \tRoom Cap \tRoom Income \tCompleteness\n";
 for (size_t i = 0 ; i != rooms.size(); i++) {

            cout<<"  " <<rooms[i].getRoomCode();
            cout<<"  \t\t" <<rooms[i].getcap();
            //rooms[i].To_String();
            cout<<"  \t\t"<<pricing_calculator(rooms[i].getRoomCode());
            cout<<"  \t\t"<<rooms[i].completeness()<<endl;

        }
}
void hotel::printAllReservations(){
cout<<"\n\t\t====================="<<endl;
for (size_t i = 0 ; i < reservations.size(); i++) {
        cout<<"RESERVATION CODE:" <<reservations[i].getRes_code()<<endl;
        cout<<"CLIENT NAME:" <<reservations[i].GetName()<<endl;
        bool test =true;
        for (size_t j = 0 ; j < rooms.size(); j++) {
            for (int k = 0 ;k<30;k++ ){
                    //cout<<rooms[j].getAvailability(k)<<endl;
               if(rooms[j].getAvailability(k)!=0){
                    cout<<rooms[j].getAvailability(k)->getRes_code()<<"!=";
                    cout<<reservations[i].getRes_code()<<endl;
               if(rooms[j].getAvailability(k)->getRes_code()==reservations[i].getRes_code()){
                    cout<<"ROOM CODE:"<<rooms[j].getRoomCode()<<endl;

                }
                }

            }


        }
}
}

int hotel::no_of_res(){

return reservations.size();}
bool hotel::newavail(int reser){
    reservation res = getReservationByCode(reser);
    for (size_t j = 0 ; j < rooms.size(); j++) {
        for (int i = 0;i<30;i++){
            if(rooms[j].getAvailability(i)!=0){
            int Rcode = rooms[j].getAvailability(i)->getRes_code();
            if(Rcode == reser){
                rooms[j].setavail(i);
            }

        }
        }
    }
}
