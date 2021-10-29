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
        //the_customers.push(new Customer(clock));

        //push customer into queue when time matches arrival rate
        if (clock == 0) {
            the_customers.push(new Customer(clock));
        } else if ((clock % int(arrival_rate_in_min)) == 0 ) {
            the_customers.push(new Customer(clock));
        }

        //check what tellers are free
        for (int i = 0; i < tellers.size(); i++) {
            if (tellers[i].is_free() && !the_customers.empty()) {
                tellers[i].start_service(clock,the_customers.front());
                the_customers.pop();
            }

        }
    }

}

std::vector<Teller> Simulator::getTellers() const {
    return tellers;
}
