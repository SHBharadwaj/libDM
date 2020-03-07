add_executable(dm DM.cpp)

target_link_libraries(dm
	DMData
	DMPreprocess
)

install(TARGETS dm DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
