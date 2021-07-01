#include <iostream>
#include <vector>

using namespace std;

// void sort(int a[], int n)
// {

//     for (int i = 0; i < n; i++)
//     {
//         int max = i;
//         for (int j = i + 1; j < n; j++)
//         {

//             if (a[j] < max)
//                 max = j;
//         }
//         swap(a[i], a[max]);
//     }
// }

vector<int> temp;

void printresult(int target, int array[], int I, int n)
{

    if (target == 0)
    {
       
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;

        return;
    }
    if (I == n)
    {
        return;
    }

    for (int i = I; i < n; i++)
    {
        if (array[i] <= target)
        {
            temp.push_back(array[i]);

            printresult(target - array[i], array, i + 1, n);
            temp.pop_back();
        }
    }
}
int main()
{

    int target;
    int *array, n;
  
    cin >> n;
    array = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cin >> target;

}
    printresult(target, array, 0, n);