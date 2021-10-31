//
// Created by Jonathan Rubio on 10/28/21.
// Copyright [2021]

#include "Customer.h"


extern Random my_random;

void Customer::set_max_service_time(int the_max_service_time) {
    max_service_time = the_max_service_time;
}

Customer::Customer(int the_arrival_time) {
    //time customer arrive
    arrival_time = the_arrival_time;

    //how long it takes to service customer
    service_time = 1 + my_random.next_int(max_service_time);

    //increment total served customers
    total_customers_served++;
}

int Customer::start_service(int time) {
    delay_time = time - arrival_time;
    total_delay_time += delay_time;\
    return time + service_time;
}

int Customer::get_delay_time() const {
    return delay_time;
}

int Customer::get_arrival_time() const {
    return arrival_time;
}

int Customer::get_service_time() const {
    return service_time;
}

int Customer::get_total_delay_time() {
    return total_delay_time;
}

int Customer::get_total_customers_served() {
    return total_customers_served;
}

//Definition of static members
int Customer::max_service_time;
int Customer::total_customers_served = 0;
int Customer::total_delay_time = 0;
