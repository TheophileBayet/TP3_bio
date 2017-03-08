
cmake_minimum_required (VERSION 2.8.11)

#Déclaration du projet

project(tp3_bio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

#Génération de la liste des fichiers sources

file(GLOB_RECURSE
        source_files
        ../src/*
)

add_executable(exe ${source_files})
