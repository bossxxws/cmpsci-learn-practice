#include <iostream>
using namespace std;
//What C and C++ recognize is {} and ; so that they can excute it,so you can write freely,but it is better to make it  more beautiful.
template<class T>
bool make2dArray(T**& x, int rows, int cols)
{
    try
    {
        x = new T * [rows];
        for (int i=0;i < rows; i++)
        {
            x[i] = new T [cols];
        }
        return true;
    }
    catch (bad_alloc) 
    {
        return false; 
    }
}
int main()
{
    int** array;
    int rows = 3;
    int cols = 4;

    if (make2dArray(array, rows, cols)) {
        // Initialization successful
        // Access and use the array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j] = i * cols + j;
                std::cout << array[i][j] << ' ';
            }
            std::cout << '\n';
        }

        // Clean up memory
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
    else {
        // Initialization failed
        std::cout << "Failed to allocate memory for the 2D array.\n";
    }

    return 0;
	system("pause");
}