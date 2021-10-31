//
// Created by Jonathan Rubio on 10/28/21.
//

#ifndef HW4_BANK_TELLER_QUEUE_CUSTOMER_H
#define HW4_BANK_TELLER_QUEUE_CUSTOMER_H

// create a ramdom variable in .cpp
#include "Random.h"

class Customer {
public:
    /**
     * Constructor for customer, setting the time that the customer arrived at the bank.
     * @param the_arrival_time The time the customer arrived at the bank.
     */
    explicit Customer(int the_arrival_time);

    /**
     * The customer has been assigned to a teller, and service has begun.
     * also calculate the total delay time of a customer
     * @param time The time service will begin.
     * @return The time service will complete.
     */
    int start_service(int time);

    /**
     * Get the delay time a customer waited to be serviced
     * @return The delay time a customer had to wait in minutes.
     */
    int get_delay_time() const;

    /**
     * Get the arrival time for the given customer.
     * @return The arrival time of the customer in minutes after simulation start.
     */
    int get_arrival_time() const;

    /**
     * Gets the time a customer was serviced.
     * @return The time a customer was serviced in minutes after simulation start.
     */
    int get_service_time() const;

    /**
     * Sets the maximum service time for any possible customer.
     * @param the_max_service_time The maximum amount of time
     * it takes to serve any given customer in minutes.
     */
    static void set_max_service_time(int the_max_service_time);

    /**
     * The total delay time that all customers have faced.
     * @return
     */
    static int get_total_delay_time();

    /**
     * The total number of customers served.
     * @return
     */
    static int get_total_customers_served();


private:

    //  Initialize the static variables in .cpp file.
    static int total_delay_time; // total delay time
    static int max_service_time; // max service time for each customer.
    static int total_customers_served; // total number of customer serve **
    int arrival_time; // customer arrival time **
    int service_time; // customer service time **
    int delay_time{}; // customer waited in line

};


#endif //HW4_BANK_TELLER_QUEUE_CUSTOMER_H
