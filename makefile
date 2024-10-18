# List of files to compile
FILES_cpp23 := print expected unique_ptr strategy command observer type_erasure string_view reimpl_strategy derived span

ALL_FILES := $(FILES_cpp23)

# Compilation flags
LIBCPP23 := -stdlib=libc++ -std=c++23

DEBUG := -g -O0

# Rule to compile every file
all: $(ALL_FILES)

# from chat gpt
# The rule for compiling each file individually now includes a dependency on the corresponding .cpp file using a pattern rule.
# $(FILES): %: %.cpp: This pattern rule states that for each file in $(FILES), the target depends on a corresponding .cpp file. The % symbol matches the stem of the target and prerequisite, allowing for the dependency relationship.
# $< is a special automatic variable in Makefiles that represents the first prerequisite (in this case, the .cpp file).

# Rule to compile each file individually
# $(FILES_cpp23): %: %.cpp
# 	clang++ $(LIBCPP23) -o $@ $<

# let's try if always executign it is fine here
$(FILES_cpp23) run: %: %.cpp
	clang++ $(LIBCPP23) $(DEBUG) -o $@ $< && ./$@

# Clean rule, sicne execs are named like sources are
clean:
	$(RM) $(ALL_FILES)
