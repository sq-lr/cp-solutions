#include <iostream>
#include <vector>
using namespace std;
struct Node {
    vector<int> children;
    int sub_size = 1;
};
Node arr[2*(int)1e5];
int func(int x)
{
    for(int i = 0; i < arr[x].children.size(); i++)
    {
        arr[x].sub_size += func(arr[x].children[i]);
    }
    return arr[x].sub_size;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x-1].children.push_back(i);
    }
    func(0);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].sub_size-1 << " ";
    }
}