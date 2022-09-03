#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    static bool comp(Job a,Job b){
       return a.profit>b.profit;
   }

    vector<int> JobScheduling(Job arr[], int n)
   {
       // your code here
       vector<int>v;
       sort(arr,arr+n,comp);
       int maxi=arr[0].dead;
       for(int i=0;i<n;i++){
           maxi=max(maxi,arr[i].dead);
       }
       vector<int>slot(maxi+1);
       for(int i=0;i<maxi+1;i++){
           slot[i]=-1;
       }
       int countjobs=0;
       int countprofit=0;
       for(int i=0;i<n;i++){
           for(int j=arr[i].dead;j>0;j--){
               if(slot[j]==-1){
                   slot[j]=1;
                   countjobs++;
                   countprofit+=arr[i].profit;
                   break;
               }
           }
       }
       v.push_back(countjobs);
       v.push_back(countprofit);
       return v;
    }

};

int main()
{
    return 0;
}
