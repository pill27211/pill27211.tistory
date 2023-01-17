
# [Gold I] 외판원 순회 3 - 16991

[문제 링크](https://www.acmicpc.net/problem/16991)

### 문제 요약

<p> Do you know TSP ? </p>

### 제한

TL : 1sec, ML : 512 MB

2 ≤ N ≤ 16

-1,000 ≤ n_x, n_y ≤ 1,000

두 도시의 위치가 같은 경우는 없다.

### 성능 요약

메모리: 10228 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍(dp), 비트마스킹(bitmask), 비트필드를 이용한 다이나믹 프로그래밍(dp_bitfield), 외판원 순회 문제(tsp)

### comment

기본 외판원 순회 문제에, 간단한 좌표 계산이 추가된 문제이다.

모든 쌍에 대해 W[i][j], W[j][i]를 유클리드 거리를 통해 채워준 뒤, tsp를 돌려주면 된다.

tsp에 있어선 [여기](https://github.com/pill27211/Baekjoon/blob/main/Gold/DP/2098_%EC%99%B8%ED%8C%90%EC%9B%90%20%EC%88%9C%ED%9A%8C/README.md)에서 설명했으므로 생략.
