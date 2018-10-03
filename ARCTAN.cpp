
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long a,b,sum,c,t;
    cin>>t;
    while (t--) {
        cin>>a;
        sum=1;
        sum<<=60;
        for(b=a+1;b<=2*a+1;b++) {
            if (0==(a*b+1)/(b-a))
                sum=min(sum, b+c);
        }
        cout<<sum<<endl;
    }
    return 0;
}