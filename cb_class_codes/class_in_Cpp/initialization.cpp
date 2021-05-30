#include <iostream>
#include <cstring>


using namespace std;

class car    // its is like a blue print,  uses no memory space.
{
    public:
    int  seats;       //data types
    // char name[100];   // memory wasted;
    char * name;
    int modelno;
    int price;

    // const data member
    const int tyres; // must be initialised but cant do here because it is just blue print

    // static data members
    static int number_of_cars; // initialises only once;


    car(): tyres(4)
    {   
      
        cout << " You are in constructor which is modified by you" <<endl;
        name=NULL;
        number_of_cars++;
    }

    
    car(char * n,int s, int m, int p) : tyres(4), modelno(m),seats(s),price(p)  //intialisation list
    {

        cout << "In parameterised constructor : "<<endl;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        // seats=s;
        // modelno=m;
        // price=p;
        number_of_cars++;
        
    } 


    void printcar() 
    
    {

    cout <<endl<<endl<< "printing from print. "<<endl;
    cout<<"Name of car : "<< name<<endl;
    cout<<"Model number : "<< modelno<<endl;
    cout<<"Seats in car are "<< seats<<endl;
    cout<<"You can buy at Rs "<< price<<endl;
    }

    void update(char *n){

        if (name!=NULL)
        {
            delete []name;
            name=NULL;

        }
        
        name=new char[strlen(n)+1];
        strcpy(name,n);

    }
};

 int car :: number_of_cars=0;


int main()
{
    car A;
      A.update("Alto");
    A.seats=4;
    A.price=450000;
    A.modelno=728;

    cout<<"Name of car : "<< A.name<<endl;
    cout<<"Model number : "<< A.modelno<<endl;
    cout<<"Seats in car are "<< A.seats<<endl;
    cout<<"You can buy at Rs "<< A.price<<endl;
    cout<<"no of tyres :  "<< A.tyres<<endl;

    cout << "Total count of cars : ";
    cout <<car :: number_of_cars<<endl;


}