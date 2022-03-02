#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      int aP = a.length() - 1;
      int bP = b.length() - 1;
      cout << aP << ' ' << bP << endl;
      bool isEx = false; // 判断进位
      int resP = max(aP, bP);
      string result;
      vector<char> res;
      
      while(aP >= 0 && bP >= 0){
        bool toAdd = false;
        if(isEx)
          toAdd = true;
        if(a[aP] == '1' && b[bP] == '1'){
          isEx = true;
          if(toAdd)
            res.insert(res.begin(), '1');
          else
            res.insert(res.begin(), '0');
        }else if(a[aP] == '0' && b[bP] == '0'){
          isEx = false;
          if(toAdd)
            res.insert(res.begin(), '1');
          else
            res.insert(res.begin(), '0');
        }else{
          if(!toAdd){
            res.insert(res.begin(), '1');
            isEx = false;
          }else{
            res.insert(res.begin(), '0');
            isEx = true;
          }
        }
        aP--;bP--;
      }

      if(aP >= 0 && bP < 0){
        while(aP >= 0){
          if(a[aP] == '0'){
            if(isEx)
              res.insert(res.begin(), '1');
            else
              res.insert(res.begin(), '0');
            isEx = false;
          }
          if(a[aP] == '1'){
            if(isEx){
              res.insert(res.begin(), '0');
              isEx = true;
            }else
              res.insert(res.begin(), '1');
          }
          aP--;
        }
      }
      if(bP >= 0 && aP < 0){
        while(bP >= 0){
          if(b[bP] == '0'){
            if(isEx)
              res.insert(res.begin(), '1');
            else
              res.insert(res.begin(), '0');
            isEx = false;
          }
          if(b[bP] == '1'){
            if(isEx){
              res.insert(res.begin(), '0');
              isEx = true;
            }else
              res.insert(res.begin(), '1');
          }
          bP--;
        }
      }
      if(isEx)
        res.insert(res.begin(), '1');

      for(int i = 0; i < res.size(); i++){
        result += res[i];
      }
        
      return result;
    }
};

int main()
{
  string a = "1010", b = "1011";

  Solution s;
  cout << s.addBinary(a, b) << endl;
}