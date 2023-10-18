#include <iostream>
#include <string>
#include <stack>
using namespace std;

string BracketMatcher(string str) {
  
 std::stack<char> bracketStack;

    // Iterate through each character in the input string
    for (char ch : str) {
        if (ch == '(') {
            // If an open bracket is encountered, push it onto the stack
            bracketStack.push(ch);
        } else if (ch == ')') {
            // If a closing bracket is encountered, check if there is a matching open bracket
            if (!bracketStack.empty() && bracketStack.top() == '(') {
                // If there is a matching open bracket, pop it from the stack
                bracketStack.pop();
            } else {
                // If there is no matching open bracket, return 0
                return "0";
            }
        }
    }

    // After processing the entire string, if the stack is empty, all brackets are matched
    // If the stack is not empty, there are unmatched open brackets
    return bracketStack.empty() ? "1" : "0";

}

int main(void) { 
   
  // keep this function call here
    std::string testStr1 = "(hello (world))";
    std::string testStr2 = "((hello (world))";
    std::string testStr3 = "No brackets in this string";

    // Call the BracketMatcher function and display the results
    std::cout << BracketMatcher(testStr1) << std::endl;  // Should print 1
    std::cout << BracketMatcher(testStr2) << std::endl;  // Should print 0
    std::cout << BracketMatcher(testStr3) << std::endl;  // Should print 1
  return 0;
    
}