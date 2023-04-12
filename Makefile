default : chute_fp chute_vf chute_vf.o vfix.o

chute_fp : chute_fp.c
	cc -o chute_fp chute_fp.c

chute_vf : chute_vf.c vfix.o vfix.h
	cc -o chute_vf chute_vf.c vfix.o vfix.h -lm

vfix.o : vfix.c vfix.h
	cc -c vfix.c


chute_vf.o : chute_vf.c
	cc -c chute_vf.c

clean :
	rm -f chute_fp chute_vf *.data *.o

