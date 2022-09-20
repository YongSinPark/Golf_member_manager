cmake_minimum_required(VERSION 3.0.0)

project(Golf_member_manager)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/Golf_membership_manager.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/hw/rfid/mfrc522.cpp
    ./src/hw/rfid/Card_reader.cpp
    ./src/hw/spi/SPI.cpp
    ./src/hw/Monitor/Monitor.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./src
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/Model
    ./src/hw/rfid
    ./src/hw/spi
    ./src/hw/Monitor
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)