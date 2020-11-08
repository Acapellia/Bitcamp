
# f = open("새파일.txt", "w")
# f.close()

# f = open("새파일.txt", "w", encoding="utf-8")
# for i in range(1, 11):
#     data = "%d번째 줄입니다\n" % i
#     f.write(data)
# f.close()

# f = open("새파일.txt", "r", encoding="utf-8")
# line = f.readline()
# print(line)
# f.close()


# f = open("새파일.txt", "r", encoding="utf-8")
# while True:
#     line = f.readline()
#     if not line:
#         break
#     print(line, end="")
# f.close()

# f = open("새파일.txt", "r", encoding="utf-8")
# lines = f.readlines()
# for line in lines:
#     print(line, end="")
# f.close()

# f = open("새파일.txt", "r", encoding="utf-8")
# data = f.read()
# print(data)
# f.close()

# f = open("foo.txt", "w", encoding="utf-8")
# f.write("Life is too short, you need python")
# f.close()

with open("foo.txt", "w", encoding="utf-8") as f:
    f.write("Life is too short, you need python")












