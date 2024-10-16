#include <iostream>
#include "Automovel.h"

using namespace std;

int main() {
    Automovel a("AA-24-88", 80.0, "BMW", "320d");
    cout << a.toString();
    return 0;
}
