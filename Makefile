TARGET		= noutore.out

CXX				= clang++
LD				= $(CXX)

CXXFILES	= $(wildcard *.cpp)
OFILES		= $(CXXFILES:.cpp=.o)

CXXFLAGS	= -O2 -std=gnu++20
LDFLAGS		= -Wl,--gc-sections

all: $(TARGET)

clean:
	@rm -rf $(TARGET)
	@rm -rf *.o

re: clean all

%.o: %.cpp $(wildcard *.h)
	@echo $<
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OFILES)
	@echo linking...
	@$(LD) $(LDFLAGS) -o $@ $^