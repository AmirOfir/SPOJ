#include <iostream>
#include <vector>
#include <algorithm>
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
    
    // Answers for (a * b)
    vector<int> lhs;
    vector<int> rhs;
    
    for (int a = 0; a < n; ++a)
    for (int b = 0; b < n; ++b)
    for (int c = 0; c < n; ++c)
    {
        int r = ((items[a] * items[b]) + items[c]);
        lhs.push_back(r);
        if (items[a] != 0)
        {
            r = (items[a] *(items[b] + items[c]));
            rhs.push_back(r);
        }
    }
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    
    // for (auto const& value: lhs)
    // {
    //     cout<<" "<<value;
    // }
    // cout<<endl;
    // for (auto const& value: rhs)
    // {
    //     cout<<" "<<value;
    // }
    // cout<<endl;
    
    int count = 0; // counter
    auto first = rhs.begin();
    auto last = rhs.end();
    for (auto const& value: lhs)
    {
        // cout<<value<<": ";
        auto lower = std::lower_bound(first,last,value);
        // we have a match
        while (lower != last && !(value<*lower))
        {
            // cout<<*lower<<" ";
            ++count;
            ++lower;
        }
        // cout<<endl;
    }
    cout<<count;
    
    delete items;
    return 0;
}
