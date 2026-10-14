#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canweplace(vector<int> &stall, int k, int mindist){
    int cowscount=1;
    int  lastposition=stall[0];
    for (int i=0; i<stall.size(); i++){
        if (k>stall.size()){
            return false;
        }
        if (stall[i]-lastposition>=mindist){
            cowscount++;
            lastposition=stall[i];
        } 
    }
    return cowscount>=k? true:false;
}
int aggressivecows(vector<int> &stall, int k){
    sort(stall.begin(), stall.end());
    int low=1;   //minimum distance is always 1
    int high= stall.back()- stall[0];
    int ans=-1;
    while (low<=high){
        int mid= low+(high-low)/2;
        if (canweplace(stall, k, mid)){// There are spaces available
            ans=mid;
            low=mid+1;
        }else { //Too crowdy, no adequate space 
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int k=3;
    vector<int> stall= {1,2,8,4,9};
    cout<<"Maximum of the minimum distances="<<aggressivecows(stall, k)<<endl;
    return 0;
}