#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct NumberRange
{
public:
    int min, max;
    NumberRange() : min(0), max(0) {}
    NumberRange(int m, int n) : min(m), max(n) {}
};

void Prime1();
std::vector<std::shared_ptr<NumberRange>> ReadAllNumberRanges();
int max(const std::vector<shared_ptr<NumberRange>> & vec);
vector<bool> InitMulArr(int max);
int RoundSqrt(int n, float guess);

void unmark(vector<bool> & vec, int num)
{
    if (!(vec[num])) return;
    int curr = num * 2;
    while (curr < vec.size())
    {
        // cout<<"unmarking "<<(curr)<<endl;
        vec[curr]=false;
        curr += num;
    }
}

// int main()
// {
//     Prime1();
//     return 0;
// }

void Prime1()
{
    auto vec = ReadAllNumberRanges();
    int maxVal = max(vec);
    int maxValRoundSqrt = RoundSqrt(maxVal, maxVal / 2);
    auto mulArr = InitMulArr(maxVal);
    
    // cout<<"maxValRoundSqrt:"<<maxValRoundSqrt<<endl;
    
    for (auto i = 2; i < maxValRoundSqrt; ++i)
    {
        // cout<<"entering unmark for " << i<<endl;
        unmark(mulArr, i);
    }
    
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        // cout<<"min "<<(*i)->min<<" max: "<<(*i)->max<<endl;
        for (auto j = (*i)->min; j <= (*i)->max; ++j)
        {
            if (mulArr[j] && j!=1)
                cout<<j<<endl;
        }
        if(i != vec.end())
            cout<<endl;
    }
}

std::vector<std::shared_ptr<NumberRange>> ReadAllNumberRanges()
{
    int size;
    // size = 2; // 
    cin>>size;
    std::vector<std::shared_ptr<NumberRange>> list;
    
    int min,max;
    for(int i = 0; i < size; ++i)
    {
        cin>>min>>max;
        list.push_back(std::make_shared<NumberRange>(min,max));
    }
    return list;
}

int max(const std::vector<shared_ptr<NumberRange>> & vec)
{
    int max = 0;
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if ((*i)->max > max)
            max = (*i)->max;
    }
    return max;
}

vector<bool> InitMulArr(int max)
{
    return vector<bool>(max + 1, true);
}

int RoundSqrt(int n, float guess)
{
    float p = guess * guess;
    if (n - p < 1)
        return guess;
    auto nextGuess = ((n / guess) + guess) / 2;
    return RoundSqrt(n, nextGuess);
}