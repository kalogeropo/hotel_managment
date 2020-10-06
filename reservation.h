#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>

using namespace std;

class reservation{
    private :
        string client_name;
        unsigned static int resver_code;
        int Date_of_arrival , Stay_days , no_of_customers,res_id;


    public :
    //setters getters
        string GetName(){return client_name;}
        void setName(string name){this->client_name = name;}
        void setdates (int , int , int);
        //might need get dates!!!!!!
        void setall(string , int ,int, int);
        int GetDoa(){return Date_of_arrival;}
        int GetSd(){return Stay_days;}
        int GetNoC(){return no_of_customers;}



        unsigned int getRes_code(){return res_id;}

        //constructors
        reservation();
        //reservation(string);
        reservation(string, int, int, int );
        //print method
        void ToString(); //override fuction if needed

};

#endif // RESERVATION_H
