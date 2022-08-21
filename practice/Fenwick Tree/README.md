# Fenwick Tree



### [BOJ 12899 데이터 구조](https://www.acmicpc.net/problem/12899)



K 번째 수를 찾는 문제이다, 구간에서 K 번째 수를 찾아라!라면 귀찮은 머지소트트리 하러 가야하지만... 

전체에서 K 번째 수를 찾는 문제이므로, 구간합으로 변경해 푼다.

구간합은 세그트리로도 풀 수 있지만, (세그트리가 글자수도 더 많고) 여러모로 귀찮으므로 펜윅으로 풀자... 

펜윅트리 구간합 플4문제를 굳이? 업로드해서 기억할만한건가 싶긴 한데, 

오랜만에 해서인지 K 번째 수 버튼 눌리자마자 머지소트트리 짜러가는 등 헷갈렸기 때문에... 기록을 해놓긴 하자... 



### [BOJ 2820 자동차 공장](https://www.acmicpc.net/problem/2820)

펜윅트리 + 오일러 투어 테크닉 

펜윅트리로 레이지프로포게이션이  필요한 구간합 세그트리를 대체한다.

- 구간 업데이트 쿼리 / 포인트 쿼리  

그리고 오일러 투어 테크닉으로 트리 순회를 연속적이게 한다. 
