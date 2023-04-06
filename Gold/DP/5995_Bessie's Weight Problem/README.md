# [Gold V] Bessie's Weight Problem - 5995

[문제 링크](https://www.acmicpc.net/problem/5995)

### 문제 요약

<p> 기본 냅색 문제 </p>

### 제한

TL : 1sec, ML : 128 MB

$1 ≤ N ≤ 500$

$5 <= H <= 45,000$

### 성능 요약

메모리: 2196 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍(dp), 배낭 문제(knapsack)

### comment

냅색 기본 문제다.

$dp[i]$ : $i$만큼의 건초를 소비할 수 있는가?

이후 $H$부터 하나씩 내려오며 표시가 되어있는 가장 처음의 수가 곧 답이 다.
