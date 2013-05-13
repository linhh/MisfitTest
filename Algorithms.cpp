#ifndef  _ALGORITHMS_CPP_
#define  _ALGORITHMS_CPP_

#include <iostream>
#include <math.h>

#include <cstdlib>

using namespace std;

//---------------------------------------------------------
/*
    a. Given following method signature, print all the combinations of the numbers:
    void combinations(int maxNumber);
*/
void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << std::endl;
}

void swap(int *a, int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void permute(int *a, int k, int max)
{
    int i;

    if (k > 0) {
        for (i = k-1; i >= 0; --i ) {
            swap(a, i, k-1);
            permute(a, k-1, max);
            swap(a, i, k-1);
        }
    }
    else if (k == 0) {
        printArray(a, max);
    }
}

// the combinations method
void combinations(int maxNumber)
{
    if (maxNumber < 1) {
        return;
    }

    int *a = new int[maxNumber];
    int i;
    for (i = 0; i < maxNumber; ++i) {
        a[i] = i+1;
    }
    cout << "combinations of: ";
    printArray(a, maxNumber);
    permute(a, maxNumber, maxNumber);

    delete a;
}

//------ b. Given N numbers, how to find the minimum M numbers of them ---------------------------------------------
void findMinimumNumbers(int m, int n)
{
    int *a = new int[n];
    int i, j, min;

    for (i = 0; i < n; ++i) {
        a[i] = rand() % 10;
    }

    cout << "the minimum " << m << " number(s) in ";
    printArray(a, n);
    cout << " is: ";

    for (i = 0; i < m; ++i) {
        min = a[i];
        for (j = i+1; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                swap(a, i, j);
            }
        }
    }
    printArray(a, m);

    delete a;
}

//-------------------------------------------------------------------------------------------------------
/*
    d.Given a list of N people and let h be an unsorted array such that h( i) is the height of a person i. A
    person height is between 10cm and 400cm. If we form everyone in a line in an increasing order based
    on their height, what is the height of the middle person in this line?
*/

void sortArray(int *a, int n)
{
    int i, j;
    for (i = 0; i < n-1; ++i) {
        for (j = i+1; j < n; ++j) {
            if (a[j] < a[i]) {
                swap(a, i, j);
            }
        }
    }
}

void middlePerson(int n)
{
    int *a = new int[n];
    int i;

    // generate the data for test, random number from 10 - 400
    for (i = 0; i < n; ++i) {
        a[i] = (rand() % 390) + 10;
    }

    sortArray(a, n);
    cout << "input: ";
    printArray(a, n);

    i = (n-1) / 2;
    cout << "output: " << a[i];

    delete a;
}

//------------------------------------------------------------------------
/*
    i. Given two unsorted integer array a and b with same size, determine if a is an permutation of b with
    some solution better than sorting.

*/
#define N_SIZE 5
inline int numberTheSame(int *a, int *b, int n)
{
    int i, j, l = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (a[i] == b[j]) {
                l += 1;
                break;
            }
        }
    }
    return l;
}

void determinePermutation()
{
    int a[N_SIZE] = {1, 2, 3, 4, 5};
    int b[N_SIZE] = {3, 4, 2, 5, 1};
    int n, m;

    n = numberTheSame(a, b, N_SIZE);
    m = numberTheSame(b, a, N_SIZE);

    if (n == N_SIZE && m == N_SIZE) {
        cout << "true";
    } else {
        cout << "false";
    }
}

//----------------------------------------------------------------------------
/*
    f. Given an N*N matrix of integers, write code to rotate the matrix
*/
void printMatrix(int **a, int n)
{
    int i, j;
    cout << "Matrix: " << endl;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

#define MATRIX_SIZE 3
void rotateMatrix()
{
    // example matrix for test
    int n = MATRIX_SIZE;
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "original matrix: " << endl;
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //printMatrix(a, r, c);

    int rotatedMatrix[MATRIX_SIZE][MATRIX_SIZE];

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            rotatedMatrix[i][j] = matrix[n-j-1][i];
        }
    }

    cout << "rotated matrix: " << endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------------------------------------
/*
    g. Given two sorted integer array, find the Kth smallest element among both arrays.
*/
#define ARR_SIZE_A 5
#define ARR_SIZE_B 7
void findKthSmallestNumber(int k)
{
    int i;
    // generate data for test
    int a[ARR_SIZE_A];
    int b[ARR_SIZE_B];

    for (i = 0; i < ARR_SIZE_A; ++i) {
        a[i] = rand() % (2*ARR_SIZE_A);
    }

    for (i = 0; i < ARR_SIZE_B; ++i) {
        b[i] = rand() % (2*ARR_SIZE_B);
    }

    cout << "Array a: ";
    printArray(a, ARR_SIZE_A);
    cout << "Array b: ";
    printArray(b, ARR_SIZE_B);

    int loop, prevMin, curMin;

    prevMin = -1;
    curMin = a[0];
    for (loop = 0; loop < k; ++loop) {
        curMin = 1000000;
        for (i = 0; i < ARR_SIZE_A; ++i) {
            if (a[i] > prevMin && a[i] < curMin) {
                curMin = a[i];
            }
        }

        for (i = 0; i < ARR_SIZE_B; ++i) {
            if (b[i] > prevMin && b[i] < curMin) {
                curMin = b[i];
            }
        }
        prevMin = curMin;
    }

    cout << "the Kth smallest element among both arrays is: " << curMin;
}

// ----------------------------------------------------------
/*
    e. Given N total different shirts numbered from 1 to N and a number k of all different baskets
    (1<=k<=N). A basket can keep more than N shirts and at least 1 shirt. Now we need to keep each shirt
    in one of the K baskets. How many ways are there to keep these N shirts in k baskets?

*/
int factorial(int x)
{
    int i, r;
    r = 1;
    for (i = 2; i <= x; ++i) {
        r *= i;
    }
    return r;
}

void keepShirtInBasket(int n_shirt, int k_basket)
{
    int i, sum;
    sum = 0;

    for (i = 1; i < k_basket; ++i) {
        sum += (factorial(k_basket) / (factorial(i) * factorial(k_basket-i))) * pow(i, n_shirt);
    }
    int result = pow(k_basket, n_shirt);

}

#endif
//-------------------------------------------------------------------------------------
/*
int main()
{
    //combinations(1);
    //findMinimumNumbers(3, 12);
    //middlePerson(7);
    //determinePermutation();
    //rotateMatrix();
    findKthSmallestNumber(3);

    return 0;
}
*/
