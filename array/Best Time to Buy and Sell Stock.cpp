#include <iostream>
#include <vector>
using namespace std;
int main(){
    int prices[4] = {3,2,2,3};
    int i=0,j=1;
        int maxx = 0;
        int bestprice = prices[0];
        while(j<4 && i<4){
            bestprice = min(bestprice,prices[i]);
            if(prices[i]>=prices[j]){
                j++;
            }
            
            else if(prices[i]<prices[j]){
                maxx = max(maxx,prices[j]-bestprice);
                j++;
            }
            
            i++;
        }
        cout << maxx;
}