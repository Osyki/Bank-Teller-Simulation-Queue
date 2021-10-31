//
// Created by Jonathan Rubio on 10/28/21.
// Copyright [2021]

#ifndef HW4_BANK_TELLER_QUEUE_TELLER_H
#define HW4_BANK_TELLER_QUEUE_TELLER_H
#include "Customer.h"
/** Class to model a teller */

class Teller
{
public:
    Teller();
    bool is_free() const;  // true if teller is free
    int get_time_next_free() const;  // return the next free time
    int get_total_service_time() const;  // return total service time
    int get_total_idle_time() const;   // return total idle time
    int get_num_customers_served() const;  // return total customers served

    /**
    * Start servicing a customer at the given time.
    * calculate the total idle time of a teller
    * calculate number of customer served
    * and next available free time
    * @param time The time servicing began.
    * @param A pointer to the customer to be serviced.
    */
    void start_service(int time, Customer* currentCustomer);

    /**
    *  end the teller service time
    *  calculate the total service time
    *  set teller free
    *  @param time The time service end
    */
    void end_service(int time);

private:
    bool free;                 // teller is free
    int time_next_free;        // next available free time
    int num_customers_served;  // keep track of how many customer served
    int time_service_started;  // the time service start
    int time_service_ended;    // the time service end
    int total_service_time;    // total service time
    int total_idle_time;       // total idle time
    Customer* currentCustomer; // current customer being served

};

#endif //HW4_BANK_TELLER_QUEUE_TELLER_H
