# [Gold II] 잘못 구현한 에라토스테네스의 체 - 15897

[문제 링크](https://www.acmicpc.net/problem/15897)

### 문제 요약

<p> $Harmonic-Lemma$ </p>

### 제한

TL : 1sec, ML : 512 MB

$1 ≤ n ≤ 10^9$

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학(math), 정수론(number_theory)

### comment

$Harmonic-Lemma$를 아는가?

그리 어려운 내용도 아니고 종종 유용하게 써먹힐 때가 있을 듯 하니, 이 참에 공부해두자.

솔직히 [이 글](https://ahgus89.github.io/algorithm/Harmonic-Lemma/)만 봐도 대강 충분해 보인다. (아직 내 수준에서는..)

문제로 돌아와서, 당연히 $O(N)$을 박을 순 없다. 수열의 점화식을 정의해보면

$a_n = 1 + (n - 1) / i$ 에서 $n + Σ (n - 1) / i$ 이므로..

$Harmonic-Lemma$를 이용해 같은 값을 가지는 인덱스들을 뛰어 넘어 최종 $O(sqrt(N))$에 문제를 해결할 수 있다.
