'''
BOJ1991 : 트리 순회 (S1)

해결 방법 : 전위, 중위, 후위 순회에 맞게 트리 순회 코드 구현
'''

import sys
input = sys.stdin.readline  

def preorder(node):   # 전위: 루트 → 왼쪽 → 오른쪽
    if node == '.':
        return
    result.append(node)
    preorder(tree[node][0])
    preorder(tree[node][1])

def inorder(node):    # 중위: 왼쪽 → 루트 → 오른쪽
    if node == '.':
        return
    inorder(tree[node][0])
    result.append(node)
    inorder(tree[node][1])

def postorder(node):  # 후위: 왼쪽 → 오른쪽 → 루트
    if node == '.':
        return
    postorder(tree[node][0])
    postorder(tree[node][1])
    result.append(node)

n = int(input())
tree = {}

for _ in range(n):
    node, left, right = input().split()
    tree[node] = (left, right)

result = []
preorder('A')
print(''.join(result)) 

result = []
inorder('A')
print(''.join(result))

result = []
postorder('A')
print(''.join(result))