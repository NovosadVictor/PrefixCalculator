#include <iostream>
#include <string>
#include <stack>

void oper(std::stack<int> &S, char c);
int main()
{
	std::string s;
	std::string n = "";
	std::stack<int> S;
	std::getline(std::cin, s);
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (isdigit(s[i]))
		{
			n = s[i] + n;
			//std::cout << n << std::endl;
		}
		else
		{
			if (n.size() > 0)
			{
				S.push(stoi(n));
				n = "";
				//std::cout << S.top() << std::endl;
			}
			if (s[i] != ' ')
			{
				oper(S, s[i]);
				//std::cout << S.top() << std::endl;
			}
		}
	}
	std::cout << S.top() << std::endl;
	//system("pause");
	return 0;
}

void oper(std::stack<int> &S, char c)
{
	int a1, a2;
	a1 = S.top();
	S.pop();
	a2 = S.top();
	S.pop();
	switch (c)
	{
	case '+': {S.push(a1 + a2); break; }
	case '-': {S.push(a1 - a2); break; }
	case '*': {S.push(a1 * a2); break; }
	case '/': {S.push(a1 / a2); break; }
	default: return;
	}
}


