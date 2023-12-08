cmake_minimum_required(VERSION 3.27)

project(ep-poo LANGUAGES CXX VERSION 1.0.0)

set(SOURCE_DIR src)
set(HEADER_DIR 
	${SOURCE_DIR}/Amplificador.h 
	${SOURCE_DIR}/Somador.h 
	${SOURCE_DIR}/Sinal.h 
	${SOURCE_DIR}/Derivador.h 
	${SOURCE_DIR}/Integrador.h 
	${SOURCE_DIR}/ModuloRealimentado.h 
	${SOURCE_DIR}/Piloto.h 
	${SOURCE_DIR}/Grafico.h
	${SOURCE_DIR}/Circuito.h
	${SOURCE_DIR}/CircuitoSISO.h
	${SOURCE_DIR}/CircuitoMISO.h
	${SOURCE_DIR}/Modulo.h
	${SOURCE_DIR}/ModuloEmSerie.h
	${SOURCE_DIR}/ModuloEmParalelo.h
	${SOURCE_DIR}/PersistenciaDeModulo.h
)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(amplificador 
	${SOURCE_DIR}/Amplificador.cpp
	${SOURCE_DIR}/Amplificador.h
)
target_link_libraries(amplificador INTERFACE circuitosiso sinal)

add_library(somador 
	${SOURCE_DIR}/Somador.cpp 
	${SOURCE_DIR}/Somador.h
)
target_link_libraries(somador INTERFACE circuitomiso sinal)

add_library(grafico 
	${SOURCE_DIR}/Grafico.cpp 
	${SOURCE_DIR}/Grafico.h
)

add_library(sinal 
	${SOURCE_DIR}/Sinal.cpp 
	${SOURCE_DIR}/Sinal.h
)
target_link_libraries(sinal INTERFACE grafico)

add_library(derivador
	${SOURCE_DIR}/Derivador.cpp
	${SOURCE_DIR}/Derivador.h
)
target_link_libraries(derivador INTERFACE circuitosiso sinal)

add_library(integrador
	${SOURCE_DIR}/Integrador.cpp
	${SOURCE_DIR}/Integrador.h
)
target_link_libraries(integrador INTERFACE circuitosiso sinal)

add_library(modulorealimentado
	${SOURCE_DIR}/ModuloRealimentado.cpp
	${SOURCE_DIR}/ModuloRealimentado.h
)
target_link_libraries(modulorealimentado INTERFACE sinal modulo moduloemserie somador amplificador integrador)

add_library(piloto
	${SOURCE_DIR}/Piloto.cpp
	${SOURCE_DIR}/Piloto.h
)
target_link_libraries(piloto INTERFACE sinal)

add_library(circuito
	${SOURCE_DIR}/Circuito.cpp
	${SOURCE_DIR}/Circuito.h
)

add_library(circuitosiso
	${SOURCE_DIR}/CircuitoSISO.cpp
	${SOURCE_DIR}/CircuitoSISO.h
)
target_link_libraries(circuitosiso INTERFACE circuito sinal)

add_library(circuitomiso
	${SOURCE_DIR}/CircuitoMISO.cpp
	${SOURCE_DIR}/CircuitoMISO.h
)
target_link_libraries(circuitomiso INTERFACE circuito sinal)

add_library(modulo
	${SOURCE_DIR}/Modulo.cpp
	${SOURCE_DIR}/Modulo.h
)
target_link_libraries(modulo INTERFACE circuitosiso)

add_library(moduloemserie
	${SOURCE_DIR}/ModuloEmSerie.cpp
	${SOURCE_DIR}/ModuloEmSerie.h
)
target_link_libraries(moduloemserie INTERFACE sinal circuitosiso)

add_library(moduloemparalelo
	${SOURCE_DIR}/ModuloEmParalelo.cpp
	${SOURCE_DIR}/ModuloEmParalelo.h
)
target_link_libraries(moduloemparalelo INTERFACE sinal circuitosiso somador)

add_library(persistenciademodulo
	${SOURCE_DIR}/PersistenciaDeModulo.cpp
	${SOURCE_DIR}/PersistenciaDeModulo.h
)
target_link_libraries(persistenciademodulo INTERFACE modulo moduloemserie moduloemparalelo modulorealimentado circuitosiso amplificador derivador integrador)

add_executable(ep-poo
	${SOURCE_DIR}/main.cpp
	${SOURCE_DIR}/menu.cpp
	${HEADER_DIR}
)
target_link_libraries(ep-poo amplificador somador sinal derivador integrador modulorealimentado piloto moduloemserie moduloemparalelo persistenciademodulo)

#add_subdirectory(tests)
