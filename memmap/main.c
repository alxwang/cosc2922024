#include <stdio.h>

int memoryMap(float x)
{
    static int i = 0;
    int a = 1235257896;
    double d = 9.0;
    float b = 3.2f;
    char c = 'a';
    short s = 10815;
    char cArray[] = "Hello";

    // Print the address of each variable
    // The "Address of" operator is the overloaded &
    // Note that %p is used for printing addresses in hexadecimal
    printf("The address of int i is \t%p\n", &i);
    printf("The address of int a is \t%p\n", &a);
    printf("The value of int a in hex is \t%x\n", a); // %x says print in hex
    printf("The value of a as a char is \t%c\n\n", a);

    printf("The address of double d is \t%p\n", &d);
    printf("The address of float b is \t%p\n", &b);
    printf("The address of char c is \t%p\n", &c);
    printf("The value of c in hex is \t%x\n\n", c);

    printf("The address of short s is \t%p\n", &s);
    printf("The value of s in hex is \t%x\n", s);
    printf("The value of s as a char is \t%c\n\n", s);

    // Note that the name of an array IS its address. & is not required.
    printf("The address of cArray is \t%p\n", cArray);
    printf("The address of cArray is \t%p\n", &cArray); // & will still work

    // Address of the parameter
    printf("The address of float x is \t%p\n", &x);

    // Print the address of the function itself.
    // Note that the name of the function stores its address.
    printf("The address of memoryMap is \t%p\n", memoryMap);

    // memoryMap(x + 1.0f); // continuous recursive call would cause stack overflow

    return 0;
}

int main() {
    float pi = 3.14159f;
    memoryMap(pi);
    return 0;
}
