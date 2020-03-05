add_library(DMData
    Dataset.cpp
)

install(TARGETS DMData DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
