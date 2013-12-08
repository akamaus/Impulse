#include_directories(${Impulse_SOURCE_DIR}/Engine)
#link_directories(${Impulse_BINARY_DIR}/Engine)

#the one C file
add_executable(Impulse main.cpp Synapse.cpp)
