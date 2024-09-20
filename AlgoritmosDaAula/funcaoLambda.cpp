#include <bits/stdc++.h>

using namespace std;

int main()
{
    string vogais = "aeiou";
    string frase = "O rato roeu a roupa do rei de roma";
    string res;

    auto F = [&vogais](const char &c) {
        return vogais.find(tolower(c)) != string::npos;
    };

    copy_if(frase.begin(), frase.end(), back_inserter(res), F);

    cout << res << endl;

    return 0;
}