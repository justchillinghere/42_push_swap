import random

# Function to generate a list of 10 random unique integers
def generate_unique_integers():
    min_limit = -1000
    max_limit = 1000
    num_integers = 100

    # Generate random unique integers using a set to ensure uniqueness
    unique_integers = set()
    while len(unique_integers) < num_integers:
        unique_integers.add(random.randint(min_limit, max_limit))

    return list(unique_integers)

# Generate 10 random unique integers
random_integers = generate_unique_integers()

# Convert the list to a space-separated string
random_integers_str = " ".join(str(x) for x in random_integers)

# Write the random integers to a file
file_name = "random_integers.txt"
with open(file_name, "w") as file:
    file.write(random_integers_str)
