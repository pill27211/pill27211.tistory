# [Gold IV] Alias - 21222

[문제 링크](https://www.acmicpc.net/problem/21222)

### 문제 요약

<p> hash + dijkstra </p>

### 제한

TL : 1sec, ML : 512 MB

$2 ≤ n ≤ 1,000$

$1 ≤ q, m ≤ 1,000$

$1 ≤ t_i ≤ 10^9$

### 성능 요약

메모리: 10016 KB, 시간: 8 ms

### 분류

자료 구조(data structures), 그래프 이론(graphs), 해시를 사용한 집합과 맵(hash_set), 다익스트라(dijkstra)

### comment

hash로 각 단어들을 넘버링하고, 모든 단어로부터의 다익스트라를 돌려주면 된다.

이를 전처리 $O(N * ElogE)$, 쿼리 당 $O(1)$에 응답해도 되고,

매 쿼리마다 주어진 단어로부터 다익스트라를 돌려도 될 것 같다.

범위가 워낙 친절해서..
