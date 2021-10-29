//
// Created by Jonathan Rubio on 10/28/21.
//

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

void Simulator::run_simulation(int max_time, double arrival_rate_in_min) {
    for (int clock = 0; clock < max_time; clock++) {
        the_customers.push(new Customer(clock));

        if (clock >=)
    }

}
