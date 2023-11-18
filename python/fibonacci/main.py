from time import sleep


def fib(recursion_max):
    fib_num_a: int = 0
    fib_num_b: int = 1
    print(f"{fib_num_a}\n{fib_num_b}")

    for n in range(2, recursion_max):
        fib_num_c = fib_num_a + fib_num_b
        print(fib_num_c)

        fib_num_a = fib_num_b
        fib_num_b = fib_num_c


user_input: int = None
while True:
    try:
        user_input = int(input("\nHow many recursions?: "))
        if user_input < 2:
            raise ValueError
        break
    except ValueError as e:
        print(f"{type(e).__name__}: Enter a number higher than 2.")
        sleep(1)
        continue
fib(user_input)
