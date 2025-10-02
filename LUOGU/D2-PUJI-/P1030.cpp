#include <iostream>
using namespace std;

void before(string in, string after)
{
    if (in.size() > 0)
    {
        char root = after[after.size() - 1];
        cout << root;
        int index = in.find(root);
        before(in.substr(0,index),after.substr(0,index));
        before(in.substr(index+1),after.substr(index,in.size()-index-1));
    } 
}

int main()
{
    string in, after;
    cin >> in >> after;
    before(in, after);
}