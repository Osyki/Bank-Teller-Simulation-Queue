//
// Created by Jonathan Rubio on 10/28/21.
//

#ifndef HW4_BANK_TELLER_QUEUE_BANK_SIMULATOR_H
#define HW4_BANK_TELLER_QUEUE_BANK_SIMULATOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include "Customer.h"
#include "Teller.h"
#include "Random.h"

class Simulator
{
public:

    void run_simulation(int x, double y);  // start the simulation
    void output_statistics();  // print out the statistics
    void setTellers(int x);  // create number of teller
    std::vector<Teller> getTellers() const;  // return tellers vector


private:

    std::vector<Teller> tellers;
    std::queue<Customer*> the_customers;

};


#endif //HW4_BANK_TELLER_QUEUE_BANK_SIMULATOR_H
