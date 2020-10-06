#include "reservation.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int reservation::resver_code = 0;
void reservation::setall(string c_name , int Doa, int Sd , int no_c ){
    this->client_name=c_name;
    this->Date_of_arrival = Doa;
    this->Stay_days = Sd ;
    this->no_of_customers =no_c;
    this->res_id = resver_code;
    reservation::resver_code++;
}

//defult constractor
reservation::reservation(){

    this->client_name="error";
    this->Date_of_arrival = 0;
    this->Stay_days = 0 ;
    this->no_of_customers = 0;
    //this->res_id = resver_code;
    //reservation::resver_code++;
}
reservation::reservation(string c_name , int Doa, int Sd , int no_c ){
    this->client_name=c_name;
    this->Date_of_arrival = Doa;
    this->Stay_days = Sd ;
    this->no_of_customers =no_c;
    this->res_id =resver_code;
    reservation::resver_code++;
}
void reservation::ToString(){
    cout<<"Client name: " <<this->client_name << endl;
    cout<<"Date_of_arrival " <<this->Date_of_arrival << endl;
    cout<<"Days "<<this ->Stay_days << endl;
    cout<<"No_of_cust " <<this->no_of_customers << endl;
    cout<<"CODE of reservation " <<this->res_id << endl;
}
