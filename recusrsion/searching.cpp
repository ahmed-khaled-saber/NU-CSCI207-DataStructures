#include <iostream> 
using namespace std;

int linear_search(int* a, int n, int t){
    if(n <= 0){     
        return -1;  // Not found
    }else{
        if (a[n-1] == t){
            return n-1;
        }else{
            return linear_search(a, n-1, t);
        }
    }
}

bool linear_search(int* arr, int n,int target){

    if (n == 0){
        return false;
    }else{
        return arr[n-1] == target || linear_search(arr, n-1, target);
    }
}






bool binary_search(int* arr, int n, int start, int end, int t){
    if(start > end){
        return false;
    }
    else{
        if (arr[int(n/2)] == t){
            return true;
        }else{
            if(arr[int(n/2)] > t){
                binary_search(arr, n, start, n/2-1, t);
            }else{
                binary_search(arr, n, n/2+1, end, t);
            }
        }
    }
}


int main(){
    binary_search(arr, 10, 0, 9, 88);
}












int binary_search(int* a, int n, int t){
    if(n == 0){
        return -1;  // Not found
    }else{
        if(a[int(n/2)] == t){
            return int(n/2);
        }else{
            return binary_search(a, int(n/2), t);
        }
    }
}

int main(){
    int A[] = {5, 17, -2, 129, 7, 0, 89};
    cout<<"The index position of Value 5 at: " << linear_search(A, 7, 5)<<endl;
    int A_sorted[] = {-2, 0, 1, 5, 7, 77, 89};
    cout<<"The index position of Value 5 at: " << binary_search(A_sorted, 7, 5) + 1<<endl;

    return 0;
}