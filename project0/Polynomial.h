/**
    ECE250
    Polynomial.h
    Purpose: Class to represent a polynomial with a single variable.
    Provides services to add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

// Polynomial for single variable X

class Polynomial {

    // class variables
	private:
//	double    *coeff;  // coefficients
//	int size ;  // degree + 1
//    LinkedList Poly1;
//    LinkedList Poly2;
    int poly_size;
//    int poly2_size;
    LinkedList *poly_head;
    // class functions
    public:
    Polynomial (unsigned int size, LinkedList *input);
    Polynomial();
    ~Polynomial();

    // copy constructor and equal operator
//    Polynomial (const Polynomial &polynomial_to_copy);
//    Polynomial& operator=(const Polynomial& other) ;
//
//	/* comparison operator == and != */
//
//	bool operator==(const Polynomial& right );
//	bool operator!=(const Polynomial& right );
//
//    // add and +
//	Polynomial add( const Polynomial& right) const ;
//	Polynomial operator+(const Polynomial& right) ;
//
//	// multiply
//    Polynomial mult( const Polynomial& right) const ;
//    //evaluate a polynomial
//    double evaluate( const double &x) const ;
//    double evaluate_horner( const double &x) const ;
//    //
    void read_file();
    void get(LinkedList *expected_poly);
    void eval(unsigned int x, LinkedList *expected_val);
    
//    void coeff_p1(unsigned int m, LinkedList current_poly);
//    void coeff_p2(unsigned int m, LinkedList second_poly);
    void add( LinkedList *expected_poly);
    void mult(LinkedList *expected_poly);
    void exit();
    // print the polynomial
//    void print();

};


// I just write all the definition in this file


Polynomial::Polynomial(unsigned int size, LinkedList *input) {
    poly_size = size;
    poly_head = input;
}


// Blank constructor
Polynomial::Polynomial(){
    poly_head = nullptr;
    poly_size = 0;
}

// deconstructor
Polynomial::~Polynomial() {
    LinkedList *p_deleted;
    while(poly_head!=nullptr){
        p_deleted = poly_head;
        poly_head = poly_head->get_next();
        delete p_deleted;
    }
}

// function for reading file
void Polynomial::read_file(){
    // todo
}

// get the value
void Polynomial::get(LinkedList *expected_poly){
    LinkedList *temp = poly_head;
    
    while (temp->get_next()!=nullptr){
        if(temp->get_coeff() != expected_poly->get_coeff() or temp->get_power()!= expected_poly->get_power()){
            printf("failure");
        }else{
            temp = temp->get_next();
            expected_poly = expected_poly->get_next();
        }
    }
    std::cout<<"Success";
}

void Polynomial::eval(unsigned int x, LinkedList *expected_val){
    LinkedList *temp = poly_head;
    if(x < poly_size){
        std::cout<< "Failure";
    }else {
        while (int i=0, i<x, i++) {
            temp->get_next();
        }
        if (temp->get_power()== expected_val->get_power() and temp->get_coeff()==expected_val->get_coeff()){
            std::cout<<"Success";
        }else{
            std::cout<<"Failure";
        }
    }
}

// add function
void Polynomial::add(LinkedList *expected_poly){
    
}
