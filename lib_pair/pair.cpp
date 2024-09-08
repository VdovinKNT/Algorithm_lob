#include "pair.h"

#ifdef EASY_EXAMPLE
#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"

int main() {
    int a, b;
    float result;

    a = 1; b = 4;

    try {
        result = division(a, b);
        std::cout << a << " / " << b << " = "
            << std::setprecision(2) << result << std::endl;
    }
    catch (std::exception err) {
        std::cerr << err.what() << std::endl;
    }

    a = 1; b = 0;

    try {
        result = division(a, b);
        std::cout << a << " / " << b << " = "
            << std::setprecision(2) << result << std::endl;
    }
    catch (std::exception err) {
        std::cerr << err.what() << std::endl;
    }

    return 0;
}

#endif  // EASY_EXAMPLE

#else
int main() {
    TPair<int, std::string> myPair(1, "example");

    std::cout << "Создана пара: " << myPair << std::endl;

    myPair.set_first(2);
    myPair.set_second("new_example");

    std::cout << "Обновленная пара: " << myPair << std::endl;

    return 0;
}
#endif

