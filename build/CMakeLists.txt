
cmake_minimum_required (VERSION 2.8.11)

#Déclaration du projet

project(tp3_bio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -I /../../armadillo-7.200.3/include -DARMA_DONT_USE_WRAPPER -lblas -llapack")

#Génération de la liste des fichiers sources

file(GLOB_RECURSE
        source_files
        ../src/*
)

add_executable(exe ${source_files})
