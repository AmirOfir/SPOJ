#include <iostream>
using namespace std;

int main()
{
    int n;
    int curr;
    cin >> n;
    int *items = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> curr;
        items[i] = curr;
    }
    //counter
    int count = 0;
    
    for (int a = 0; a < n; ++a)
    {
        a = items[i];
        for (int b = 0; b < n; ++b)
        {
            b = items[i];
            for (int c = 0; c < n; ++c)
            {
                c = items[i];
                for (int d = 0; d < n; ++d)
                {
                    d = items[i];
                    if (d == 0) continue;
                    for (int e = 0; e < n; ++e)
                    {
                        e = items[i];
                        for (int f = 0; f < n; ++f)
                        {
                            bool b = (a * b) + c == d *(f + e);
                            if (b)
                                ++count;
                        }
                    }
                }
            }
        }
    }
    
    cout<<count;
    delete items;
    return 0;
}
