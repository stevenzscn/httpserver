aux_source_directory(. DIR_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/deps)

add_executable(httpserver ${DIR_SRCS})
target_link_libraries(httpserver -lboost_system -lpthread)

install(TARGETS httpserver DESTINATION ${PROJECT_SOURCE_DIR}/bin)
