#ifndef FUNCTION_HPP
#define FUNCTION_HPP


#include <iostream>
#include <string>

/** 
 * @brief Abstract base class representing a mathematical function.
 * 
 * This class provides an interface for evaluating functions,
 * computing their derivatives, and displaying information about them.
 */
class Function {
    protected:
        std::string name;

    public:
        Function(const std::string& i_name) : name(i_name) {}

        /**
         * @brief Evaluates the function at a given point x0.
         * 
         * This is a pure virtual method that must be implemented
         * by derived classes.
         * 
         * @param x0 The x value at which to evaluate the function.
         * @return The result of the evaluation f(x0) as a double.
         */
        virtual
        double eval(double x0) = 0;
        
        /**
         * @brief Computes the derivative of the function.
         * 
         * This is a pure virtual method that must be implemented
         * by derived classes.
         * 
         * @return A pointer to a new Function object representing the derivative.
         */
        virtual
        Function* derivative() = 0;

        /**
         * @brief Displays information about the function.
         * 
         * This is a pure virtual method that must be implemented
         * by derived classes.
         */
        virtual
        void display() = 0;
};

/** 
 * @brief Class representing a polynomial of degree 0.
 * 
 * This class inherits from Function and represents a constant function
 * of the form p(x) = k0.
 */
class Poly0 : public Function {
    private:
        double k0;

    public:
        Poly0(double i_k0) : Function("Poly0"), k0(i_k0) {}

        double eval(double x0) override {
            return k0;
        }

        Function* derivative() override {
            return new Poly0(0.0);
        }

        void display() override {
            std::cout << "This function is a Polynomial of degree 0." << std::endl;
            std::cout << "p(x) = " << k0 << std::endl;
        }
};

/** 
 * @brief Class representing a polynomial of degree 1.
 * 
 * This class inherits from Function and represents a linear function
 * of the form p(x) = k0 + k1*x.
 */
class Poly1 : public Function {
    private:
        double k0;
        double k1;
    
    public:
        Poly1(double i_k0, double i_k1) : Function("Poly1"), k0(i_k0), k1(i_k1) {} 

        double eval(double x0) override {
            return k0 + k1 * x0;
        }

        Function* derivative() override {
            return new Poly0(k1);
        }

        void display() override {
            std::cout << "This function is a Polynomial of degree 1." << std::endl;
            std::cout << "p(x) = " << k0 << " + " << k1 << ".x" << std::endl;
        }
};

/** 
 * @brief Class representing a polynomial of degree 2.
 * 
 * This class inherits from Function and represents a quadratic function
 * of the form p(x) = k0 + k1*x + k2*x^2.
 */
class Poly2 : public Function {
    private:
        double k0, k1, k2;
   
    public:
        Poly2(double i_k0, double i_k1, double i_k2) : Function("Poly2"), k0(i_k0), k1(i_k1), k2(i_k2) {} 

        double eval(double x0) override {
            return k0 + k1 * x0 + k2 * x0 * x0;
        }

        Function* derivative() override {
            return new Poly1(k1, 2 * k2);
        }

        void display() override {
            std::cout << "This function is a Polynomial of degree 2." << std::endl;
            std::cout << "p(x) = " << k0 << " + " << k1 << ".x + " << k2 << ".x^2" << std::endl;
        }
};



#endif 