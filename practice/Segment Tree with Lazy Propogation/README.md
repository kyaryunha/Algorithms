# Segment Tree with Lazy Propogation



- 세 문제 모두 0부터 입력 받던 1부터 입력 받던 상관이 없는데,  (구간합이나 XOR에 0으로 초기화해서..? ), 만약 쿼리 종류가 달라진다면 Initial 값 알아서 신경써줘야 할 듯



### [BOJ 10999 구간합 구하기 2](https://www.acmicpc.net/problem/10999)

Segment Tree with Lazy Propogation - 구간 합 



### [BOJ 12844 XOR](https://www.acmicpc.net/problem/12844)

Segment Tree with Lazy Propogation - 숫자 XOR 



### [BOJ 1395 스위치](https://www.acmicpc.net/problem/1395)

Segment Tree with Lazy Propogation - 01 XOR 



### [BOJ 14287 내리 칭찬3](https://www.acmicpc.net/problem/14287)

Segment Tree with Lazy Propogation - 구간합 + Euler Tour Technique



### [BOJ 18437 회사 문화 5](https://www.acmicpc.net/problem/18437)

Segment Tree with Lazy Propogation - 구간 합 변형 ( 아래를 모두 끄거나 키거나 ) + Euler Tour Technique 

Euler Tour Technique 에서 x에서 in ~ out 까지를 구하고 싶을 때, 

x를 제외하고 싶으면 (in[x]+1,out[x]) 이렇게 해야함에 주의, 

x를 포함하고 싶으면 (in[x], out[x])

