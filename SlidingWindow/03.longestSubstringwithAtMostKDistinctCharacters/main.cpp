#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
   int lengthOfLongestSubstringKDistinct(string s, int k) {
      int ans = 0;  // Initialize the variable to store the length of the longest substring.
      unordered_map<char, int> m;  // Create a map to store character frequencies.
      int n = s.size();  // Get the size of the input string.
      int x = 0;  // Initialize the count of distinct characters.

      for (int j = 0, i = 0; j < n; j++) {
         m[s[j]]++;  // Update the frequency of character s[j] in the map.

         if (m[s[j]] == 1)
            x++;  // If s[j] is a new distinct character, increment the count.

         while (x > k && i <= j) {
            m[s[i]]--;  // Remove s[i] from the substring.
            if (m[s[i]] == 0)
               x--;  // Decrement the count if s[i] is no longer in the substring.
            i++;  // Move the left pointer to the right.
         }

         ans = max(ans, j - i + 1);  // Update the maximum substring length.
      }

      return ans;  // Return the length of the longest substring.
   }
};

int main() {
   Solution ob;
   cout << (ob.lengthOfLongestSubstringKDistinct("eceba", 2))<<endl;  // Test the function.
}
