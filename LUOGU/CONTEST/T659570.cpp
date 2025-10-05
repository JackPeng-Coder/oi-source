#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 读入 __int128 的函数，会返回读入的数。
__int128 read() {
    char c;
    bool isf = 0;
    while (!isdigit(c = getchar())) {
    	isf = (c == '-');
    }
    __int128 res = (c ^ 48);
    while (isdigit(c = getchar())) {
    	res = (res << 3) + (res << 1) + (c ^ 48);
    }
    return isf ? -res : res;
}

// 输出 __int128 的函数。需传入需要输出的数作为参数。
void write(__int128 x) {
    if (x < 0) {
    	putchar('-'), x = -x;
    } 
    if (x >= 10) {
    	write(x / 10);
    }
    putchar('0' + x % 10);
}

struct Cake
{
    __int128 C, D, X;
};

bool cmp(Cake cake1, Cake cake2)
{
    return cake1.X > cake2.X;
}

int main()
{
    __int128 N, sum = 0;
    N = read();
    vector<Cake> cakes(N);
    for (int i = 0; i < N; i++)
    {
        // cin >> cakes[i].C >> cakes[i].D >> cakes[i].X;
        cakes[i].C = read();
        cakes[i].D = read();
        cakes[i].X = read();
    }
    sort(cakes.begin(), cakes.end(), cmp);
    __int128 d = 0;
    for (auto cake : cakes)
    {
        sum += (2 * cake.D - (2 * d + cake.C - 1) * cake.X) * cake.C / 2;
        d += cake.C;
    }
    write(sum);
}