#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int ans = 0;

        while(start < end){
          int area = ((end - start) * min(height[start], height[end]));
          ans = max(ans, area);
          if (height[start] <= height[end])
          {
            start += 1;
          }else{
            end -=1;
          } 
        }
        
        return ans;
    }
    
};

int main() {
  Solution s;
  vector<int> height = {1,3,2,5,25,24,5};
  cout << s.maxArea(height) << endl;
}