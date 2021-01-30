set(SERVER_SOURCES src) # add source files here

include_directories(inc)

add_executable(${CMAKE_PROJECT_NAME}_server server.cpp ${SERVER_SOURCES})

#if(MINGW)
#    target_link_libraries(${CLIENT_PROJECT} ws2_32)
#endif()
