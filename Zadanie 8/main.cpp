#include <iostream>
#include <typeinfo>
#include "newstring.h"

using namespace obliczenia;
using std::cout;
using std::endl;

int main()
{
        try {
        /*
        cout << "Testowanie konstruktorow standardowych: " << endl;

        newstring n1(static_cast<std::string>("testowy napis"));
        cout << "String: " << n1 << endl;

        newstring n2(static_cast<int>(-368));
        cout << "int: " << n2 << endl;

        newstring n2b(static_cast<int>(208));
        cout << "int: " << n2b << endl;

        newstring n2c(static_cast<int>(0));
        cout << "int: " << n2c << endl;

        newstring n3(static_cast<double>(-368.432));
        cout << "double: " << n3 << endl;

        newstring n3b(static_cast<double>(41.460));
        cout << "double: " << n3b << endl;

        newstring n4(static_cast<bool>(5));
        cout << "bool: " << n4 << endl;

        newstring n4b(static_cast<bool>(0));
        cout << "bool: " << n4b << endl;

        newstring n5(static_cast<char>(75));
        cout << "char: " << n5 << endl;

        newstring n5b(static_cast<char>('c'));
        cout << "char: " << n5b << endl;

        //!
        std::string n6x = "napis n6";

        void *ptr1 = &n6x;
        newstring n6(ptr1);
        cout << "ptr1: " << ptr1 << ", n6: " << n6 << endl;
        */
        cout << "Testowanie konwersji niejawnej: " << endl;

        newstring m1 = static_cast<std::string>("testowy napis");
        cout << "String: " << m1 << endl;

        //newstring m2 = static_cast<int>(-368);
        newstring m2 = -368;
        cout << "int: " << m2 << endl;

        newstring m2b = static_cast<int>(208);
        cout << "int: " << m2b << endl;

        newstring m2c = static_cast<int>(0);
        cout << "int: " << m2c << endl;

        //newstring m3 = static_cast<double>(-368.432);
        newstring m3 = -368.432;
        cout << "double: " << m3 << endl;

        newstring m3b = static_cast<double>(41.46);
        cout << "double: " << m3b << endl;

        //newstring m4 = static_cast<bool>(5);
        newstring m4 = true;
        cout << "bool: " << m4 << endl;

        newstring m4b = static_cast<bool>(0);
        cout << "bool: " << m4b << endl;

        newstring m5 = static_cast<char>(75);
        cout << "char: " << m5 << endl;

        //newstring m5b = static_cast<char>('c');
        newstring m5b = 'c';
        cout << "char: " << m5b << endl;

        std::string m6x = "napis m6";

        void *ptr2 = &m6x;
        newstring m6 = ptr2;
        cout << "ptr2: " << ptr2 << ", m6: " << m6 << endl;

        cout << endl << endl << "Testowanie operatorow konwersji: " << endl;

        std::string o1 = m1;
        cout << "String: " << o1 << endl;

        int o2 = m2;
        cout << "int: " << o2 << endl;

        int o2b = m2b;
        cout << "int: " << o2b << endl;

        int o2c = m2c;
        cout << "int: " << o2c << endl;

        double o3 = m3;
        cout << "double: " << o3 << endl;

        double o3b = m3b;
        cout << "double: " << o3b << endl;

        bool o4 = m4;
        cout << "bool: " << o4 << endl;

        bool o4b = m4b;
        cout << "bool: " << o4b << endl;

        char o5 = m5;
        cout << "char: " << o5 << endl;

        char o5b = m5b;
        cout << "char: " << o5b << endl;
        //m6[3] = 'h'; // bad_cast
        void* o6 = m6;
        cout << "void *: " << o6 << endl;

        cout << endl << endl << "Testowanie operacji: " << endl;

        newstring t1 = newstring (static_cast<std::string>("abcdefghijklmnopr"));
        cout << "t1: " << t1 << endl;

        t1 += static_cast<int>(44);
        cout << "t1 += (int)44: " << t1 << endl;

        t1 += static_cast<double>(-1.34);
        cout << "t1 += (double)-1.34: " << t1 << endl;

        newstring t2 = 1234;

        newstring t3;
        t3 = t2 + t1;
        cout << "t2: " << t2 << endl;
        cout << "t3 = t2 + t1: " << t3 << endl;

        cout << "t2.length(): " << t2.length() << endl;

        cout << "t2.append(t3): " << t2.append(t3) << endl;

        cout << "t2.erase(8, 4): " << t2.erase(8, 4) << endl;

        cout << "t2.replace(8, 2, n2): " << t2.replace(8, 2, m2) << endl;

        cout << "t2.substr(3, 10): " << t2.substr(3, 10) << endl;

        // DODAWANIE
        cout << endl << endl << "Testowanie dodawania: " << endl;

        newstring d1 = 2456;
        cout << "d1: " << d1 << endl;

        d1 += (int)999;
        d1 = d1 + static_cast<int>(40);
        cout << "d1 = d1 + (int)40: " << d1 << endl;
        d1 = d1 + static_cast<double>(-13.34);
        cout << "d1 = d1 + (double)-13.46;: " << d1 << endl;

        d1 = d1 + static_cast<bool>(5);
        cout << "d1 = d1 + (bool)5: " << d1 << endl;

        d1 = d1 + static_cast<char>(76);
        cout << "d1 = d1 + (char)76: " << d1 << endl;

        d1 = d1 + static_cast<void *>(&d1);
        cout << "d1 = d1 + (void *)&d1: " << d1 << endl;

        d1[0] = 75;
        cout << d1[1];
        cout << endl << "d1[0] = 9:f " << d1 << endl;

        newstring e1 = static_cast<std::string>("abe");
        newstring e2 = static_cast<std::string>("abd");
        (e1 > e2) ? cout << "e1 wieksze" : cout << "e2 wieksze";

    } catch (std::bad_cast& e) {
        std::cerr << "Wystapil wyjatek \"bad_cast\"" << "\n";
        std::cerr << e.what() << "\n";
    } catch (std::string blad) {
        std::cerr << blad;
    }
    return 0;
}
