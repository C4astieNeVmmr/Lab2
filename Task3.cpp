#include <iostream>
using namespace std;

int main(){
    int arr0[10],arr1[10],*arr2 = new int[10],*arr3 = new int[10],index,*ptr;

    //static array with indexes
    for(index=0;index<10;index++){
        arr0[index] = index*index+0;
    }

    //static array with pointers
    for(ptr=arr1;ptr<arr1+10;ptr++){
        *ptr = (ptr-arr1)*(ptr-arr1)+1;
    }

    //dynamic array with indexes
    for(index=0;index<10;index++){
        arr2[index] = index*index+2;
    }

    //dynamic array with pointers
    for(ptr=arr3;ptr<arr3+10;ptr++){
        *ptr = (ptr-arr3)*(ptr-arr3)+3;
    }


    for(int i=0;i<10;i++){
        cout << arr0[i] << "\t" << arr1[i] << "\t" << arr2[i] << "\t" << arr3[i] << endl;
    }
    delete arr2,arr3;
    return 0;
}