#include<iostream>
using namespace std;

void test_array_address()
{
    int array[3][3] =
    {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    cout<< &array[0][0]<<" "<< &array[0][1]<<" "<< &array[0][2]<<" "<<endl;
    cout<< &array[1][0]<<" "<< &array[1][1]<<" "<< &array[1][2]<<" "<<endl;
    cout<< &array[2][0]<<" "<< &array[2][1]<<" "<< &array[2][2]<<" "<<endl;
}

int main()
{
    test_array_address();

    return 0;

}