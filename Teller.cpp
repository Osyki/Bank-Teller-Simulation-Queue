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
