CXX = g++
CXXFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
TARGET = Solver.exe
SourceFolder = Source
Source = main.cpp Computational.cpp FlagsManager.cpp InputOutput.cpp Logger.cpp math_utilits.cpp Test.cpp MainMode.cpp
Headers = Computational.h config.h FlagsManager.h InputOutput.h Logger.h MainMode.h math_utilits.h StructAndEnums.h Test.h
objects = $(Source:.cpp=.o)

ggg = $(addprefix $(SourceFolder)\, $(Source))
hhh = $(addprefix $(SourceFolder)\, $(Headers))

.PHONY : all clean 

all : $(TARGET)

$(TARGET) : $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o $(TARGET)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Computational.o : Computational.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

FlagsManager.o : FlagsManager.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

InputOutput.o : InputOutput.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

MainMode.o : MainMode.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

math_utilits.o : math_utilits.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Test.o : Test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

rec : $(ggg)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

rec_t : $(ggg)
	$(CXX) $(CXXFLAGS) -DRUN_TEST $^ -o $(TARGET)

rec_t_l : $(ggg)
	$(CXX) $(CXXFLAGS) -DRUN_TEST -D_SHOW_LOGG_MESSAGE $^ -o $(TARGET)

rec_l : $(ggg)
	$(CXX) $(CXXFLAGS) -D_SHOW_LOGG_MESSAGE $^ -o $(TARGET)

clean :
	rm $(TARGET) *.o