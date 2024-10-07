
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long index=-1;
    long long maxh=-1;
    for (auto i=0;i<n;i++){
        long long vvod;
        cin>>vvod;
        if (vvod>maxh){
            index=i+1;
            maxh=vvod;
        }
    }
    cout<<index<<'\n';
}



