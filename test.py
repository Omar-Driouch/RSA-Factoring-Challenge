import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def prime_factors(n):
    factors = []
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            factors.append(divisor)
            n //= divisor
        divisor += 1

    return factors

def find_and_print_prime_factors_in_file(file_name):
    try:
        with open(file_name, 'r') as file:
            lines = file.readlines()
            for line in lines:
                numbers_in_line = [int(num) for num in line.split() if num.isdigit()]
                for number in numbers_in_line:
                    factors = prime_factors(number)
                    if is_prime(number):
                        print(f"The number {number} is prime.")
                    else:
                        print(f"The prime factors of {number} are: {factors}")
    except FileNotFoundError:
        print("File not found.")

# Usage: python your_script.py your_file.txt
import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python your_script.py your_file.txt")
    else:
        file_name = sys.argv[1]
        find_and_print_prime_factors_in_file(file_name)
