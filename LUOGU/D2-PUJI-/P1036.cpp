#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k;
vector<int> x(20);

bool isPrime(int num)
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int countCombinations(int start, int currentSum, int selected)
{
    // 如果已经选够k个数，判断和是否为素数
    if (selected == k)
    {
        return isPrime(currentSum) ? 1 : 0;
    }
    
    int result = 0;
    for (int i = start; i < n; i++)
    {
        result += countCombinations(i + 1, currentSum + x[i], selected + 1);
    }
    return result;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    cout << countCombinations(0, 0, 0) << endl;
    return 0;
}