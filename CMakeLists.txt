cmake_minimum_required(VERSION 3.15)
project(AEDA_UghEats)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDA_UghEats main.cpp utils.cpp Classes/Address.cpp Classes/Location.cpp Classes/Date.cpp
        Classes/Vehicle.cpp Classes/Product.cpp Classes/Client.cpp Classes/Worker.cpp Classes/Order.cpp Classes/Restaurant.cpp Classes/Company.cpp
        Classes/Base.cpp)