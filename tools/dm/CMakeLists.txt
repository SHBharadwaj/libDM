add_executable(dm DM.cpp)

target_link_libraries(dm
	DMData
)

install(TARGETS dm DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
