cmake_minimum_required(VERSION 4.0)
project(Proyecto_1_Progra1_2025)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project2)

add_executable(Proyecto_1_Progra1_2025
        Project2/Clase.cpp
        Project2/Clase.h
        Project2/Cliente.cpp
        Project2/Cliente.h
        Project2/Controller.cpp
        Project2/Controller.h
        Project2/Ejercicio.cpp
        Project2/Ejercicio.h
        Project2/GymsPowerLab.cpp
        Project2/GymsPowerLab.h
        Project2/Instructor.cpp
        Project2/Instructor.h
        Project2/main.cpp
        Project2/ReporteMedicion.cpp
        Project2/ReporteMedicion.h
        Project2/Sucursal.cpp
        Project2/Sucursal.h
        Project2/UI.cpp
        Project2/UI.h
        Project2/VectorClases.cpp
        Project2/VectorClases.h
        Project2/VectorClientes.cpp
        Project2/VectorClientes.h
        Project2/VectorEjercicio.cpp
        Project2/VectorEjercicio.h
        Project2/VectorInstructores.cpp
        Project2/VectorInstructores.h
        Project2/VectorMedicion.cpp
        Project2/VectorMedicion.h
        Project2/VectorSucursales.cpp
        Project2/VectorSucursales.h
        Project2/Fecha.cpp
        Project2/Fecha.h)
