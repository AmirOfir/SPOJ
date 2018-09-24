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
    for (int b = 0; b < n; ++b)
    for (int c = 0; c < n; ++c)
    for (int d = 0; d < n; ++d)
    {
        if (items[d] == 0) continue;
        for (int e = 0; e < n; ++e)
        for (int f = 0; f < n; ++f)
        {
            bool b = (items[a] * items[b]) + items[c] == items[d] *(items[f] + items[e]);
            if (b)
                ++count;
        }
    }
    
    cout<<count;
    delete items;
    return 0;
}
