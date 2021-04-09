find_package(GTest CONFIG REQUIRED)
#target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_executable(test_api
    connected_test.h
    test_connect.cpp
    test_channels.cpp
    test_exchange.cpp
    test_queue.cpp
    test_publish.cpp
    test_get.cpp
    test_consume.cpp
    test_message.cpp
    test_table.cpp
    test_ack.cpp
    test_nack.cpp
    )
target_link_libraries(test_api
        PUBLIC
        SimpleAmqpClient
        GTest::gtest
        GTest::gtest_main
        )
