# generate_test_case.py

weights = [1] * 50000
days = 50000

with open("output.txt", "w") as f:
    # Write weights as list format like [1,1,1,...]
    f.write("[" + ",".join(map(str, weights)) + "]\n")
    # Write number of days
    f.write(str(days) + "\n")
