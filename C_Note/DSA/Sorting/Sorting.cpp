/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include "Sorting.h"
#include "stdio.h"
#include "array"
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

/*Create an array of random numbers with length k*/
void Sorting::CreateArray(int k){
    NumList = new int[k];
    for (int i=0; i<k; i++){
        NumList[i] = rand()%(k+10);
    }
    num = k;
}

/*Copy the created array*/
int* Sorting::CopyArray(){
    int* list = new int[num];
    for(int i=0; i<num; i++){
        list[i] = *(NumList+i);
    }
    return list;
}

void Sorting::Print(int* NumList){
    for(int i=0; i<num; i++){
        cout << NumList[i] << ",";
    }
    cout << endl;
}

/**==========================For Bubble Sort===================================*/
void Sorting::BubbleSort(int* NumList){
    //Write your code here. 
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (NumList[j] > NumList[j + 1]) {
                int temp = NumList[j];
                NumList[j] = NumList[j + 1];
                NumList[j + 1] = temp;
            }
        }
    }
}

/**==========================For Insertion Sort===================================*/
void Sorting::InsertSort(int* NumList){
    //Write your code here.
    for (int i = 1; i < num; i++)
    {
        int key = NumList[i];
        int j = i - 1;
        while (j >= 0 && NumList[j] > key)
        {
            NumList[j + 1] = NumList[j];
            j--;
        }
        NumList[j + 1] = key;
    }
}

/**==========================For Merge Sort===================================*/

/*Merge two sorted array. Used in MergeSort*/
void Merge(int* NumList, int start, int mid, int end){      
    //Write your code here.
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = new int[n1];
    int* right = new int[n2];
    for (int i = 0; i < n1; i++)
        left[i] = NumList[start + i];
    for (int i = 0; i < n2; i++)
        right[i] = NumList[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            NumList[k++] = left[i++];
        }
        else
        {
            NumList[k++] = right[j++];
        }
    }
    while (i < n1)//left still have component
        NumList[k++] = left[i++];
    while (j < n2)//right still have component
        NumList[k++] = right[j++];
}

void Sorting::MergeSort(int* NumList, int start, int end){
    //Write your code here.
    if (start < end) {
        int center = (start + end) / 2;
        MergeSort(NumList, start, center);
        MergeSort(NumList, center + 1, end);
        Merge(NumList, start, center, end);
    }
}

/**==========================For Quick Sort===================================*/
/*Swap the i'th and j'th element in the array*/
void Swap(int* NumList, int i, int j){
    //Write your code here.
    int temp = NumList[j];
    NumList[j] = NumList[i];
    NumList[i] = temp;
}

int MedianOfThree(int* NumList, int begin, int tail){
    //Write your code here.
    int center = (begin + tail) / 2;
    if (NumList[center] < NumList[begin])
        Swap(NumList, begin, center);
    if (NumList[tail] < NumList[begin])
        Swap(NumList, begin, tail);
    if (NumList[tail] < NumList[center])
        Swap(NumList, center, tail);
    Swap(NumList, center, tail - 1);
    return NumList[tail - 1];

}

int Partition(int* NumList, int begin, int tail){  
    //Write your code here.
    double pivot = MedianOfThree(NumList, begin, tail);
    int i = begin;
    int j = tail - 1;
    while (i < j) {
        while (NumList[++i] < pivot) {};
        while (NumList[--j] > pivot) {};
        if (i < j)
            Swap(NumList, i, j);
        else
            break;
    }
    Swap(NumList, i, tail - 1);
    return i;
}

void Sorting::QuickSort(int* NumList, int begin, int tail){
    //Write your code here.
    int pivot;
    if (begin < tail) {
        pivot = Partition(NumList, begin, tail);
        QuickSort(NumList, begin, pivot - 1);
        QuickSort(NumList, pivot + 1, tail);
    }
   
}


/**==========================For Heap Sort===================================*/

/**Maintain max-heap order*/
void percolateUp(int* heap, int currentSize) {
    //Write your code here.
    int idx = currentSize;
    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        idx = idx / 2;
    }

}

/**Append an element to the end of heap, and adjust heap to maintain the max-heap order.*/
void InsertHeap(int* heap, int& currentSize, const int ele){
    //Write your code here.
    heap[++currentSize] = ele;
    percolateUp(heap, currentSize);
    
}

/*Construct a max heap (Parent larger than its children)*/
int* BuildMaxHeap(int* NumList, int num){
    //Write your code here.
    int* heap = new int[num + 1];
    int currentSize = 0;
    for (int i = 0; i < num; i++) {
        InsertHeap(heap, currentSize, NumList[i]);
    }
    return heap;

}

/**Adjust heap to maintain the heap order*/
void percolateDown(int* MaxHeap, int currentSize){   
    //Write your code here.
    int hole = 1;
    int tmp = MaxHeap[hole];
    while (hole * 2 < currentSize) {
        int child = hole * 2;
        if (MaxHeap[child] < MaxHeap[child + 1]) {
            child = child + 1;
        }
        if (MaxHeap[child] > tmp) {
            MaxHeap[hole] = MaxHeap[child];
            hole = child;
        }
        else break;
    }
    MaxHeap[hole] = tmp;
    
}


void DeleteMin(int* MaxHeap, int& currentSize){
    //Write your code here.
    int max = MaxHeap[1]; //Save the top element.
    MaxHeap[1] = MaxHeap[currentSize];  //Move the end element of MaxHeap to the top;
    percolateDown(MaxHeap, currentSize);  //Adjust MaxHeap to maintain the heap structure.
    MaxHeap[currentSize] = max; //Append the previous top element to the end of heap;
    currentSize--;

}


void Sorting::HeapSort(int* NumList){
    //Write your code here.
    int* MaxHeap = BuildMaxHeap(NumList, num); 
    int currentSize = num;
    while (currentSize > 0) {
        DeleteMin(MaxHeap, currentSize);
    }
    for (int i = 0; i < num; i++) NumList[i] = MaxHeap[i + 1];

}



/*
 * 
 */
int main(int argc, char** argv) {
    Sorting s;
    int t = 15; //You may try different numbers here, e.g. from 3 to 17.
    int num = pow(2, t); 
    s.CreateArray(num);  //Created an Array "A" with "num" elements.
    clock_t start;
    double duration; //Time duration of running each sorting algorithm.

    
    int* BubbleSortList = s.CopyArray();  //Copy array "A" for BubbleSort.
    // cout << "Original Array: " << endl;
    // s.Print(BubbleSortList);
    start = std::clock();    //Start timer.
    s.BubbleSort(BubbleSortList);       //Run sorting algorithm;
    // cout << "Bubble Sort Array: " << endl;
    // s.Print(BubbleSortList);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  //Record running time.
    cout << "Bubble Sort needs time: " << duration << endl;

    
    int* InsertSortList = s.CopyArray();
    start = std::clock();
    s.InsertSort(InsertSortList);
    // cout << "Insertion Sort Array: " << endl;
    // s.Print(InsertSortList);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  
    cout << "Insertion Sort needs time: " << duration << endl;

    int* MergeSortList = s.CopyArray();
    start = std::clock();
    s.MergeSort(MergeSortList, 0, num-1);
    // cout << "Merge Sort Array: " << endl;
    // s.Print(MergeSortList);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  
    cout << "Merge Sort needs time: " << duration << endl;

    
    int* QuickSortList = s.CopyArray();
    start = std::clock();
    s.QuickSort(QuickSortList, 0, num-1);
    // cout << "Quick Sort Array: " << endl;
    // s.Print(QuickSortList);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Quick Sort needs time: " << duration << endl;


    int* HeapSortList = s.CopyArray();
    start = std::clock();
    s.HeapSort(HeapSortList);
    // cout << "Heap Sort Array: " << endl;
    // s.Print(HeapSortList);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Heap Sort needs time: " << duration << endl;

    return 0;
}

