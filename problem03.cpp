#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> ex;
      int left = 0;
      int ans = 0;
      for(int i = 0; i < s.length(); i++){
        int right = i;
        while(right < s.length() && !ex.count(s[right])){
          ex.insert(s[right++]);
        }
        ans = max(ans, int(ex.size()));
        ex.clear();
      }
      return ans;
    };

};

int main()
{
  Solution s;
  cout << s.lengthOfLongestSubstring("pwwkew");
  return 0;
}