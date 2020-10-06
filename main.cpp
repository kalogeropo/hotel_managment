#include <iostream>
#include <string>
#include <vector>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()


#include "reservation.h"
#include "room.h"
#include "roomtypeA.h"
#include "roomtypeB.h"
#include "roomtypeC.h"
#include "roomtypeE.h"
#include "roomtypeD.h"
#include "hotel.h"
using namespace std;



void printmenu();

int hotelInit(hotel hotobj);

void printRooms();

int main(){

    cout<<"Welcome to the hotel California"<<endl;

    hotel california; //creates hotel obeject
    room* roomspointer; // pointer type room so we can refer to all roomtypes by it

    room room1(5);
    roomspointer = &room1;
    california.addRoom(roomspointer); //using the same pointer we can refer to all types of rooms and add them to the california object -> type hotel
                                        //1
    roomtypeA roomTA1(6);
    roomspointer = &roomTA1;
    california.addRoom(roomspointer);//2
    roomtypeA roomTA2(4);
    roomspointer = &roomTA2;
    california.addRoom(roomspointer);//3

    roomtypeB roomTB1(6,10);
    roomspointer = &roomTB1;
    california.addRoom(roomspointer);//4
    roomtypeB roomTB2(7,20);
    roomspointer = &roomTB2;
    california.addRoom(roomspointer);//5

    roomtypeC roomTC1(8);
    roomspointer = &roomTC1;
    california.addRoom(roomspointer);//6
    roomtypeC roomTC2(9);
    roomspointer = &roomTC2;
    california.addRoom(roomspointer);//7

    roomtypeD roomTD1(10,false , true,false);
    roomspointer = &roomTD1;
    california.addRoom(roomspointer);
    roomtypeD roomTD2(11,true, false,true);
    roomspointer = &roomTD2;
    california.addRoom(roomspointer);

    roomtypeE roomTE1(12);
    roomspointer = &roomTE1;
    california.addRoom(roomspointer);
    roomtypeE roomTE2(13);
    roomspointer = &roomTE2;
    california.addRoom(roomspointer);

static bool  validAnswer;
reservation firstres("hotel_tester",10,5,1);
//RAMDOMIZER INIT
 srand(time(0));

string Cname ;
int ar,d,peeps, roomC,rescode;
int answer;
int rounds=0;
validAnswer=false;
int cancelation_chance,resno,pick;



reservation newres;
california.addReservationInRoom(firstres);
    do
            {

            bool pause = false;//change to false
            rounds++;
            if (!pause){
            printmenu();
            cout<<"Choose an option";
            cin>>answer;}
            else{answer=1;}


                switch (answer)
                {
                    case 1:
                        cout<<"++++++++++++++Round: "<<rounds<<"++++++++++++++"<<endl;
                        Cname = "round" + to_string(rounds);
                        do{
                        d=(rand()%20)+1;
                        ar = (rand()%29)+1;
                        }while(d+ar>30);
                        peeps = (rand()%13+1);
                        cout<<"Cname:"<<Cname<<endl;
                        cout<<"Arrive:"<<ar<<endl;
                        cout<<"Days:"<<d<<endl;
                        cout<<"Customers"<<peeps<<endl;
                        newres.setall(Cname,ar,d,peeps);
                        california.addReservationInRoom(newres);

                        cancelation_chance =rand()%4;
                        if (cancelation_chance==0){
                            cout<<"RANDOM ROOM CANCELATION!!!"<<endl;
                            resno=california.no_of_res();
                            //cout<<resno<<endl;
                            pick =rand()%resno;
                            cout<<"Lucky Reservation iiiiiissssss: "<<pick<<endl;
                            california.cancelReservation(pick);
                            california.newavail(pick);

                        }
                        pause = false;
                        break;
                    case 2:

                        cout<<"Input Customer name: ";
                        cin>>Cname;
                        cout<<"Input date of arrival: ";
                        cin>>ar;
                        cout<<"Input the number of stay days:";
                        cin>>d;
                        cout<<"Input number of people:";
                        cin>>peeps;
                        //creating reservation
                        newres.setall(Cname,ar,d,peeps);
                        california.addReservationInRoom(newres);//De douleuei i add reservation to room(res,int)!!!!!!!
                        pause = true;
                        break;
                    case 3:
                        cout<<"Input reservation code:";
                        cin>>rescode;
                        california.cancelReservation(rescode);
                        california.newavail(rescode);
                        pause = true;
                        break;
                    case 4:
                        california.printAllReservations();
                        pause = true;
                        break;
                    case 5:
                        california.printAllRooms();
                        pause = true;
                        break;
                    case 6:
                        california.graph_rep_hotel();
                        pause = true;
                        break;
                    case 7:
                        int room_no;
                        cout<<"Input an valid Room for income calculation or 0 for income sum calculation\n ";
                        cin>>room_no;
                        if (room_no>0 && room_no<12){
                            cout<<"Valid Room\n";
                            cout<<"Room: "<<room_no<< "Income:"<<california.pricing_calculator(room_no)<<endl;
                        }
                        else{
                            cout<<"Total Income:"<<california.pricing_calculator()<<endl;
                        }
                        pause = true;
                        break;
                    case 8:
                        cout<<"\t\tThank you!!!!\n\t\tExiting....";
                        validAnswer = true;
                        pause = true;
                        break;
                    default:
                        cout<<"\nerror_exiting\n";
                        pause = true;
                        break;

                }
            }while(!validAnswer);



    return 0;

}

void printmenu(){
    cout<<""<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"\n1. Next Round\n" <<
                        "2. Add Reservation\n" <<
                        "3. Cancel Reservation\n" <<
                        "4. Reservation Display\n"<<
                        "5. Room Display\n"<<
                        "6. Hotel Rooms Display\n"<<
                        "7. Income of Room or Hotel\n"<<
                        "8. Exit\n\n" ;
}


