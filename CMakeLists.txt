cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(proj2 main.cpp Proj2/Server.h Proj2/ClientHendlers/ClientHendler.h
        Proj2/Servers/MySerialServer.h
        Proj2/Stream/InputStream.h Proj2/Stream/OutputStream.h Proj2/CacheManager/CacheManager.h
        Proj2/Solver/Searchable.h Proj2/Solver/StringReverserSearchable.h Proj2/Solver/Searcher.h
        Proj2/Solver/StringReverserSearcher.h Proj2/Solver/State.h Proj2/CacheManager/FileCacheManager.h
        Proj2/Utils/FileTextHendler.h Proj2/Solver/Solution.h
        Proj2/Solver/StringReverserSolution.h Proj2/Solver/BFS.h Proj2/Utils/Comperators.h
        Proj2/Utils/Utils.h Proj2/Solver/MatrixSearchable.h Proj2/Utils/Point.h
        Proj2/Factory/SearchableFactory.h
        Proj2/Factory/StringSearchableFactory.h Proj2/Factory/MatrixSearchableFactory.h
        Proj2/Factory/SolutionFactory.h Proj2/Factory/StringSolutionFactory.h
        Proj2/Solver/MatrixSolution.h Tests/FileCacheManagerTests.h Proj2/ClientHendlers/MyClientHendler.h
        Proj2/Factory/MatrixSolutionFactory.h Proj2/Solver/AStar.h Proj2/Solver/DFS.h
        Proj2/Utils/AStarUtils.h Proj2/Solver/BreadthFirst.h Tests/MatrixCreator.h
        Proj2/Solver/Solver.h Proj2/Servers/MyParallelServer.h StringReverserMain.h Proj2/ClientHendlers/MyTestClientHendler.h)