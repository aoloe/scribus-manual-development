# Adding a library

A library is a directory containing code that belong together.


## Creating the directory

```cmake
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/scribus
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_FPIC}")

set(SCRIBUS_NEWDIRECTORY_LIB_MOC_CLASSES
    # xxx.h
)

set(SCRIBUS_NEWDIRECTORY_LIB_SOURCES
    # xxx.cpp
)

QT5_WRAP_CPP(SCRIBUS_NEWDIRECTORY_LIB_MOC_SOURCES ${SCRIBUS_NEWDIRECTORY_LIB_MOC_CLASSES})

set(SCRIBUS_NEWDIRECTORY_LIB "scribus_newdirectory_lib")
add_library(${SCRIBUS_NEWDIRECTORY_LIB} STATIC ${SCRIBUS_NEWDIRECTORY_LIB_SOURCES} ${SCRIBUS_NEWDIRECTORY_LIB_MOC_SOURCES})

set_target_properties(${SCRIBUS_NEWDIRECTORY_LIB}
	PROPERTIES
	COMPILE_FLAGS -DCOMPILE_SCRIBUS_MAIN_APP
)
```


## Adding the library to the Scribus `CMakeLists.txt`


in `scribus/CMakeLists.txt` one needs to add:

- the directory with `add_subdirectory(newdirectory)`
- the directory to `link_directories()` as `${CMAKE_CURRENT_BINARY_DIR}/newdirectory`
- the string of the "library" as defined in the library's CMakeLists.txt: `set(SCRIBUS_NEWDIRECTORY_LIB "scribus_newdirectory_lib")`
- link the `${SCRIBUS_NEWDIRECOTRY_LIB}` library code in `target_link_libraries(${EXE_NAME} (...)`


a good example is how the zip library gets added.
