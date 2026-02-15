import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solve():
    N, M = map(int, input().split())
    adj = [[] for _ in range(N + 1)]
    for i in range(1, M + 1):
        u, v = map(int, input().split())
        adj[u].append((v, i))
        adj[v].append((u, i))

    visited = [False] * (N + 1)
    is_leaf = [False] * (N + 1)

    components = []

    def dfs(u, c_nodes, c_edges):
        visited[u] = True
        c_nodes.append(u)

        leaf = True
        for v, edge_idx in adj[u]:
            if not visited[v]:
                leaf = False
                c_edges.append(edge_idx)
                dfs(v, c_nodes, c_edges)

        is_leaf[u] = leaf

    for i in range(1, N + 1):
        if not visited[i]:
            nodes = []
            edges = []
            dfs(i, nodes, edges)
            components.append((nodes, edges))

    if len(components) > 2:
        print(-1)
        return
    elif len(components) == 1:
        all_nodes = components[0][0]

        leaf_node = -1
        root_node = -1

        for x in all_nodes:
            if is_leaf[x]:
                leaf_node = x
            else:
                root_node = x

            if leaf_node != -1 and root_node != -1:
                break
        else:
            print(-1)
            return

        components = []
        visited = [False] * (N + 1)

        visited[leaf_node] = True

        nodes_main = []
        edges_main = []
        dfs(root_node, nodes_main, edges_main)

        components.append((nodes_main, edges_main))
        components.append(([leaf_node], []))

    if len(components[0][0]) == len(components[1][0]):
        print(-1)
        return

    print(len(components[0][0]), len(components[1][0]))
    print(*components[0][0])
    print(*components[0][1])
    print(*components[1][0])
    print(*components[1][1])

if __name__ == "__main__":
    solve()