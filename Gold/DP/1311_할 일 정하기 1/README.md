
# [Gold I] 할 일 정하기 1 - 1311

[문제 링크](https://www.acmicpc.net/problem/1311)

### 문제 요약

<p> N명의 사람이 각각 하나씩 N개의 일을 처리해야 한다. 각 비용들이 주어질 때, 전체 비용의 최솟값을 구해보자. </p>

### 제한

TL : 1sec, ML : 512 MB

1 ≤ N ≤ 20

1 ≤ D_i ≤ 10,000

### 성능 요약

메모리: 83944 KB, 시간: 196 ms

### 분류

다이나믹 프로그래밍(dp), 비트마스킹(bitmask), 비트필드를 이용한 다이나믹 프로그래밍(dp_bitfield)

### comment

비트dp 기본 문제이다.

i번째 사람이 i번째 일을 할 때, i + 1번째 일을 할 때, ... 로 분기해가며 최댓값을 찾아주면 된다.

비트dp에 관해선 [여기](https://github.com/pill27211/Baekjoon/blob/main/Gold/DP/2098_%EC%99%B8%ED%8C%90%EC%9B%90%20%EC%88%9C%ED%9A%8C/README.md)에서 tsp를 다루며 설명 했었다.

여기선 딱히 추가로 설명해야 할 부분은 없어 보인다.
