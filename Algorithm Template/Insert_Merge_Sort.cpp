#include <iostream>
#include <ctime>
template <class T>

void insertion_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (key<arr[j])){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(int a[],int start,int end){
    int mid = (start+end)/2;
    int lLength=mid-start+1;
    int rLength=end-mid;
    int la[lLength];
    int ra[rLength];
    for(int i=mid;i>=start;i--){
        la[i-start]=a[i];
    }
    for(int i=end;i>=mid+1;i--){
        ra[i-mid-1]=a[i];
    }
    int lIndex=0,rIndex=0;
    for(int i=start;i<=end;i++){
        if(lIndex!=lLength&&rIndex!=rLength){
            if(la[lIndex]<ra[rIndex]){
                a[i]=la[lIndex++];
            }else {
                a[i]=ra[rIndex++];
            }
        }else if(lIndex==lLength){
            a[i]=ra[rIndex++];
        }else {
            a[i]=la[lIndex++];
        }
    }
}
void mergeSort(int a[],int start,int end){
    if(end-start>0){
        mergeSort(a,start,(start+end)/2);
        mergeSort(a,(start+end)/2+1,end);
        merge(a,start,end);
    }
}

int main() {
    using namespace std;
    int ms[] = {2,3,5,1,0,8,6,9,7};
    int size = 9;

    cout<< "原数列:";

    for(int i = 0;i<size;i++)
    {
        cout<< ms[i] << " ";
    }

    cout<< "\n" << "归并排序后:";

    mergeSort(ms,0,size-1);

    for(int i = 0;i<size;i++)
    {
        cout<< ms[i] << " ";
    }
    return 0;
}
