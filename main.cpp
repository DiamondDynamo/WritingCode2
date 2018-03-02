// Project: WritingCode2
// Authors: Charley Bein, Ben Tipton
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

void swap(int[], int, int);


int N = 100000;
int RUNS = 10;

clock_t start, finish;
double runTime;

int main() {

//    freopen("out.txt", "w", stdout);

    //Seed the random number generation based on current time
    srand(time(0));

    int *A = new int[N];
    int *B = new int[N];
    int *C = new int[N];
    int *D = new int[N];

    float qAvg, iAvg, sAvg, mAvg;

    qAvg = 0;
    iAvg = 0;
    sAvg = 0;
    mAvg = 0;    

    for(int z = 0; z < RUNS; z++) {

//    cout << "Initial randomized array:\n";
        for (int i = 0; i < N; i++) {
            A[i] = (rand() % N) + 1;
            B[i] = A[i];
            C[i] = A[i];
            D[i] = A[i];

//        cout << A[i] << endl;
        }

        //cout << endl;

        start = clock();
        quicksort(A, 0, N - 1);
        finish = clock();
        runTime = (double(finish) - double(start)) / CLOCKS_PER_SEC;
        qAvg =+ runTime;
//        cout << "Quicksort: " << runTime << " s";
//    for(int i = 0; i < N; i++){
//        cout<<A[i] << endl;
//    }

//        cout << endl;

        start = clock();
        insertSort(B);
        finish = clock();
        runTime = (double(finish) - double(start)) / CLOCKS_PER_SEC;
        iAvg += runTime;
//        cout << "Insert Sort: " << runTime << " s";
//    for(int i = 0; i < N; i++){
//        cout << B[i] << endl;
//    }

//        cout << endl;

        start = clock();
        selectSort(C);
        finish = clock();
        runTime = (double(finish) - double(start)) / CLOCKS_PER_SEC;
        sAvg += runTime;
//        cout << "Selection Sort: " << runTime << "s";
//    for(int i = 0; i < N; i++){
//        cout << C[i] << endl;
//    }

//        cout << endl;

        start = clock();
        mergeSort(D, 0, N - 1);
        finish = clock();
        runTime = (double(finish) - double(start)) / CLOCKS_PER_SEC;
        mAvg += runTime;
//        cout << "Merge Sort: " << runTime << "s";
//    for(int i = 0; i < N; i++) {
//        cout << D[i] << endl;
//    }

//        cout << endl;

    }

    cout << "Quicksort Avg: " << qAvg/RUNS << " s\n";
    cout << "Insertion Sort Avg: " << iAvg / RUNS << " s\n";
    cout << "Selection Sort Avg: " << sAvg / RUNS << " s\n";
    cout << "Merge Sort Avg: " << mAvg / RUNS << " s\n";

    delete [] A;
    delete [] B;
    delete [] C;
    delete [] D;

    return 0;
}



void swap(int A[], int p, int r){
    int temp = A[p];
    A[p] = A[r];
    A[r] = temp;
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

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i = i + 1;
            swap(A, i, j);
        }

    }

    swap(A, i + 1, r);

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
