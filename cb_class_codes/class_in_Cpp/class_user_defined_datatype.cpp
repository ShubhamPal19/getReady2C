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


    // methods or functions;

    // BY default there is a function " constructor " which is called wheneever we give instruction to bulid a object to construct or creat object;
    // this is method to override the default construction.

    car()
    {   
      
        cout << " You are in constructor which is modified by you" <<endl;
        name=NULL;
    }

    
    // there are two type of costructor , default(already present int ) and parametrised(need to be build by programmer)
    car(char * n,int s, int m, int p)
    {

        cout << "In parameterised constructor : "<<endl;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        seats=s;
        modelno=m;
        price=p;
        
    } 


    void printcar()  // memeber function;
    
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



int main()
{
    car A;
    // strcpy(A.name,"Alto");  //it will not work for NULL pointer . null can not be accessed at any instant. it will give segmentation fault.
      A.update("Alto");
    A.seats=4;
    A.price=450000;
    A.modelno=728;

    cout<<"Name of car : "<< A.name<<endl;
    cout<<"Model number : "<< A.modelno<<endl;
    cout<<"Seats in car are "<< A.seats<<endl;
    cout<<"You can buy at Rs "<< A.price<<endl;


    char c_name[]="dustur";
    car c(c_name,8,5433,440000);

    
    cout<<"Name of car : "<< c.name<<endl;
    cout<<"Model number : "<< c.modelno<<endl;
    cout<<"Seats in car are "<< c.seats<<endl;
    cout<<"You can buy at Rs "<< c.price<<endl;


    c.printcar();
}