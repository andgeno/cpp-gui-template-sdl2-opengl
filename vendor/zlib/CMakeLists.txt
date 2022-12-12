message(STATUS "Fetching zlib ...")

## TODO: Fehlermeldung -> Compatibility with CMake < 2.8.12 will be removed from a future version of CMake.

## TODO: Windows kennt kein unistd.h -> Wie entfernen?
#remove_definitions(-DHAVE_UNISTD_H)

FetchContent_MakeAvailable(zlib)
