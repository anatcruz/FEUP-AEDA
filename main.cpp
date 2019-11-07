#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        std::cout << "Hello, World!";
        string a;
        getline(cin, a);
        break;
    }
    return 0;
}