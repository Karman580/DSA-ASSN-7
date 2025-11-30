#include <bits/stdc++.h>
using namespace std;

void improvedSelectionSort(vector<int>& a){
    int left=0,right=a.size()-1;
    while(left<right){
        int minIdx=left,maxIdx=right;
        for(int i=left;i<=right;i++){
            if(a[i]<a[minIdx]) minIdx=i;
            if(a[i]>a[maxIdx]) maxIdx=i;
        }
        swap(a[left],a[minIdx]);
        if(maxIdx==left) maxIdx=minIdx;
        swap(a[right],a[maxIdx]);
        left++;
        right--;
    }
}

int main(){
    vector<int>a={64,25,12,22,11,90,1,55};

    improvedSelectionSort(a);

    for(int x:a) cout<<x<<" ";
}
