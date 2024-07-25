#include <iostream>
using namespace std;



class Array {
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
public:
    Array() {
        size = 100;
        A = new int[100];
        length = 0;
    }
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array() {
        delete []A;
    }
    void Display();
    void Append();
    void Insert(int index, int x);
    int Linear_Search(int key);
    int Binary_Search(int key);
    int Get(int index);
    int Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int Average();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
}


void Array ::Display(){
    int i;
    printf("\n Element are \n");
    for(i=0;i<length;i++){
        printf(" %d",A[i]);
    }
}

void Array:: Append(int x){
    if(length <size){
        A[length++] = x;
        }
}
void Array:: Insert(int index, int x){
    int i;
    if(index >=0 && index <=length){
        for(i=length;i>index;i--){
            A[i] =A[i-1];
        }
        A[index]  =x;
        length++;
    }
};

int Array:: Linear_Search(int x){
    int i;
    for(i=0,i < length; i++){
        if(A[i] == x){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int Array :: Binary_Search(int key){
    int lower, mid, higher;
    lower =0;
    higher = length -1;
    while(lower <= higher){
        mid = (lower + higher) /2 ;
        if( key  == A[mid]){
            return mid;
        }
        else if(key < A[mid]){
            higher = mid -1;
        }
        else{
            lower = mid +1;
        }
    }
    return 0;

}

int Array :: Get(int index){
    if(index >=0; index < arr.length){
        return A[index];
    }
    return -1;
}


void Array :: Set(int index, int x){
    if(index >=0 && index < A[length]){
        A[index] =x;
    }
}


int Array ::Max(){
    int Max = A[0];
    int i;
    for(i =0; i<A.length;i++){
        if(A[i] > Max){
            Max = A[i]
        }

    }
    return Max;
}



template<class T>
void Array<T>::Display() {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template<class T>
void Array<T>::Insert(int index, T x) {
    if (index >= 0 && index <= length) {
        for (int i = length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = x; // This should be outside the loop
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index) {
    if (index >= 0 && index < length) {
        T x = A[index]; // This should be inside the conditional block
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    return T(); // Return a default value if index is invalid
}

int main() {
   Array arr(10);
    arr.Insert(0, 1);
    arr.Insert(1, 2);
    arr.Insert(2, 3);
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();
    return 0;
}
