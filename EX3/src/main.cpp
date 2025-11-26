#include "function.hpp"
#include <iostream>
#include <vector>

int main(){
    std::vector<Function*> functions;

    functions.push_back(new Poly0(6.0));
    functions.push_back(new Poly1(2.0, 5.0));
    functions.push_back(new Poly2(10.0, 3.0, 2.0));


    for (Function* function : functions) {
        function->display();
        double x0 = 1;
        std::cout << "The value of its derivative at point x=" << x0 << " is " << function->derivative()->eval(x0) << std::endl;
    }
}