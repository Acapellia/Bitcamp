# def add(a, b):
#     return a+b
#
# def sub(a, b):
#     return a-b
#
# def mul(a, b):
#     return a*b
#
# def div(a, b):
#     return a/b
#
# print(add(100, 200))
# print(sub(100, 200))
# print(mul(100, 200))
# print(div(100, 200))


# def arithCalc(a, b):
#     return a+b, a-b, a*b, a/b
#
# r0, r1, r2, r3 = arithCalc(100, 50)
# print(r0)
# print(r1)
# print(r2)
# print(r3)


# def sum_many(*args):
#     sum = 0
#     for i in args:
#         sum = sum + i
#     return sum
#
# print(sum_many(1, 2, 3, 4, 5))
# print(sum_many(1, 2, 3, 4, 5, 6, 7, 8, 9))

# a = 1
#
# def vartest(a):
#     a = a + 1
#
# vartest(a)
# print(a)

a = 1

def vartest():
    global a
    a = a + 1

vartest()
print(a)








