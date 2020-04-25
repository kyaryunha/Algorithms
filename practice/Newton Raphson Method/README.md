### Newton Raphson Method



##### [BOJ 14786 Ax + Bsinx = C](https://www.acmicpc.net/problem/14786)

그냥 Newton Raphson Method 문제 



##### [BOJ 1305 Ax + Bsinx = C2](https://www.acmicpc.net/problem/1305)

14786과 동일하지만, 추가적으로 실수 오차를 신경써줘야 하는 문제.

Python Big Decimal를 쓰자. 

위의 14786번 코드를 c++에서 python 코드로 번역한 다음에,  double을 decimal로 변경하자.

추가적으로 decimal에서 python의 cos, sin이 안되는데, Big Decimal 공식 문서를 보면 Big Decimal에서 cos, sin을 구하는 방법이 나와 있다. (직접 짤 수도 있겠지만)

해당 코드를 가져온 다음, range가 오래 걸릴 수 있으므로, 적당히 for 문으로 하고, 30번 정도만 돌게 하자. 

