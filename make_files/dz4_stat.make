all: dz4

dz4: main.o liblist.a
	g++ main.o -L. -llist_tf -o dz4.out
	rm -f *.o
	cp ./list_src/list_tf.h ./lib_list_stat/list_tf.h
	mv ./liblist_tf.a ./lib_list_stat/

liblist.a: ./list_src/list_tf.cpp
	g++ -c ./list_src/list_tf.cpp
	ar rc liblist_tf.a  list_tf.o
	ranlib liblist_tf.a

main.o: main.cpp
	g++ -c main.cpp
	
