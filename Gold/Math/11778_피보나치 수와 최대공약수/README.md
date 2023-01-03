
# [Gold I] 피보나치 수와 최대공약수 - 11778

[문제 링크](https://www.acmicpc.net/problem/11778)

### 문제 요약

<p> n과 m이 주어진다. 이때, n번째 피보나치 수와 m번째 피보나치 수의 최대공약수를 1e9 + 7으로 나눈 나머지값을 구해보자. </p>

### 제한

TL : 1sec, ML : 256 MB

1 ≤ n, m ≤ 1,000,000,000,000,000,000

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학(math), 정수론(number_theory), 분할 정복을 이용한 거듭제곱(exponentiation_by_squaring)

### comment

이 문제 역시 [여기](https://github.com/pill27211/Baekjoon/tree/main/Gold/Math/11444_%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20%EC%88%98%206)서 다룬 내용인
d'Ocagne's identity 를 이용해 빠르게 피보나치 수를 구해주자. 저 문제와 차이점이 있는데, 바로 gcd(f(n), f(m))의 값을 구해야 한다.

단순히 f(n)과 f(m)을 구한 뒤 이들의 gcd를 찾으면, 바로 틀이다.

알다시피 이건 모듈러 연산에 의해 원본 추정값이 모두 소실된 상태이기 때문에 이 값들로 gcd를 찾아봤자 제대로 된 답이 나올리 만무하다.

결론부터 말하면, gcd(f(n), f(m)) = f(gcd(n, m))이다. 증명은 [이 글](https://hapby9921.tistory.com/entry/BOJ-11778-%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98-%EC%88%98%EC%99%80-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98)을
보면 어렵지 않게 이해할 수 있을 것이다.

항상 대충 끄적여보면 직관은 맞다고 하는데 이후 증명이 문제다.. 내 얕은 수학 지식을 탓해야지...
