import random

file_name = "input.txt"
gen_file = open("input.txt", "w")

for i in range(0, 7):
	gen_file.write(str(random.randint(0, 100)))
	if i is not 9:
		gen_file.write(" ")
	else:
		gen_file.write("\n")
