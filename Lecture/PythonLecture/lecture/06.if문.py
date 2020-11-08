# money = 1
# if money:
#     print("현재 돈이 있다")
#     print("택시를 타고 가라")
# else:
#     print("현재 돈이 없다")
#     print("걸어 가라")



# money = 2000
# card = 1
# if money >= 3000 or card:
#     print("택시를 타고 가라")
# else:
#     print("걸어 가라")

# a = ["홍길동", "임꺽정", "장길산"]
# print("홍길동" in a)
# print("차돌바위" in a)

# pocket = ['paper', 'cellphone', 'money']
# if 'money' in pocket:
#     print("택시를 타고 가라")
# else:
#     print("걸어 가라")


# pocket = ['paper', 'cellphone']
# card = 1
# if 'money' in pocket:
#     print("택시를 타고 가라")
# else:
#     if card:
#         print("택시를 타고 가라")
#     else:
#         print("걸어 가라")


pocket = ['paper', 'cellphone']
card = 1
if 'money' in pocket:
    print('택시를 타고 가라')
elif card:
    print("택시를 타고 가라")
else:
    print("걸어 가라")









