import random

# n = 1024
n = 4096

A = [[random.random() for row in range(n)] for col in range(n)]
B = [[random.random() for row in range(n)] for col in range(n)]
C = [[0 for row in range(n)] for col in range(n)]

for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]


# # The for..in loop is much slower. See https://claude.ai/chat/5ac8afd2-24d8-4bf8-91af-4dc2d2673b40 for a deep dive.
# A = []
# B = []
# C = []
# for col in range(n):
#     A.append([])
#     B.append([])
#     C.append([])

#     for row in range(n):
#         A[col].append(random.random())
#         B[col].append(random.random())
#         C[col].append(0)
