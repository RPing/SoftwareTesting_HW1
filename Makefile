CXX=g++
GTEST_DIR=gtest
G_INCLUDE=${GTEST_DIR}/include
CXXFLAGS=-std=c++11 -I include -I ${G_INCLUDE} -g -Wall -Wextra -pthread


all: unittest_triangle unittest_nextdate unittest_commission

unittest_triangle: unittest_triangle.o triangle.o
	$(CXX) $(CXXFLAGS) $^ -l$(GTEST_DIR) -o $@
unittest_nextdate: unittest_nextdate.o nextdate.o
	$(CXX) $(CXXFLAGS) $^ -l$(GTEST_DIR) -o $@
unittest_commission: unittest_commission.o commission.o
	$(CXX) $(CXXFLAGS) $^ -l$(GTEST_DIR) -o $@

unittest_triangle.o: test/unittest_triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<
unittest_nextdate.o: test/unittest_nextdate.cpp include/nextdate.h
	$(CXX) $(CXXFLAGS) -c $<
unittest_commission.o: test/unittest_commission.cpp include/commission.h

triangle.o: src/triangle.cpp include/triangle.h
	$(CXX) $(CXXFLAGS) -c $<
nextdate.o: src/nextdate.cpp include/nextdate.h
	$(CXX) $(CXXFLAGS) -c $<
commission.o: src/commission.cpp include/commission.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o
	rm -f unittest_triangle unittest_nextdate unittest_commission
