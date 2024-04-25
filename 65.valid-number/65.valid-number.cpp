/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        string decimal = "[+-]?(([0-9]+\\.[0-9]*)|(\\.[0-9]+))";
        string integer = "[+-]?[0-9]+";
        string validNumber = "((" + decimal + ")|(" + integer + "))([eE]" + integer + ")?";
        cout << validNumber << '\n';
        regex numberRegex(validNumber, regex_constants::ECMAScript);
        smatch matchResult;
        regex_match(s, matchResult, numberRegex);
        if(matchResult.empty())return false;
        return matchResult[0].matched;
    }
};
// @lc code=end

