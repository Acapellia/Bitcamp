# 파이썬의 자료구조형 자료형
# 1) List 리스트 : [1,2,3,4]
#     순서가 있는 선형구조
#     삽입, 삭제
# 2) Tuple 튜플 : (1,2,3,4)
#     순서가 있는 선형구조
#     읽기 전용 리스트
# 3) Set 셋 : {1,2,3,4}
#     집합, 순서가 없음
#     읽기 전용 리스트
# 4) Dictionary 딕셔너리 : 맵
#     키 : 값

a = [1,2,3]
#print(a)
# print(type(a))
# print(a[0])
# a = ["홍길동", "임꺽정", "장길산", "차돌바위", "일지매", "전우치"]
# print(a[1:3])
# b = ["Henry", "Albert", "James"]
# c = a + b
# print(c)
# print(a*2)
# b[1] = "Alex"
# print(b)
# del b[1]
# print(b)
# a.append(4)
# a.append(9)
# a.append(7)
# print(a)
# a.sort()
# print(a)
# a.reverse()
#print(a)
# cnta = a.count(1)
# print(cnta)
a = {1,2,3,4}
b = {2,3,4,5}

# print(a & b) # 교집합
# print(a | b) # 합집합
# print(a.union((b)))
# print(a.difference(b))

# List<-> Tuple <-> Set 사이의 자유로운 상호변환
# a = 10
# b = 20
# # a,b = 10,20
# a,b = b,a # Tuple 형태로 변환하여 전송
# print(a)
# print(b)

# a = ("홍길동", "임꺽정")
# #a.append("장길산") # 튜플은 삽입이 안됨
# l = list(a)
# l.append("장길산")
# a = l
# print(a)

# a = ["hong", "jang", "im","hong"]
# print(a)
# a = set(a)
# print(a)
# a = list(a)
# print(a)

# Dictionary : 검색에 최적화
# a = {"name" : "hong", "age":24,"height":174.3}
# print(a)
# print(type(a))
# print(a["name"])
# b = {}
# print(type(b))
# c = set()
# print(type(c))
# b["name"] = "park"
# b["age"] = 25
# print(b["name"])

a = ["hong", 24, 174.5]
b = ["im", 33, 189.5]
c = ["jang", 34, 175.6]
d = {}
d["hong"] = a
d["im"] = b
d["jang"] = c
print(d["hong"])
print(d["im"])
print(d["jang"])