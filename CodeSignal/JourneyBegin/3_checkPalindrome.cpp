/*
Given the string, check if it is a palindrome.

Example

    For inputString = "aabaa", the output should be
    checkPalindrome(inputString) = true;
    For inputString = "abac", the output should be
    checkPalindrome(inputString) = false;
    For inputString = "a", the output should be
    checkPalindrome(inputString) = true.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] string inputString

    A non-empty string consisting of lowercase characters.

    Guaranteed constraints:
    1 ≤ inputString.length ≤ 105.

    [output] boolean

    true if inputString is a palindrome, false otherwise.
*/

bool checkPalindrome(string input) {
    int len = input.length();
    for(int i= 0; i < len/2; i++){
        if(input[i] != input[len-1-i]) return false;
    }
    return true;
}
