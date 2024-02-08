gcc test_generator.c ../src/generator.c ../lib/my/my_strlen.c -I ../include -lcriterion
valgrind ./a.out