set(CLIENT_SOURCES src) # add source files here

include_directories(inc)

#add_executable(${CMAKE_PROJECT_NAME} client.cpp ${CLIENT_SOURCES})

add_executable(${CMAKE_PROJECT_NAME} client.cpp)

#if(MINGW)
#    target_link_libraries(${CLIENT_PROJECT} ws2_32)
#endif()

#find_package(Boost 1.75.0 COMPONENTS program_options system filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#target_link_libraries(${CMAKE_PROJECT_NAME} Boost::program_options Boost::system Boost::filesystem)
