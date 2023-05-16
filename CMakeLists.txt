cmake_minimum_required(VERSION 3.23)
project(2_Parser_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2_Parser_ main.cpp Directory.h DataParser.cpp DataParser.h Students.h Counter.cpp Counter.h Printer.h EmptyFileexept.h CSVexcept.h)
