
# [Platinum V] A Sorting Problem - 23336

[문제 링크](https://www.acmicpc.net/problem/23336)

### 문제 요약

<p> inversion counting </p>

### 제한

TL : 3sec, ML : 1024 MB

1 < n ≤ 200,000

1 ≤ p[i] ≤ n

### 성능 요약

메모리: 4364 KB, 시간: 44 ms

### 분류

자료구조(data_structures), 세그먼트 트리(segtree), 분할 정복(divide_and_conquer), 정렬(sorting)

### comment

기본적인 inversion counting 문제이다.

정렬 후 합세그로 카운트 해주어도 되고 분할 정복으로 카운트 해주어도 되고.. 편한대로 하면 될 것 같다.

나는 전자로 구현했으며, 간단한 로직이라 펜윅 트리를 이용하였다.
