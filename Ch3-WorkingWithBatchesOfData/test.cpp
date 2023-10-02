#include <iostream>
#include <string>
#include <iomanip>
using std::cout;

int main()
{
    std::string var1 = "this string";
    std::string var2 = "other string";

    float num = 1.4903232;

    std::streamsize cout_size = cout.precision(3);
    cout << cout_size << std::endl;
    cout.precision(cout_size);
    cout << num << std::endl;
    return 0;
}