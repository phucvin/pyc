sudo apt install gcc python3-dev clang-format python3

gcc $(python3-config --cflags --embed) empty.c $(python3-config --embed --ldflags) -o empty

cd ..

python3 pyc tests/recursive_fib.py