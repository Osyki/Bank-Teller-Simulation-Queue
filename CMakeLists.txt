cmake_minimum_required(VERSION 3.20)
project(HW4_Bank_Teller_Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW4_Bank_Teller_Queue main.cpp Bank_Simulator.cpp Bank_Simulator.h Customer.cpp Customer.h Teller.cpp Teller.h Random.cpp Random.h)
