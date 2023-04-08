# [Gold I] 합성함수와 쿼리 - 17435

[문제 링크](https://www.acmicpc.net/problem/17435)

### 문제 요약

<p> sparse table를 이용한 binary lifting으로 쿼리를 빠르게 처리해보자. </p>

### 제한

TL : 1sec, ML : 512 MB

$1 ≤ m ≤ 200,000$

$1 ≤ n ≤ 500,000$

$1 ≤ N_i ≤ 1,000,000,000$

### 성능 요약

메모리: 16864 KB, 시간: 220 ms

### 분류

자료 구조(data_structures), 희소 배열(sparse table)

### comment

sparse table 대표 예제이다.

LCA 문제들을 많이 풀어 봤다면 알겠지만 $O(NlogN)$의 전처리 후 $O(N)$ 쿼리를 $O(logN)$로 줄여주는 획기적인 테크닉이다.

만약 이런 유형을 처음 접한다면, binary lifting에 대해 공부해 보는 걸 추천한다.
