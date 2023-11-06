# Aahanaa (Atibrewa)

CC=gcc -std=c99

fp_relational_ops: test.c floatParts.c
	${CC} -o fp_relational_ops test.c floatParts.c

clean:
	rm -f fp_relational_ops