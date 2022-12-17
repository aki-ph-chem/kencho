CXX = gcc

f = list
n = 0

fl = ${f}_${n}

run: ${fl}.out
	./${fl}.out

${fl}.out : ${fl}.c
	${CXX} $< -o $@

clean:
	rm *.out

.PHONY: run clean
