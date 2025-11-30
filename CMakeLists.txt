cmake_minimum_required(VERSION 3.31)
project(NetoINI)

set(CMAKE_CXX_STANDARD 23)

add_executable(NetoINI
        main.cpp

        core/data/Constants.hpp

        core/entities/Parser.hpp
        core/entities/Parser.cpp

        core/exceptions/ParserException.cpp
        core/exceptions/ParserException.hpp

        libio.cppm
)

target_sources(NetoINI
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        libio.cppm
)