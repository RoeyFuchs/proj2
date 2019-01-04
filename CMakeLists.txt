cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(proj2 main.cpp ServerNameSpace/Server.h ServerNameSpace/ClientHendler.h
        ServerNameSpace/ClientHendlers/ClientHendler.cpp ServerNameSpace/Servers/MySerialServer.h
        ServerNameSpace/Stream/InputStream.h ServerNameSpace/Stream/OutputStream.h)