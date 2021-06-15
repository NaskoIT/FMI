cmake_minimum_required(VERSION 3.17)
project(03_Homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(03_Homework main.cpp 1/Counter.hpp 1/Counter.cpp 1/TwowayCounter.hpp 1/TwowayCounter.cpp 1/LimitedCounter.hpp 1/LimitedCounter.cpp 1/LimitedTwowayCounter.hpp 1/LimitedTwowayCounter.cpp "1/Semaphore.hpp" "1/Semaphore.cpp" 2/Developer.hpp 2/TeamLead.hpp 2/Developer.cpp 2/TeamLead.cpp 2/LeavingRequest.hpp 2/PromotionRequest.hpp 2/Request.hpp 2/Request.cpp 2/LeavingRequest.cpp 2/PromotionRequest.cpp)