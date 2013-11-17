#find_path(get_hello_INCLUDE_DIRS world.h /usr/include "$ENV{NAMER_ROOT}")

#find_library(get_hello_LIBRARIES namer /usr/lib "$ENV{NAMER_ROOT}")

find_path(get_hello_INCLUDE_DIRS get_hello.h /home/oscar/Documents/c++/03_building_a_library/include/)

find_library(get_hello_LIBRARIES get_hello /home/oscar/Documents/c++/03_building_a_library/build/)

set(get_hello_FOUND TRUE)
 
if (NOT get_hello_INCLUDE_DIRS)
	set(get_hello_FOUND FALSE)
endif (NOT get_hello_INCLUDE_DIRS)

if (NOT get_hello_LIBRARIES)
	set(get_hello_FOUND FALSE)
endif (NOT get_hello_LIBRARIES)