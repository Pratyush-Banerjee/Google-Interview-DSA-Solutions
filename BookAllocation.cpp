#include <iostream>
#include<vector> 
using namespace std;
bool isvalid(vector<int> &arr, int n, int m, int maxallowedpages){
    int students =1; 
    int pages=0;
    for (int i=0; i<n; i++){
        if (arr[i]>maxallowedpages){
            return false;
        }
    if(pages+arr[i]<=maxallowedpages){
        pages+=arr[i];
    } 
    else{
        students++;
        pages=arr[i];
    }
}
    return students>m ? false:true;
}


int allocatebooks(vector<int> &arr, int n, int m){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
int ans=-1;
int st=0, end=sum;
while (st<=end){
int mid=st+(end-st)/2;
if (isvalid(arr, n, m, mid)){//Left side search
    ans=mid;
    end=mid-1;
}else {//Right side search
    st=mid+1;
}
}
return ans;
}


int main (){
    vector<int> arr={2,1,3,4};
    int n=4;//number of books 
    int m=2;//number of students available
    cout<<"Number of minimum allocation="<<allocatebooks(arr, n, m)<<endl;
    return 0;
}