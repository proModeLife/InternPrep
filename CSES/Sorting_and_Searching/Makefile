CPPFLAGS = -std=c++11
INPUT_FILE = input.txt
FILENAME = $(firstword $(MAKECMDGOALS))

create:
	@if [ -f $(FILENAME).cpp ]; then \
		echo "File $(FILENAME).cpp already exists."; \
	else \
		echo "Creating file: $(FILENAME)"; \
		printf "#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <cmath>\n#include <string>\n#include <cstring>\n#include <queue>\n#include <stack>\n#include <map>\n#include <set>\n#include <bitset>\n#include <iomanip>\n\nusing namespace std;\n\nint main() {\n\tios_base::sync_with_stdio(false);\n\tcin.tie(NULL);\n\n\t// Your code here\n\n\treturn 0;\n}" > $(FILENAME).cpp; \
		echo "Created file: $(FILENAME)"; \
		nvim $(FILENAME).cpp; \
	fi

compile: $(FILENAME).cpp
	@g++ $(CPPFLAGS) $< -o $(FILENAME).out

run: $(FILENAME).out
	@./$< < $(INPUT_FILE)

clean:
	@rm -f *.out

%:
	@:
