// Project: WritingCode2
// Author: Charley Bein
// Class: CS315
// Last Update: 26-2-2018


#include <iostream>
#include <ctime>


using namespace std;

void quicksort (int[], int, int);
int partition(int[], int, int);

void insertSort(int[]);

void selectSort(int[]);

void mergeSort(int[], int, int);
void merge(int[], int, int, int);


int N = 10;

int main() {

    //Seed the random number generation based on current time
    srand(time(0));

    int A[N];
    int B[N];
    int C[N];
    int D[N];

    cout << "Initial randomized array:\n";
    for(int i = 0; i < N; i++){
        A[i] = (rand() % 50) + 1;
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];

        cout << A[i] << endl;
    }

    cout << endl;

    quicksort(A, 0, N);
    cout << "Quicksort:\n";
    for(int i = 0; i < N; i++){
        cout<<A[i] << endl;
    }

    cout << endl;

    insertSort(B);
    cout << "Insert Sort:\n";
    for(int i = 0; i < N; i++){
        cout << B[i] << endl;
    }

    cout << endl;

    selectSort(C);
    cout << "Selection Sort:\n";
    for(int i = 0; i < N; i++){
        cout << C[i] << endl;
    }

    cout << endl;

    mergeSort(D, 0, N);
    cout << "Merge Sort:\n";
    for(int i = 0; i < N; i++) {
        cout << D[i] << endl;
    }


    return 0;
}






//***********Quicksort****************
void quicksort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    }
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}
//**************************************

//*******Insertion Sort*****************

void insertSort(int A[]){
    int i, j, tmp;
    for (j = 1; j < N; j++){
        i = j;
        while (i > 0 && A[i - 1] > A[i]){
            tmp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = tmp;
            i = i - 1;
        }
    }
}

//****************************************

//************Selection Sort**************

void selectSort(int A[]){
    int i, j, min, tmp;
    for (i = 0; i < N - 1; i++){
        min = i;
        for ( j = i + 1; j < N; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if ( min != i){
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }
}

//**************************************

//*********Merge Sort*******************

void mergeSort(int A[], int p, int r){
    if (p < r){
        int q = (p + r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r){
// While loops based on http://www.sanfoundry.com/cpp-program-implement-merge-sort/

    int i, j, k, temp[r-p+1];
    i = p;
    k = 0;
    j = q + 1;

    while(i <= q && j <= r){
        if(A[i] < A[j]){
            temp[k] = A[i];
            k++;
            i++;
        } else {
            temp[k] = A[j];
            k++;
            j++;
        }
    }

    while ( i <= q){
        temp[k] = A[i];
        k++;
        i++;
    }

    while (j <= r){
        temp[k] = A[j];
        k++;
        j++;
    }

    for (i = p; i <= r; i++){
        A[i] = temp[i - p];
    }
}

//**************************************