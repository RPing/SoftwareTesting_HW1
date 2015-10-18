CXX=g++
GTEST_DIR=gtest
CXXFLAGS=-I include -I gtest/include -g -Wall -Wextra -pthread
G_INCLUDE=${GTEST_DIR}/include/*
G_LIB=${GTEST_DIR}/lib/lib*.a

all: unittest_triangle

unittest_triangle: unittest_triangle.o triangle.o
	$(CXX) $(CXXFLAGS) $^ -L. -lgtest

unittest_triangle.o: test/unittest_triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<

triangle.o: src/triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<
