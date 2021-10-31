//
// Created by Jonathan Rubio on 10/28/21.
// Copyright [2021]

#include "Teller.h"

Teller::Teller() {
    free = true;
    time_next_free = 0;
    num_customers_served = 0;
    time_service_started = 0;
    time_service_ended = 0;
    total_service_time = 0;
    total_idle_time = 0;
    currentCustomer = NULL;
}

bool Teller::is_free() const {
    return free;
}

int Teller::get_time_next_free() const {
    return time_next_free;
}

int Teller::get_total_service_time() const {
    return total_service_time;
}

int Teller::get_total_idle_time() const {
    return total_idle_time;
}

int Teller::get_num_customers_served() const {
    return num_customers_served;
}

void Teller::start_service(int time, Customer *currentCustomer) {
    total_idle_time += time - time_service_ended;
    free = false;
    this->currentCustomer = currentCustomer;
    time_next_free = this->currentCustomer->start_service(time);
    time_service_started = time;
}

void Teller::end_service(int time) {
    if (currentCustomer != NULL)  {
        free = true;
        time_service_ended = time;
        total_service_time += (time - time_service_started);
        delete currentCustomer; //get rid of customer no longer needed
        currentCustomer = NULL;
        num_customers_served++;
    }
}
