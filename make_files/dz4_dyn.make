all: dz4

dz4: main.o liblist.so
	g++ main.o -L./lib_list_dyn -llist_tf -Wl,-rpath,./lib_list_dyn -o dz4.out
	rm -f *.o
	cp ./list_src/list_tf.h ./lib_list_dyn/list_tf.h

liblist.so: ./list_src/list_tf.cpp
	g++ -c -fPIC ./list_src/list_tf.cpp
	g++ -shared -o ./lib_list_dyn/liblist_tf.so  ./list_tf.o 

main.o: main.cpp
	g++ -c main.cpp
	
