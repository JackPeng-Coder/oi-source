#include <iostream>       //神奇头文件不用解释
#include <algorithm>
#define INF 10234567
using namespace std;             //额……@_@
int main()                                //不用递归
{
    int n,s[1001],ans=0,max=-INF;            //n表示输入有n个正整数，ans呢待会解释，max可以不用想了，一定是最后的答案,为什么被赋值为-INF下面解释
    cin>>n;                                               //输入n
    for(int i=1;i<=n;i++)                           //循环了n次
        cin>>s[i];                                    //将数存进s数组里，其实也可以不存，这样会更好理解
    for(int i=1;i<=n;i++)                          //仍旧循环n次，对n个数进行处理
    {                                                         //以下以样例为例来解释代码：10\n3 5 6 2 3 4 5 6 8 9
        if(s[i+1]-s[i]==1)ans++;             //i从1到n，当i=1时s[i+1]表示3后面一个数，即为5，如果5-3==1，就说明3，5是连号，这里显然不是。如果是就将ans++，所以这里的ans只是为了临时存一下连号的个数，以此类推。
        else ans=0;                                  //一旦发现了一次不连号，就将临时存储的数据变为0
        if(ans>max)max=ans;                 //将max赋为-INF的原因是为了找到ans中的最大值，达到题目目的
    }
    cout<<++max;                                  //最后输出最大值
}