cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(proj2 main.cpp ServerNameSpace/Server.h ServerNameSpace/ClientHendlers/ClientHendler.h
        ServerNameSpace/ClientHendlers/ClientHendler.cpp ServerNameSpace/Servers/MySerialServer.h
        ServerNameSpace/Stream/InputStream.h ServerNameSpace/Stream/OutputStream.h ServerNameSpace/CacheManager/CacheManager.h
        ServerNameSpace/Solver/Searchable.h ServerNameSpace/Solver/StringReverserSearchable.h ServerNameSpace/Solver/Searcher.h
        ServerNameSpace/Solver/StringReverserSearcher.h ServerNameSpace/Solver/State.h ServerNameSpace/CacheManager/FileCacheManager.h
        ServerNameSpace/Utils/FileTextHendler.cpp ServerNameSpace/Utils/FileTextHendler.h ServerNameSpace/Solver/Solution.h
        ServerNameSpace/Solver/StringReverserSolution.h ServerNameSpace/Solver/BFS.h ServerNameSpace/Utils/Comperators.h
        ServerNameSpace/Utils/Utils.h)