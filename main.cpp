//
// Created by Jonathan Rubio on 10/28/21.
//

#include <cstdlib>
#include "Bank_Simulator.h"
#include "Teller.h"

using namespace std;


int main()
{
    Simulator simulator;
    int num_tellers = 3;
    double arrival_rate = 30;
    int max_time = 200;
    int max_service_time = 3;
//  cout << "Enter the number of tellers: ";
//  cin >> num_tellers;
//  tellers.resize(num_tellers);
    simulator.setTellers(num_tellers);
//  cout << "Enter the arrival rate (per hour): ";
//  cin >> arrival_rate;
//  cout << "Enter the maximum service time (minutes): ";
//  cin >> max_service_time;
    Customer::set_max_service_time(max_service_time);
//  cout << "Enter the max simulation time (minutes): ";
//  cin >> max_time;
    simulator.run_simulation(max_time, arrival_rate/60.0);
    simulator.output_statistics();
}