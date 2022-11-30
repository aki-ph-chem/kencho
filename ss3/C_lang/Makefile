CXX = gcc

f = 3
n = 1
fl = ${f}_${n}

run : ${fl}.out
	./${fl}.out

${fl}.out : ${fl}.c
	${CXX} -o $@ $<

clean:
	rm *.out

.PHONY : run clean
