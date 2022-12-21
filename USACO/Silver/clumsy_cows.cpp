#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int num = 0;
  int count = 0;
  for(int i = 0; i < s.size(); i++)
    {
      if(s[i] == '(') num++;
      else num--;
      if(num < 0) 
      {
        count++;
        num = 1;
      }
    }
  if(num) count += num/2;
  cout << count;
}