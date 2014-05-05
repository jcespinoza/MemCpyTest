#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Field{
    int type;
    int size;
    char* content;
};

int main()
{

    //Fixed lenght registries (49) with fixed lenght fields
    int aNumber = 18;
    char aString[40];
    cout << "Type something\n";
    cin >> aString;
    int anotherNumber = 20;

    //transform to bytes array
    char* cNumber = new char[sizeof(int)];
    char* cAnotherNumber = new char [sizeof(int)];
    memcpy(cNumber,&aNumber,sizeof(int));
    memcpy(cAnotherNumber, &anotherNumber,sizeof(int));
    cout << "Copying " << sizeof(int) << " bytes\n";
    cout << cNumber << "\n";
    cout << cAnotherNumber << "\n";


    //WRITE TO A FILE
    FILE* file;
    char buffer[sizeof(aString)+2*sizeof(int)];
    memcpy(buffer,cNumber,sizeof(int));
    memcpy(&buffer[4],aString,sizeof(aString));
    memcpy(&buffer[44],cAnotherNumber, sizeof(int));
    cout << "totalSize " << sizeof(buffer) << "\n";
    file = fopen("FixedLenght.jc","wb");
    fwrite(buffer,sizeof(char), sizeof(buffer),file);
    fclose(file);

    //READ FROM A FILE
    int readNumber;
    char readString[40];
    int readAnotherNumber;

    FILE* rFile;
    char rBuffer[2*sizeof(int)+sizeof(readString)];
    rFile = fopen("FixedLenght.jc","rb");
    if(rFile){
        fread(rBuffer, 1, sizeof(rBuffer),rFile);
        memcpy(&readNumber,&rBuffer[0],sizeof(int));
        memcpy(readString,&rBuffer[4],sizeof(readString));
        memcpy(&readAnotherNumber, &rBuffer[44],sizeof(int));

        cout << "\nREAD THE FILE - Results:\n";
        cout << "Buffer: " << rBuffer << "\n";
        cout << "Number: " << readNumber << "\n";
        cout << "String: " << readString << "\n";
        cout << "Number: " << readAnotherNumber << "\n";
    }else{
        cout << "Something happened";
    }


    return 0;
}

