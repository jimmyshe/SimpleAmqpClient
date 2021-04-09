cmake_minimum_required(VERSION 3.11)
project(SimpleAmqpClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(rabbitmq-c CONFIG REQUIRED)
message(STATUS "using rabbitmq-c " ${rabbitmq-c_VERSION})

find_package(Boost REQUIRED COMPONENTS)
message(STATUS "using boost " ${Boost_VERSION})

add_library(SimpleAmqpClient
        #SHARED
        src/AmqpException.cpp
        src/Channel.cpp
        src/ChannelImpl.cpp
        src/BasicMessage.cpp
        src/AmqpLibraryException.cpp
        src/AmqpResponseLibraryException.cpp
        src/Envelope.cpp
        src/MessageReturnedException.cpp
        src/Table.cpp
        src/TableImpl.cpp)

target_link_libraries(SimpleAmqpClient
        PUBLIC
        Boost::headers
        rabbitmq::rabbitmq
        )

if (WIN32)
    target_link_libraries(SimpleAmqpClient PUBLIC ws2_32)
endif ()

target_include_directories(SimpleAmqpClient
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        )
target_compile_definitions(SimpleAmqpClient PUBLIC SAC_SSL_SUPPORT_ENABLED)

add_subdirectory(testing)

