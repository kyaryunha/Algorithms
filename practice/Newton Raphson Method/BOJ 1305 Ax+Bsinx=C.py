from decimal import Decimal
import decimal

pi = Decimal('3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647')
# pi = Decimal('3.14159265358979323846264338')


def cos(x):
    x %= (Decimal('2') * pi)
    decimal.getcontext().prec += 2
    i, lasts, s, fact, num, sign = 0, 0, 1, 1, 1, 1
    for _ in range(30):
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    decimal.getcontext().prec -= 2
    return +s


def sin(x):
    x %= (Decimal('2') * pi)
    decimal.getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    for _ in range(30):
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    decimal.getcontext().prec -= 2
    return +s


def fx(a, b, c, x):
    x = Decimal(str(x))
    return Decimal(str((a * x + b * sin(x) + c) / (a + b * cos(x))))

cnt = 1000
a, b, c = input().split()
decimal.getcontext().prec = 100
a = Decimal(str(a))
b = Decimal(str(b))
c = Decimal(str(c))

p1 = Decimal(str(1))
p2 = p1 - fx(a, b, c, p1)

while cnt >= 0:
    p2 = p1 - fx(a, b, c, p1)
    p1 = p2
    cnt = cnt - 1
    # print(cnt)
# print(Decimal(str(-p2)))
print(Decimal(str(-p2)).quantize(Decimal('1.000000')))
