set(SOURCES main.cpp engine.cpp wrapper.cpp)

set(HEADERS main.cpp engine.hpp wrapper.hpp subjects.hpp)

add_executable(cpp_wrapper ${SOURCES} ${HEADERS})
