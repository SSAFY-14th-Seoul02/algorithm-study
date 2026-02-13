"""
# [Bronze II] 시험 감독 - 13458 

[문제 링크](https://www.acmicpc.net/problem/13458) 

### 성능 요약

메모리: 232752 KB, 시간: 264 ms

### 분류

수학, 사칙연산

### 제출 일자

2026년 2월 13일 13:02:41

### 문제 설명

<p>총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. i번 시험장에 있는 응시자의 수는 A<sub>i</sub>명이다.</p>

<p>감독관은 총감독관과 부감독관으로 두 종류가 있다. 총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명이고, 부감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 C명이다.</p>

<p>각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.</p>

<p>각 시험장마다 응시생들을 모두 감시해야 한다. 이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.</p>

<p>둘째 줄에는 각 시험장에 있는 응시자의 수 A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 1,000,000)가 주어진다.</p>

<p>셋째 줄에는 B와 C가 주어진다. (1 ≤ B, C ≤ 1,000,000)</p>

### 출력 

 <p>각 시험장마다 응시생을 모두 감독하기 위해 필요한 감독관의 최소 수를 출력한다.</p>

"""

# 풀이..

"""
i번 시험장에 있는 응시자의 수는 A[i]명
총감독관의 할당: 한 시험장에서 감시할 수 있는 응시자의 수 B명
부감독관의 할당: 한 시험장에서 감시할 수 있는 응시자의 수 C명

총감독관은 1명만
부감독관은 여러명

일단 총감독은 모든 방에 있어야 하는거겠지?
그럼 needs = N으로 설정
-> assistant만 계산하면 됨
"""
from math import ceil
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input()) # 시험장 개수
rooms = list(map(int, input().split())) # 방 별 응시자 수
head_proctor, assistant = map(int, input().split()) # 감독할 수 있는 응시자 수
needs = N

for room in rooms:
    lasts = room - head_proctor
    if lasts > 0:
        # needss += (lasts + assistant - 1) // assistant
        needs += ceil(lasts/assistant) 

print(needs)
    
    