#include <iostream>
#include "stack.h"

using namespace std;

string toPostfix(string str);
string toPrefix(string str);


int main()
{
    cout << "Hello world!" << endl;

    string reqs = "(CS102 or CS114) and (MATH225 or MATH220 or MATH241) and (MATH230 or MATH255 or MATH260)";

    cout << infixToPrefix(reqs) << endl;
    cout << infixToPostfix(reqs) << endl;
    return 0;
}

string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


string infixToPrefix(string str) {
    str = replaceAll(str, "and", "&");
    str = replaceAll(str, "or", "|");
    Stack st;
    string prefixExp = "";
    string tempPrefix = "";
    char tmp = '\0';

    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        char ch = *it;
        switch (ch) {
            case '(':
                st.push('(');
                break;
            case ')':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    tempPrefix = tmp + tempPrefix;
                    st.pop();
                    st.getTop(tmp);
                }
                prefixExp = prefixExp + tempPrefix;
                tempPrefix = "";
                break;
            case '&':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    tempPrefix = tmp + tempPrefix;
                    st.pop();
                    st.getTop(tmp);
                }
                st.push('&');
                break;
            case '|':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    tempPrefix = tmp + tempPrefix;
                    st.pop();
                    st.getTop(tmp);
                }
                st.push('|');
                break;
            default:
                tempPrefix += ch;
        }
    }

    while (st.pop(tmp))
        if (tmp != '(')
            prefixExp = tmp + prefixExp;
    return prefixExp;

}

string infixToPostfix(string str) {
    str = replaceAll(str, "and", "&");
    str = replaceAll(str, "or", "|");
    Stack st;
    string postfixExp = "";
    char tmp = '\0';

    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        char ch = *it;
        switch (ch) {
            case '(':
                st.push('(');
                break;
            case ')':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    postfixExp += tmp;
                    st.pop();
                    st.getTop(tmp);
                }
                break;
            case '&':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    postfixExp += tmp;
                    st.pop();
                    st.getTop(tmp);
                }
                st.push('&');
                break;
            case '|':
                tmp = '\0';
                st.getTop(tmp);
                while (!st.isEmpty() && tmp != '(') {
                    postfixExp += tmp;
                    st.pop();
                    st.getTop(tmp);
                }
                st.push('|');
                break;
            default:
                postfixExp += ch;
        }
    }

    while (st.pop(tmp))
        if (tmp != '(')
            postfixExp += tmp;
    return postfixExp;

}
