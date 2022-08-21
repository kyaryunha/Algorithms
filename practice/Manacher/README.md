# Manacher



### [2022 Kickstart Round E - C](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb0f5/0000000000ba82c5)

문제 요약: 

문제 요약하면 최대 10만글자의 팰린드롬 문자열 P이 주어지고, 1글자 이상의 다른 팰린드롬 문자열 Q을 붙였을 때, PQ도 팰린드롬이 되게하는 Q를 구하라.



풀이 요약: 

manacher - round 할 때 왼쪽은 그대로 놓고, 오른쪽은 범위 넘어가면 그냥 무조건 ok 하게 작성한다.

main - 각 for 문의 i 에서 i를 가운데로 하여 만든 팰린드롬이 범위를 넘어간다면, 0에서 ((i-((2*N)-i))/2 인덱스(왼쪽에서 오른쪽 개수만큼 뺀 부분) 까지 slice 한 문자열이 팰린드롬인지 확인한다. 