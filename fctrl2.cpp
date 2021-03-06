#include <iostream>
using namespace std;
// Each line represents the multiplication for a number (1..100)
// in the line, the first cell denotes the number for digits
// and then there are the digits, ordered from smaller to higher
// i.e. for 16! = 20922789888000, it the array mat[15,] will be [14,0,0,0,8,8,8,9,8,7,2,2,9,0,2,0,0,0,0,0...]

void multiply(int number, short *prevLine, short * currLine)
{
    short nums = 0;
    short curry = 0;
    for(int i = 1; i <= prevLine[0]; ++i)
    {
        short mul = (prevLine[i] * number) + curry;
        currLine[i] = mul % 10;
        curry = mul / 10;
        ++nums;
    }
    if (curry != 0)
    {
        // The number should be divided to few cells (each has value of o..9)
        while (curry != 0)
        {
            ++nums;
            currLine[nums] = curry % 10;
            curry /= 10;
        }
    }
    currLine[0] = nums;
}

void printLine(short * line)
{
    for(int i = line[0]; i >= 1; --i)
    {
        cout<<line[i];
    }
}

int main()
{
    short mat[100][159];
    
    // 1! = 1
    mat[0][0]=1;
    mat[0][1]=1;
    
    for(int i = 2; i <= 100; ++i)
    {
        multiply(i, mat[i - 2], mat[i - 1]);
        // cout<<endl<<i<<": ";
        // printLine(mat[i-1]);
    }
    
    int z,x;
    cin>>z;
    for (int i = 0; i < z; ++i)
    {
        cin>>x;
        printLine(mat[x - 1]);
        cout<<endl;
    }
    
    return 0;
}
