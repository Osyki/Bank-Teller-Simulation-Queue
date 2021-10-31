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
    free = false; //teller no longer free
    total_idle_time += time - time_service_ended; //calculate idle time without customer
    time_service_started = time; //time started with customer
    this->currentCustomer = currentCustomer; //set current customer
    time_next_free = this->currentCustomer->start_service(time); //returns next time free
    num_customers_served++; //increment customers served by teller
}

void Teller::end_service(int time) {
    if (currentCustomer != NULL) { //check if its not NULL first
        time_service_ended = time; //save time finished with customer
        total_service_time += time_service_ended - time_service_started; //calculate total service time
        delete currentCustomer; //get rid of customer no longer needed
        currentCustomer = NULL; //set current customer back to NULL
        free = true; //teller is free again
    }

}
