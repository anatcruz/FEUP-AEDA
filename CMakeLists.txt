cmake_minimum_required(VERSION 3.15)
project(AEDA_UghEats)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDA_UghEats main.cpp Restaurant.h Restaurant.cpp Address.cpp Address.h Location.cpp Location.h Date.cpp Date.h Product.cpp Product.h Order.cpp Order.h Delivery.cpp Delivery.h
        Company.h Worker.cpp Worker.h Vehicle.cpp Vehicle.h Base.cpp Base.h Client.cpp Client.h Company.cpp)