"""
BOJ6998. Tree Isomorphism

[문제]
빌보는 평생의 연인 오블립을 만났지만, 그녀가 어딘지 모르게 낯이 익어 혹시 친척 관계는 아닐지 걱정하고 있습니다.
두 사람 모두 자신의 가계를 알고 있지만, 단순히 조상들의 이름을 대조해 볼 수는 없습니다.
빌보는 조상들의 이름을 남성형으로 알고 있고, 오블립은 여성형으로 알고 있는데, 이 두 형태의 이름은 서로 연관성이 없기 때문입니다.
심지어 두 사람이 친남매 사이라고 해도, 각자 알고 있는 조상들의 이름은 모두 다를 것입니다!

빌보와 오블립은 각각 자신의 가계도를 작성했습니다. 여러분의 임무는 이름은 무시하고 두 트리가 동형(Isomorphic)인지를 판별하는 것입니다.
즉, 두 트리 사이에 일대일 대응 관계가 존재하는지 확인해야 합니다. 이때 트리는 루트(Root)가 고정된 루트 트리라고 가정합니다.

* 왼쪽 그림 (비동형): 왼쪽의 두 트리는 서로 동형이 아닙니다. `a`의 두 자식을 `x`의 두 자식과 매핑할 방법이 없기 때문입니다. `a`의 자식 중 하나는 반드시 2명의 자녀를 가져야 하지만, `x`의 자식들은 자녀가 전혀 없습니다.
* 오른쪽 그림 (동형): 오른쪽의 두 트리는 동형입니다. 매핑 관계는 다음과 같습니다:
    * `a ↔ x` (루트는 항상 서로 매핑되어야 함)
    * `b ↔ z`, `c ↔ y`, `g ↔ u`, `d ↔ w`, `e ↔ t`, `f ↔ v`
    * (참고: `d`와 `e`의 매핑을 서로 바꾸는 또 다른 동형 사상도 존재합니다.)

[입력 형식]
1.  첫 번째 줄에는 테스트 케이스의 개수(< 100)가 주어집니다.
2.  각 테스트 케이스는 두 줄로 구성되며, 각 줄은 하나의 트리를 설명합니다.
3.  트리는 전위 순회(Pre-order traversal) 순서로 노드 라벨을 나열하여 설명합니다.
    * 루트에서 시작하여 왼쪽에서 오른쪽 방향으로 잎(Leaf) 노드까지 순회하며 만나는 모든 노드 라벨을 출력합니다.
    * 각 자식 노드들의 나열이 끝날 때마다 샵 기호('#')가 표시됩니다.
    * 모든 노드 라벨과 샵 기호는 공백으로 구분됩니다.

[출력 형식]
각 테스트 케이스에 대해:
* 두 트리가 동형이면 “Isomorphic.”을 출력합니다.
* 동형이 아니면 “Not isomorphic.”을 출력합니다.
* 출력 끝에는 줄바꿈을 포함해야 합니다.

"""

from collections import deque

import sys
input = lambda: sys.stdin.readline().rstrip()

"""
두 트리의 구조가 같은지 묻는 문제인 거 같다
구조를 중첩 리스트 형태로 나타내서 비교하는 느낌으로 풀기 
"""

# 입력 토큰을 재귀적으로 읽어서 중첩 리스트로 변환하는 함수
def parse(q):
    token = q.popleft()
    # 자식 목록의 끝을 만나면 → None을 리턴해서 호출한 쪽에 알림
    if token == '#':
        return None
    
    # 현재 노드의 자식들을 재귀적으로 파싱
    # '#'를 만나서 None이 리턴될 때까지 반복
    children = []
    while True:
        child = parse(q)
        if child is None:
            break
        children.append(child)

    return children

# 트리를 순서에 무관한 정규화 문자열로 변환하는 함수
# 핵심: 자식들의 문자열을 정렬해서 순서가 달라도 같은 결과가 나오게 함
def canonical(tree):
    # 리프 노드이면 '()' 반환
    if not tree:
        return '()'
    # 각 자식 서브트리를 재귀적으로 문자열로 변환
    child_strs = []
    for child in tree:
        child_strs.append(canonical(child))
    # 정렬 → 자식 순서가 달라도 같은 구조면 같은 문자열이 됨
    child_strs.sort()
    # 괄호로 감싸서 서로 다른 구조가 구분되도록 함
    return '(' + ''.join(child_strs) + ')'

# 두 트리가 동형인지 확인하는 함수
def is_isomorphic(tree1, tree2):
    # 두 트리의 구조가 같으면 True, 다르면 False 반환
    return True if canonical(tree1) == canonical(tree2) else False

# main
tc = int(input())
for _ in range(tc):
    a = list(input().split(' '))
    b = list(input().split(' '))
    # 각 입력을 deque로 만들어서 parse에 전달
    tree1 = parse(deque(a))
    tree2 = parse(deque(b))
    # 두 트리의 정규화 문자열이 같으면 isomorphic, 그렇지 않으면 not isomorphic 출력
    if is_isomorphic(tree1, tree2):
        print("The two trees are isomorphic.")
    else:
        print("The two trees are not isomorphic.")
