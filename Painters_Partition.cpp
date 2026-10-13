#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

bool isvalid(vector<int> &board, int k, long long mid){
    long long workers=1; long long time=0;
    for (int i=0; i<board.size(); i++){
        if(board[i]>mid){
            return false;
        }
        if(time+board[i]<=mid){
            time+=board[i];
        } else {
            workers ++;
            time =board[i];
        }
    }
    return workers> k? false:true;
}


long long mintimetaken(vector<int> &board, int k){
    long long  st=*max_element(board.begin(), board.end());
    long long end=accumulate(board.begin(), board.end(), 0LL);
    long long ans=-1;
    while (st<=end){
        long long mid=st+(end-st)/2;
        if (isvalid (board, k, mid)){//Left searching
            ans =mid;
            end=mid-1;
        } else {//Right searching
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> board={40,30,10,20};
    int k=2; int n=4;
    cout<<"The minimum time taken for completion="<<mintimetaken(board, k)<<endl;
    return 0;
}