TARGETS=threadTest
all: $(TARGETS)
STDS=-std=c++11
LIBS=-pthread

threadTest:threadTest.cpp
	g++ $^ -o $@ $(STDs) $(LIBS)

clean:
	rm -rf $(TARGETS)
