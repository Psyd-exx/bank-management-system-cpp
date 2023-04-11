cmake_minimum_required(VERSION 3.9)

project(
  bank-management-system-cpp
  VERSION 1.0
  LANGUAGES CXX)

set(SRC ./BankAccount.h ./BankAccount.cpp ./main.cpp)

add_executable(bsms ${SRC})
