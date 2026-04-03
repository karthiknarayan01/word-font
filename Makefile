CXX      = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
TARGET   = word_font
SRCS     = main.cpp word_font.cpp
OBJS     = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp word_font.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
