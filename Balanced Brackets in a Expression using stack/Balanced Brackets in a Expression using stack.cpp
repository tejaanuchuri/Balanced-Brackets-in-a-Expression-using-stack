#include<iostream>
#include<stack>
using namespace std;

bool IsBalancedExpression(string str) {
	stack<char> s;
	for (unsigned int index = 0; index < str.length(); index++) {
		if (str[index] == '(' || str[index] == '[' || str[index] == '{') {
			s.push(str[index]);
			continue;
		}
		else if (s.empty()) {
			return false;
		}
		else if (str[index] == ')') {
			char x = s.top();
			s.pop();
			if (x == ']' || x == '}') {
				return false;
			}
		}
		else if (str[index] == ']') {
			char x = s.top();
			s.pop();
			if (x == ')' || x == '}') {
				return false;
			}
		}
		else if (str[index] == '}') {
			char x = s.top();
			s.pop();
			if (x == ']' || x == ')') {
				return false;
			}
		}
	}
	return s.empty();
}
int main()
{
	string s = "([]())";
	cout << IsBalancedExpression(s) << endl;
	string s = "([]{())";
	cout << IsBalancedExpression(s) << endl;
	string s = "([]({}))";
	cout << IsBalancedExpression(s) << endl;
	string s = "([]({{{{{{{{{))))))))";
	cout << IsBalancedExpression(s) << endl;
	return 0;
}
