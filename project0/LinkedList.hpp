//
//  LinkedList.hpp
//  project0
//
//  Created by Cai Huichuan on 2020-09-20.
//  Copyright © 2020 Cai Huichuan. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

class LinkedList {
public:
    LinkedList(unsigned int power, double coeff);
    ~LinkedList();
    unsigned int get_power() const;
    double get_coeff() const;
    LinkedList *get_next();
    
    void set_next(LinkedList *p_new_next);
private:
    unsigned int power;
    double coeff;
    LinkedList *p_next;
};

LinkedList::LinkedList(unsigned int power, double coeff){
    power = power;
    coeff = coeff;
}
LinkedList::~LinkedList(){
    // deconstruct
}
unsigned int LinkedList::get_power() const{
    return power;
}
double LinkedList::get_coeff() const{
    return coeff;
}
LinkedList *LinkedList::get_next(){
    return p_next;
}
//void LinkedList::set_power(unsigned int power){
//    power = power;
//}
//void LinkedList::set_coeff(double coeff){
//    coeff = coeff;
//}
void LinkedList::set_next(LinkedList *p_new_next){
    p_next = p_new_next;
}
#endif /* LinkedList_hpp */

