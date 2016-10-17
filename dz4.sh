#!/bin/bash
echo ""
echo ===GENERATE INPUT FILES===

python3 ./gen_inp_file.py

touch ./output.txt

echo ""
echo ===WITH STATIC LIBRARY====
echo ""
echo ===========MAKE===========
make -f ./make_files/dz4_stat.make

echo ""
echo ===========RUN============
./dz4.out input.txt output.txt

echo ПРОСМОТР РЕЗУЛЬТАТА В ВЫХОДНОМ ФАЙЛЕ

cat ./output.txt

echo "########################"
echo "########################"
echo "########################"

echo ""
echo ===WITH DYNAMIC LIBRARY===

echo ""
echo ===========MAKE===========
make -f ./make_files/dz4_dyn.make

echo ""
echo ===========RUN============
./dz4.out input.txt output.txt

echo ПРОСМОТР РЕЗУЛЬТАТА В ВЫХОДНОМ ФАЙЛЕ 

cat ./output.txt 
