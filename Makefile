CXX=g++
GTEST_DIR=gtest
G_INCLUDE=${GTEST_DIR}/include
CXXFLAGS=-I include -I ${G_INCLUDE} -g -Wall -Wextra -pthread


all: unittest_triangle unittest_nextdate

unittest_triangle: unittest_triangle.o triangle.o
	$(CXX) $(CXXFLAGS) $^ -l$(GTEST_DIR) -o $@
unittest_nextdate: unittest_nextdate.o nextdate.o
	$(CXX) $(CXXFLAGS) $^ -l$(GTEST_DIR) -o $@

unittest_triangle.o: test/unittest_triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<
unittest_nextdate.o: test/unittest_nextdate.cpp include/nextdate.h
	$(CXX) $(CXXFLAGS) -c $<

triangle.o: src/triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<
nextdate.o: src/nextdate.cpp include/nextdate.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o
	rm -f unittest_triangle unittest_nextdate
