# [Diamond IV] 국제 메시 기구 - 17429

[문제 링크](https://www.acmicpc.net/problem/17429)

### 문제 요약

<p>트리가 주어지면, 6가지의 쿼리를 적절히 처리해보자. (단, 출력에 있어서 2^32로 나눈 나머지를 출력해야 한다.)</p>

### 제한

TL : 3sec, ML : 1024 MB

1 ≤ N ≤ 500,000

1 ≤ Q ≤ 100,000

{0 || 1 } <= update value <= 10^9

### 성능 요약

메모리: 127500 KB, 시간: 1148 ms

### 분류

자료구조(data_structures), 트리(trees), 세그먼트 트리(segtree), 느리게 갱신되는 세그먼트 트리(lazyprop)

오일러 투어 테크닉(euler_tour_technique), heavy-light 분할(hld)


### comment

처음 보자마자 든 생각은 [이 문제](https://www.acmicpc.net/problem/13925)가 생각 났다. (단지 트리 위에서 진행되기 때문에 HLD가 필요했고, 쿼리 종류도 많아 구현량이 적지 않았음)

한가지 출제자의 배려(?)인지는 모르겠으나 출력에 있어서 항상 2^32로 나눈 나머지를 출력해야 한다는 것이다.

바꿔 말하면 long long, unsigned long long 등으로 모듈러 연산에 스트레스 받을 필요 없이 역으로 unsigned int 자료형을 사용하면, 모듈러 연산을 아예 할 필요가 없게 된다.
