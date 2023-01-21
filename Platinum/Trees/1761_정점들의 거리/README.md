
# [Platinum V] 정점들의 거리 - 1761

[문제 링크](https://www.acmicpc.net/problem/1761)

### 문제 요약

<p> n개의 정점으로 이루어진 트리와 q개의 쿼리가 주어진다. 각 쿼리의 두 정점쌍에 대한 거리를 구해보자. </p>

### 제한

TL : 2sec, ML : 128 MB

1 ≤ n, q ≤ 100,000

### 성능 요약

메모리: 19520 KB, 시간: 96 ms

### 분류

자료구조(data_structures), 트리(trees), 최소 공통 조상(lowest common ancestor), 희소 배열(sparse table)

### comment

[여기](https://github.com/pill27211/Baekjoon/tree/main/Platinum/Trees/11438_LCA%202)에서 LCA에 대해 다뤘었다.

이 문제 역시 비슷한 흐름이다.

전처리 하면서 정점들의 깊이를 메길 때 1번 정점으로부터 해당 정점까지의 거리(W[i])를 저장해두자.

그럼 임의의 두 정점(i, j)에 대한 거리는 다음과같이 간단한 식으로 정리할 수 있다.

d = W[i] + W[j] - 2 * W[lca(i, j)];
