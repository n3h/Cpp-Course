#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
    int wszystkie = 0, biale = 0;
    for (int cnt = 1; ; cnt++) {
        cerr << "> ";
        string str;
        getline(cin,str);
        if (!cin) break;
        cout << setw(3) << cnt << ": \"" << str << "\"" << endl;
        wszystkie += str.length()+1;
            for(int i=0; i<str.length(); i++) {
                if (str[i]==32 || str[i]==9) biale++;
            }
        biale+=1;
        cout << "Ilosc przeczytanych linii: " << cnt << ", wszystkich znakow: " << wszystkie << ", bialych znakow: " << biale << endl;
    }
    cout << endl;
    return 0;
}
