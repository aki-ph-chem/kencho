CXX = g++
f = 2
n = 4

fl = ${f}_${n}

run: ${fl}.out
	./${fl}.out

${fl}.out: ${fl}.cpp
	${CXX} $< -o $@
clean:
	rm *.out

.PHONY: run clean
