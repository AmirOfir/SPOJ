// used C++14 GCC
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void Prime1();

int main()
{
    Prime1();
    return 0;
}

void Prime1()
{
    int count;
    cin>>count;
    
    for (int i = 0; i < count; ++i)
    {
        int min, max;
        cin>>min>>max;
        
        // emit 1
        if (min == 1) 
        {
            ++min;
        }
        // emit 2
        if (min == 2)
        {
            cout<<2<<endl;
            ++min;
        }
        // make boundries odd
        if (min % 2 == 0)
        {
            ++min;
        }
        if (max % 2 == 0)
        {
            --max;
        }
        
        int diff = max - min + 1;
        int size = diff;
        bool* arr = new bool[size];
        for(int q = 0; q < size; ++q)
            arr[q] = true;
        
        // The max item to check
        int maxToCheck = max / 2 < 32000 ? (int)(max / 2) : 32000;
        // cout<<"maxToCheck: "<<maxToCheck<<endl;
        bool* checks = new bool[maxToCheck];
        int checksMax = maxToCheck -2;
        int checksCurr = 0;
        for(int q = 0; q < maxToCheck; ++q)
            checks[q] = true;
        
        int firstToDevideByC, ci, q;
        for (int c = 2; c <= maxToCheck; ++c)
        {
            if (checks[checksCurr])
            {
                firstToDevideByC = c >= min ? (2*c) : min;// + (min % c);
                while (firstToDevideByC % c != 0)
                    ++firstToDevideByC;
                //cout<<"c: "<<c<<" firstToDevideByC:"<<firstToDevideByC<<endl<<"unmasking: ";
                
                for (ci = firstToDevideByC; ci <= max; ci += c)
                {
                    // if (ci != c)
                    // {
                        
                        // cout<<ind<<"("<<ci<<"), ";
                        arr[ci - min] = false;
                    // }
                }
                // cout<<endl;
                
                for (q = checksCurr; q < checksMax; q += c)
                    checks[q] = false;
            }
            ++checksCurr;
        }
        //cout << "done:" << endl;
        
        for (int d = 0; d < size; ++d)
        {
            if (arr[d])
            {
                cout<<(d + min)<<endl;
            }
        }
        
        delete checks;
        delete arr;
        
        if (i + 1 < count)
            cout<<endl;
    }
}
