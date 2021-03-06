//
// Created by Jonathan Rubio on 10/28/21.
// Copyright [2021]

#include "Bank_Simulator.h"

Random my_random;

void Simulator::setTellers(int x) {
    tellers.resize(x);
}

void Simulator::output_statistics() {
    std::cout << "Total Customers Served: " << Customer::get_total_customers_served() << std::endl;
    double average_wait =
            double(Customer::get_total_delay_time()) / Customer::get_total_customers_served();
    std::cout << "Average Wait: " << average_wait << std::endl;
    std::cout << "Teller Total     Total    Total Average\n"
              << "       Customers Service  Idle  Idle\n"
              << "       Served    Time     Time  Time\n";
    for (size_t i = 0; i < tellers.size(); i++) {
        std::cout << std::setw(5) << i;
        std::cout << std::setw(9) << tellers[i].get_num_customers_served();
        std::cout << std::setw(7) << tellers[i].get_total_service_time();
        std::cout << std::setw(9) << tellers[i].get_total_idle_time();
        std::cout << std::setw(9) << std::setprecision(3)
                  << double(tellers[i].get_total_idle_time()) /
                     tellers[i].get_num_customers_served();
        std::cout << std::endl;
    }
}

void Simulator::run_simulation(int max_time, double arrival_rate) {
    //begin clock
    for (int clock = 0; clock < max_time; clock++) {
        //randomly push customers onto queue as needed
        if (my_random.next_double() < arrival_rate) {
            the_customers.push(new Customer(clock));
        }

        //check what tellers are free
        for (size_t i = 0; i < tellers.size(); i++) {
            //first check if tellers[i] is done with current customer
            if (!tellers[i].is_free() && (tellers[i].get_time_next_free() <= clock)) {
                tellers[i].end_service(clock);
            }

            //if teller[i] is free and queue is not empty, give them a customer and pop from queue
            if (tellers[i].is_free() && !the_customers.empty()) {
                tellers[i].start_service(clock, the_customers.front());
                the_customers.pop();
            }
        }
    }
}

std::vector<Teller> Simulator::getTellers() const {
    return tellers;
}
