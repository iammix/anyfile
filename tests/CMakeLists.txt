# Add test executable for CsvHandler
include_directories(${PROJECT_SOURCE_DIR}/external/json)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test_csvhandler test_csvhandler.cpp
        ../src/CsvHandler.cpp
        ../src/JsonHandler.cpp
        ../src/FileDump.cpp)

add_executable(test_jsonhandler test_jsonhandler.cpp
        ../src/JsonHandler.cpp
        ../src/FileDump.cpp
        ../src/CsvHandler.cpp
)


# Add tests to CTest
add_test(NAME TestCsvHandler COMMAND test_csvhandler)
add_test(NAME TestJsonHandler COMMAND test_jsonhandler)

# Copy test data to the build directory
add_custom_command(
        TARGET test_csvhandler POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/test_data/test_data.csv
        $<TARGET_FILE_DIR:test_csvhandler>
)

add_custom_command(
        TARGET test_jsonhandler POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/test_data/test_data.json
        $<TARGET_FILE_DIR:test_jsonhandler>
)
