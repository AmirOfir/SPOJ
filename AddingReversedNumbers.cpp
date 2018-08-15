// C++ 14

#include <iostream>

using namespace std;
int reverseNumber(int number)
{
    int result = 0;
    int devider = 10;
    int newNumber = number;
    
    while (newNumber != 0)
    {
        result = result * 10 + newNumber % 10;
        newNumber = (int)(newNumber / 10);
    }
    return result;
}

int main()
{
    int re, first,last;
    cin>>re;
    for(int i = 0; i < re; ++i)
    {
        cin>>first>>last;
        cout<<reverseNumber(reverseNumber(first) + reverseNumber(last));
        
        if (i + 1 < re)
            cout<<endl;
    }
    
    return 0;
}
