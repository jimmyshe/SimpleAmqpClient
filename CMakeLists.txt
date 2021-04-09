cmake_minimum_required(VERSION 3.11)
project(SimpleAmqpClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(rabbitmq-c CONFIG REQUIRED)
message(STATUS "using rabbitmq-c " ${rabbitmq-c_VERSION})

find_package(Boost REQUIRED COMPONENTS)
message(STATUS "using boost " ${Boost_VERSION})

add_library(SimpleAmqpClient SHARED
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
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/SimpleAmqpClient
        )
target_compile_definitions(SimpleAmqpClient PUBLIC SAC_SSL_SUPPORT_ENABLED)

# Some smoke tests:


add_subdirectory(testing)



#include(GNUInstallDirs)
#
#install(TARGETS SimpleAmqpClient
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    )
#
#install(FILES
#    src/SimpleAmqpClient/AmqpException.h
#    src/SimpleAmqpClient/AmqpLibraryException.h
#    src/SimpleAmqpClient/AmqpResponseLibraryException.h
#    src/SimpleAmqpClient/BadUriException.h
#    src/SimpleAmqpClient/BasicMessage.h
#    src/SimpleAmqpClient/Channel.h
#    src/SimpleAmqpClient/ConnectionClosedException.h
#    src/SimpleAmqpClient/ConsumerCancelledException.h
#    src/SimpleAmqpClient/ConsumerTagNotFoundException.h
#    src/SimpleAmqpClient/Envelope.h
#    src/SimpleAmqpClient/MessageReturnedException.h
#    src/SimpleAmqpClient/MessageRejectedException.h
#    src/SimpleAmqpClient/SimpleAmqpClient.h
#    src/SimpleAmqpClient/Table.h
#    src/SimpleAmqpClient/Util.h
#    src/SimpleAmqpClient/Version.h
#    DESTINATION include/SimpleAmqpClient
#    )
#
#set(prefix ${CMAKE_INSTALL_PREFIX})
#set(exec_prefix "\${prefix}")
#set(libdir ${CMAKE_INSTALL_LIBDIR})
#set(includedir "\${prefix}/include")
#
#foreach(_lib ${Boost_LIBRARIES})
#    get_filename_component(_LIBPATH ${_lib} PATH)
#    if (NOT _LIBPATH STREQUAL _LASTLIBPATH)
#        set(libs_private "${libs_private} -L${_LIBPATH}")
#        set(_LASTLIBPATH ${_LIBPATH})
#    endif()
#
#    get_filename_component(_LIBNAME ${_lib} NAME_WE)
#    string(REGEX REPLACE "^lib" "" _LIBNAME ${_LIBNAME})
#    set(_LIBNAME "-l${_LIBNAME}")
#    set(libs_private "${libs_private} ${_LIBNAME}")
#endforeach()
#
#configure_file(libSimpleAmqpClient.pc.in ${CMAKE_CURRENT_BINARY_DIR}/libSimpleAmqpClient.pc @ONLY)
#
#install(FILES
#    ${CMAKE_CURRENT_BINARY_DIR}/libSimpleAmqpClient.pc
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
#    )
