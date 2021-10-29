//
// Created by Jonathan Rubio on 10/28/21.
//

#include "Customer.h"


extern Random my_random;

//Definition of static members
int Customer::total_customers_served = 0;
int Customer::total_delay_time = 0;


Customer::Customer(int the_arrival_time) {
    arrival_time = the_arrival_time;
    service_time = 1 + my_random.next_int(max_service_time);
    total_customers_served++;
}

void Customer::set_max_service_time(int the_max_service_time) {
    max_service_time = the_max_service_time;
}

int Customer::start_service(int time) {
    return 0;
}

