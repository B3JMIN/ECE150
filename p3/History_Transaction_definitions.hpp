#ifndef _HISTORY_TRANSACTION_HPP_
#define _HISTORY_TRANSACTION_HPP_

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project3.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

//Transaction( std::string ticker_symbol,  unsigned int day_date,
//    unsigned int month_date,  unsigned year_date,
//    bool buy_sell_trans,  unsigned int number_shares,
//    double trans_amount )
//[
//    ~Transaction();
//    bool operator<(Transaction const&other);
//};

// Constructor
// TASK
//
Transaction::Transaction( std::string ticker_symbol,  unsigned int day_date,
unsigned int month_date,  unsigned year_date,
bool buy_sell_trans,  unsigned int number_shares,
double trans_amount )
{
    day = day_date;
    month = month_date;
    year = year_date;
    if (buy_sell_trans) {
        trans_type = "Buy";
    }
    else{
        trans_type = "Sell";
    }
    shares = number_shares;
    symbol = ticker_symbol;
    amount = trans_amount;
    trans_id = assigned_trans_id;
    assigned_trans_id += 1;
    acb = 0;
    acb_per_share = 0;
    share_balance = 0;
    cgl = 0;
    p_next = nullptr;
}


// Destructor
// TASK
//
// How to implement the destructor???
Transaction::~Transaction(){
//    clear the data in the transaction
    
}

// TASK
// Overloaded < operator.
//
bool Transaction::operator < (Transaction const &other)
{
    if (this->get_year() < other.get_year())
    {
        return true;
    }
    if (this->get_year() == other.get_year() && this->get_month() < other.get_month())
    {
        return true;
    }
    if (this->get_year() == other.get_year() && this->get_month() == other.get_month() && this->get_day() < other.get_day()) {
        return true;
    }
    else{
        return false;
    }
    
}
// GIVEN
// Member functions to get values. 
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
 unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values. 
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " " 
    << std::setw(4) << get_symbol() << " " 
    << std::setw(4) << get_day() << " "  
    << std::setw(4) << get_month() << " " 
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) { 
    std::cout << "  Buy  "; 
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " " 
    << std::setw(10) << get_amount() << " " 
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl() 
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK
//
History::History(){
    //p_head = History::get_p_head();
    this->p_head = nullptr;
}

// Destructor
// TASK
//
History::~History(){
//    we need to iterate all the linked list
    Transaction *p_deleted;
    while (p_head!=nullptr) {
        p_deleted = p_head;
        p_head = p_head->get_next();
        delete p_deleted;
    }
    
}


// TASK
// read_transaction(...): Read the transaction history from file. 
//
void History::read_history()
{
    ece150::open_file();
    Transaction *p_next_head;
    while (ece150::next_trans_entry()) {
        //std::cout << "a" << std::endl;
//        Transaction *p_next_head;
        p_next_head = new Transaction (ece150::get_trans_symbol(), ece150::get_trans_day(), ece150::get_trans_month(), ece150::get_trans_year(), ece150::get_trans_type(),  ece150::get_trans_shares(), ece150::get_trans_amount());
        insert(p_next_head);
    }
    ece150::close_file();
}

// insert(...): Insert transaction into linked list.
//
void History::insert( Transaction *p_new_trans ){
    Transaction *temp = p_head;
    //temp = p_head;
    if (temp == nullptr) {
        //p_new_trans->set_next(nullptr);
        p_head = p_new_trans;
    }
    else{
        while (temp->get_next() != nullptr) {
            temp = temp->get_next();
//            std::cout << "not nullptr" << std::endl;
        }
        //if (temp->get_next() == nullptr) {
            temp->set_next(p_new_trans);
//            std::cout << "Add a transaction" << std::endl;
       // }
    }
}


// TASK
// sort_by_date(): Sort the linked list by trade date.
//
void History::sort_by_date(){
    Transaction *p_sorted_head=nullptr;
    Transaction *to_sort=nullptr;
    Transaction *to_traverse=nullptr;
//    get the first one p_head and isolate it
    while (p_head !=nullptr) {
        to_sort = p_head;
        p_head = p_head->get_next();
        to_sort ->set_next(nullptr);
        if (p_sorted_head==nullptr) {
            p_sorted_head = to_sort;
        } else {
            if (*to_sort < *p_sorted_head) {
                to_sort->set_next(p_sorted_head);
                p_sorted_head = to_sort;
            }
            else
            {
                to_traverse = p_sorted_head;
                while (to_traverse->get_next()!=nullptr && *(to_traverse->get_next()) < *to_sort) {
                    to_traverse = to_traverse->get_next();
//                    std::cout << "larger" << std::endl;
                }
                to_sort->set_next(to_traverse->get_next());
                to_traverse->set_next(to_sort);
//                std::cout << "TEst" << std::endl;
            }
        }
    }
    
    p_head = p_sorted_head;
}



// TASK
// update_acb_cgl(): Updates the ACB and CGL values. 
//
void History::update_acb_cgl( )
{
    Transaction *p_to_get;
//    Set the first one
    p_head->set_acb(p_head->get_amount());
    p_head->set_share_balance(p_head->get_shares());
    p_head->set_acb_per_share(p_head->get_acb() / p_head->get_share_balance());
    p_to_get = p_head;
//    set for the rest
    while (p_to_get->get_next()!= nullptr) {
        Transaction *p_next=nullptr;
        p_next = p_to_get->get_next();
        if (p_next->get_trans_type() ) {
            p_next->set_acb(p_to_get->get_acb() + p_next->get_amount());
            p_next->set_share_balance(p_to_get->get_share_balance() + p_next->get_shares());
        }
        else{
            p_next->set_acb(p_to_get->get_acb() - p_next->get_shares() * p_to_get->get_acb_per_share());
            p_next->set_share_balance(p_to_get->get_share_balance() - p_next->get_shares());
            p_next->set_cgl(p_next->get_amount() - p_next->get_shares() * p_to_get->get_acb_per_share());
        }
        p_next->set_acb_per_share(p_next->get_acb()/p_next->get_share_balance());
        p_to_get = p_to_get->get_next();
    }
}


// TASK
// compute_cgl(): )Compute the ACB, and CGL.
//

double History::compute_cgl( unsigned int year )
{
    double result{0};
    Transaction *p_next{nullptr};
    p_next = p_head;
    while (p_next != nullptr) {
        if (p_next->get_year() == year) {
            result += p_next->get_cgl();
        }
        p_next = p_next->get_next();
    }
    return result;
}


// TASK
// print() Print the transaction history.
//

void History::print()
{
    //History::read_history();
    std::cout << "========= BEGIN TRANSACTION HISTORY =========" << std::endl;
    
    Transaction *p_traverse = p_head;

    while (p_traverse->get_next()!= nullptr) {
        p_traverse->print();
//        std::cout << "print once" << std::endl;
        p_traverse = p_traverse->get_next();
    }
     p_traverse->print();
    
    std::cout << "========= END TRANSACTION HISTORY =========" << std::endl;
}


// GIVEN
// get_p_head(): Full access to the linked list.
// 
Transaction *History::get_p_head() { return p_head; }


#endif

