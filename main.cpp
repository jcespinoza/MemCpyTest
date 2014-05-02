#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    //Fixed lenght registries (49) with fixed lenght fields
    int aNumber = 18;
    char* aString = new char [40];
    int anotherNumber = 20;

    //transform to bytes array
    char* cNumber = new char[sizeof(int)];
    char* cAnotherNumber = new char [sizeof(int)];
    memcpy(cNumber,&aNumber,sizeof(int));
    memcpy(cAnotherNumber, &anotherNumber,sizeof(int));
    cout << "Copying " << sizeof(int) << " bytes\n";
    cout << cNumber << "\n";
    cout << cAnotherNumber << "\n";

    //transform from bytes array
    int dNumber;
    int dAnotherNumber;
    memcpy(&dNumber, cNumber, sizeof(int));
    memcpy(&dAnotherNumber, cAnotherNumber, sizeof(int));
    cout << "Retrieving bytes\n";
    cout << dNumber << "\n";
    cout << dAnotherNumber << "\n";

    return 0;
}

