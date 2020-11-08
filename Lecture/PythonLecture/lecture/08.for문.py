# num_list = ["one", "two", "three"]
# for num in num_list:
#     print(num)

# marks = [90, 25, 67, 45, 80]
# number = 0
# for mark in marks:
#     number = number + 1
#     if mark >= 60:
#         print("%d번 학생은 합격입니다" % number)
#     else:
#         print("%d번 학생은 불합격입니다" % number)

# a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# for i in a:
#     print(i, end=", ")

# a = range(10)
# print(a, type(a))
#
# for i in range(10):
#     print(i, end=" ")

# sum = 0
# for i in range(1, 11):
#     sum = sum + i
# print("합은 %d입니다" % sum)

# print('*' * 80)
# for i in range(2, 10):
#     for j in range(1, 10):
#         print("%dx%d=%d" % (i, j, i*j), end='\t')
#     print()
# print('*' * 80)

# 3의 배수를 5개 리스트에 저장해라
# result = []
# for i in range(1, 6):
#     result.append(i*3)
# print(result)

# result = [i*3 for i in range(1, 6)]
# print(result)

# 3의 배수이면서 짝수인 것
result = [i*3 for i in range(1, 20) if (i*3)%2 == 0]
print(result)










