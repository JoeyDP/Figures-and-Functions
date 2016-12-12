SET(TESTSRC
	${TESTSRC}
	test1.cpp
)

ADD_SUBDIRECTORY (gtest)

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

# Add test cpp file
ADD_EXECUTABLE(Test ${TESTSRC} ${SRC})

# Link test executable against gtest & gtest_main
target_link_libraries(Test gtest gtest_main)
target_link_libraries(Test FigFunc gsl gslcblas)
