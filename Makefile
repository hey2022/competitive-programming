CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -Winvalid-pch -DLOCAL -Idbg-macro -fsanitize=undefined -fsanitize=address -D_GLIBCXX_DEBUG -std=c++17

%: %.cpp
	$(CXX) $(CXXFLAGS) $<
