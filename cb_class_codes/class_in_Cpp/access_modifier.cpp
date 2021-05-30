// lecture 27  

#include <iostream>

#include <cstring>

using namespace std;

class car // its is like a blue print,  uses no memory space.
{

private: //cant access outside thiss class
    int private_data;

public:
    int seats; //data types
    // char name[100];   // memory wasted;
    char *name;
    int modelno;
    int price;

    // methods or functions;

    // BY default there is a function " constructor " which is called wheneever we give instruction to bulid a object to construct or creat object;
    // this is method to override the default construction.

    car()
    {

        cout << " You are in constructor which is modified by you" << endl;
        name = NULL;
    }

    // there are two type of costructor , default(already present int ) and parametrised(need to be build by programmer)
    car(char *n, int s, int m, int price)
    {

        cout << "In parameterised constructor : " << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        seats = s;
        modelno = m;
        this->price = price;    // usse of this keyword ;
    }

    void printcar() // memeber function;

    {

        cout << endl
             << endl
             << "printing from print. " << endl;
        cout << "Name of car : " << name << endl;
        cout << "Model number : " << modelno << endl;
        cout << "Seats in car are " << seats << endl;
        cout << "You can buy at Rs " << price << endl;
    }

    void update(char *n)
    {

        if (name != NULL)
        {
            delete[] name;
            name = NULL;
        }

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void set_data(int pri_data) // SETTER
    {
        private_data = pri_data;
    }

    int get_private_data()
    {
        return private_data;
    }


    // copy constructor

    car(car &x){   // & is used so as to avoid the construction of another object name x
         
         cout << endl << "In copy constructor. "<< endl;
        // name =x.name;               //for shallow copy 
        name = new char[strlen(x.name)];  //for deep copy
        strcpy(name, x.name);
        price =x.price;
        seats = x.seats;
        modelno= x.modelno;

    }



    // copy assignment constructor;


    void operator=(car x)   // operator overloading
    {
         
         cout << endl << "In copy assignment constructor. "<< endl;
        // name =x.name;               //for shallow copy 
        name = new char[strlen(x.name)];  //for deep copy
        strcpy(name, x.name);
        price =x.price;
        seats = x.seats;
        modelno= x.modelno;
    }


    // destructor 

    ~car(){

        cout<< " dustructor for car "<< name << " called "<< endl;
    }
};

int main()
{
    car A;
    // strcpy(A.name,"Alto");  //it will not work for NULL pointer . null can not be accessed at any instant. it will give segmentation fault.
    A.update("Alto");
    A.seats = 4;
    A.price = 450000;
    A.modelno = 728;

    cout << "Name of car : " << A.name << endl;
    cout << "Model number : " << A.modelno << endl;
    cout << "Seats in car are " << A.seats << endl;
    cout << "You can buy at Rs " << A.price << endl;

    char c_name[] = "Dustur";
    car c(c_name, 8, 5433, 440000);

    cout << "Name of car : " << c.name << endl;
    cout << "Model number : " << c.modelno << endl;
    cout << "Seats in car are " << c.seats << endl;
    cout << "You can buy at Rs " << c.price << endl;

    c.printcar();

    // cant access private data or functions.
    // c.private_data=4;

    // getters and setters

    A.set_data(786); // setter

    int private_data_accessed = A.get_private_data(); //getter

    cout << "This is private data :  " <<private_data_accessed << endl;

    car d = c; // or car d(c),  constructor called ---> copy contructor

    d.printcar();

    // sallow copy and deep copy

    d.name[0]='M';  // shallow copy and deep copy.  see copy constructor for clrarity;
    c.printcar();
    d.printcar(); 


    // copy assignment constructor
     car e;
     e=c;   // operator overloading;


cout <<"car e details are : "<<endl;
     e.printcar();


}