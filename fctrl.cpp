#include <iostream>

using namespace std;

// Find the amount of trailing zeroes in a factorial.
// For instance 60! = 60*59*58... = 8320987112741390144276341183223364380754172606361245952449277696409600000000000000 
// has 14 trailing zeroes
// each time a 0 is added to a numer multiplying it keeps the zero, so counting the numbers of times a 5 is multiplied, and its powers (25,125..)

int main()
{
    int nums;
    cin>>nums;
    
    int inputNumber;
    int zeroes;
    int powered;
    for(int i = 0; i < nums; ++i)
    {
        cin >> inputNumber;
        zeroes = 0;
        powered = 5;
        for (int power = 0; power < 12 && powered <= inputNumber ; ++power)
        {
            zeroes += (int)(inputNumber / powered);
            powered *= 5;
        }
        cout<<zeroes;
        if (i < nums)
            cout<<endl;
    }
    
    return 0;
}
