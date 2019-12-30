//
//  main.cpp
//  p3
//
//  Created by Cai Huichuan on 2019-11-24.
//  Copyright © 2019 Cai Huichuan. All rights reserved.
//
#include <iostream>
#include "project3.hpp"
#include "History_Transaction_definitions.hpp"
#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() {
//    std::cout << "Test" << std::endl;
History trans_history{};
trans_history.read_history();
std::cout << "[Starting history]:" << std::endl;
trans_history.print();
std::cout << "test" << std::endl;
trans_history.sort_by_date();
std::cout << "[Sorted ]:" << std::endl;
trans_history.print();
trans_history.update_acb_cgl();
trans_history.print();
std::cout << "[CGL for 2018 ]: " << trans_history.compute_cgl(2018) << std::endl;
std::cout << "[CGL for 2019 ]: " << trans_history.compute_cgl(2019) << std::endl;
return 0;
}
#endif
