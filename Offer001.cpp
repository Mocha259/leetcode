#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
      if(a == INT_MIN && b == -1)
        return INT_MAX;
      if(a == 0)
        return 0;
      if(b == 1)
        return a;
      // 确定结果的正负号
      int isNeg = (a > 0) ^ (b > 0);
      a = a > 0 ? -a : a;
      b = b > 0 ? -b : b;
      // int是4字节，32位，0~31
      int ans = 0;
      while(a <= b){
        for(int i = 0; i < 32; i++){
          
          if((b << i) < a){
            // cout << "b:" << b << endl;
            cout << "b    :" << (b << i - 1) <<endl;
            a -= (b << (i - 1));
            ans += (1 << (i - 1));
            cout << "ans  : " << ans << endl;
            cout << "a    : " << a << endl;
            break;
          }
        }
      }
      
      return isNeg == 1 ? -ans : ans;
    }
};


int main(){
  Solution s;
  int a =15
  ;
  int b = 2;
  cout << s.divide(a, b);
}