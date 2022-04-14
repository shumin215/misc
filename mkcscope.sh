#!/bin/sh
rm -rf cscope.files cscope.files
find . \( -name '*.cu' -o -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' -o -name '*.s' -o -name '*.S' -o -name '*.hh' -o -name '*.py' -o -name '*.pyh' -o -name '*.sv' -o -name '*.v' -o -name '*.vh' \) -print > cscope.files

cscope -i cscope.files
