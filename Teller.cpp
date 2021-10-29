//
// Created by Jonathan Rubio on 10/28/21.
//

#include "Teller.h"

Teller::Teller() {
    free = true;
    time_next_free = 0;
    num_customers_served = 0;
    time_service_started = 0;
    time_service_ended = 0;
    total_idle_time = 0;
    currentCustomer = nullptr;
}

bool Teller::is_free() const {
    return free;
}

int Teller::get_time_next_free() const {
    return time_next_free;
}

int Teller::get_total_service_time() const {
    return time_service_ended-time_service_started;
}

int Teller::get_total_idle_time() const {
    return total_idle_time;
}

int Teller::get_num_customers_served() const {
    return num_customers_served;
}

void Teller::start_service(int time, Customer *currentCustomer) {
    if (currentCustomer == nullptr) {

    } else {

    }

}

void Teller::end_service(int time) {

}
