#include <iostream>
using namespace std;

int main()
{

    int **array;
    int rows , columns , i;

    cout<< "Enter the number of rows and columns : ";
    cin>> rows>> columns;
    array = (int **)new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        array[i]= (int *)new int[columns];


    }
    int count =0;

    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j]= count++;
        }
        
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
           cout << array[i][j]<< " ";
           
        }
        cout << endl;
    }


for(int i; i<rows;i++)
{
    delete []array[i];
}
    delete []array;
}
