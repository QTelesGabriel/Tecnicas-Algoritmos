#include <iostream>
#include <stack>
#include <string>

bool expressaoCorreta(std::string& s) {
    std::stack<char> pilha;
    for(auto c : s) {
        if(c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(pilha.empty()) return false;
            char topo = pilha.top();
            pilha.pop();
            if ((c == ')' && topo != '(') || (c == ']' && topo != '[') || (c == '}' && topo != '{')) {
                return false;
            }
        }
    }

    return pilha.empty();
}

int main()
{
    std::string s;
    std::cin >> s;

    if(expressaoCorreta(s)) {
        std::cout << "OK" << std::endl;
    }
    else {
        std::cout << "SyntaxError" << std::endl;
    }

    return 0;
}