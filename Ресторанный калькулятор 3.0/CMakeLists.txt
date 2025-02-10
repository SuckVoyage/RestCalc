cmake_minimum_required (VERSION 3.10)

# имя решения
project(Settings)

# имя таргета
set(
ProjectName
RestCalc
)

set(
	SOURCES
	Calc.cpp
)

set(
	HEADERS

)

# таргет
add_executable(${ProjectName} ${SOURCES} ${HEADERS})


set_target_properties(
	${ProjectName} PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)


include("functions.cmake")
generate_packages(${ProjectName})
