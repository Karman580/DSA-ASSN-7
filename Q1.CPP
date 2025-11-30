#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& a) {
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIdx]) minIdx=j;
        }
        swap(a[i],a[minIdx]);
    }
}

void insertionSort(vector<int>& a) {
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(vector<int>& a) {
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void mergeArr(vector<int>& a,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    vector<int>L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(vector<int>& a,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int partitionArr(vector<int>& a,int low,int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(vector<int>& a,int low,int high){
    if(low<high){
        int pi=partitionArr(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main(){
    vector<int>a={64,25,12,22,11};
    vector<int>b=a,c=a,d=a,e=a;

    selectionSort(a);
    insertionSort(b);
    bubbleSort(c);
    mergeSort(d,0,d.size()-1);
    quickSort(e,0,e.size()-1);

    cout<<"Selection Sort: ";
    for(int x:a) cout<<x<<" ";

    cout<<"\nInsertion Sort: ";
    for(int x:b) cout<<x<<" ";

    cout<<"\nBubble Sort: ";
    for(int x:c) cout<<x<<" ";

    cout<<"\nMerge Sort: ";
    for(int x:d) cout<<x<<" ";

    cout<<"\nQuick Sort: ";
    for(int x:e) cout<<x<<" ";
}
