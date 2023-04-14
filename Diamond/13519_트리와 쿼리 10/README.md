# [Diamond III] 트리와 쿼리 10 - 13519

[문제 링크](https://www.acmicpc.net/problem/13519)

### 문제 요약

<p> 금광 세그를 선형 구조가 아닌 트리 위에서 한다면? </p>

### 제한

TL : 2sec, ML : 512 MB

$2 ≤ N ≤ 100,000$

$1 ≤ Q ≤ 100,000$

$w_i ≤ |10,000|$


### 성능 요약

메모리: 26824 KB, 시간: 484 ms

### 분류

자료 구조(data_structures), 트리(trees), heavy-light 분할(heavy-light decomposition), 세그먼트 트리(segtree), 느리게 갱신되는 세그먼트 트리(lazy-propagation)

### comment

[이 문제](https://github.com/pill27211/Baekjoon/tree/main/Diamond/22487_Do%20use%20segment%20tree)에서 이미 대차게 얻어맞고 왔기 때문에, 사실상 복기하는 느낌으로 코드를 작성했다.

그러니 자세한 과정은 위 링크를 참고하자.

그나마 차이점이라곤 $N$ 및 $Q$의 범위이며, 정답은 $0$보다 크거나 같다는 것이다.

이에 따라 레이지 값을 뿌려줄 때

$seg[n].ls = seg[n].rs = seg[n].ms = max(lz[n], seg[n].ps)$ 가 아닌

$seg[n].ls = seg[n].rs = seg[n].ms = max(0LL, seg[n].ps)$ 의 값을 취해 주는 것이 핵심이다.

위에서 먼저 푼 문제가 답에 제한이 없음에 따라, 좀 더 일반적인 형태인 듯 하다.
