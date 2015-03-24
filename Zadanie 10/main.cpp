#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    std::string polecenie;
    while (std::cin) {
        std::string linia;
        std::getline(std::cin, linia);
        istringstream isstream(linia);
        isstream >> polecenie;
        cout << endl << polecenie;

    }

    return 0;
}
