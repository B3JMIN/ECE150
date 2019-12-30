#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <iomanip>
#include <iostream>
#include <string>
#include "Transaction.hpp"
#include "project3.hpp"

class History {
  public:
    // TASK
    // Constructor
    //
    History();
    
    // TASK
    // Destructor.
    //
    ~History();

    // TASK
    // Read the transaction history from file. 
    //
    void read_history();

    // TASK
    // Insert transaction in linked list.
    //
    void insert( Transaction *p_new_trans );

    void disconnect_trans( Transaction *prev, Transaction *curr );

    // TASK 
    // Sort using insertion sort.
    //
    void sort_by_date();

    // TASK
    // Update the acb members in the linked list.
    //
    void update_acb_cgl( );

    // TASK
    // Compute the ACB, and CGL.
    //
    double compute_cgl( unsigned int year );

    // TASK
    // Print the transaction history.
    //
    void print();

    Transaction *get_p_head();
  private:
    Transaction *p_head;
};

#endif 
