# try:
#     print(1231/0)
# except ZeroDivisionError as e:
#     print(e)

try:
    f = open("없는 파일.txt","r")
except FileNotFoundError as e:
    print(e)
finally:
    print("예외랑 상관없이 무조건 실행되는 부분")
    f.close()