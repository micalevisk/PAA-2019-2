# O problema da Longest Common Sequence:
# Dado duas sequências X=<x1, x2, ..., xm> e Y=<y1, y2, ..., yn>, deseja-se
# encontrar uma subsequência comum de comprimento máximo de X e Y.

DIAGONAL = '`'
CIMA = '^'
ESQUERDA = '<'


def LCS_length(X, Y):
  m = len(X)
  n = len(Y)

  B = [ ## Matriz (m)x(n) de escolhas
    ['-' for i in range(n)]
    for j in range(m)
  ]

  C = [ ## Matriz (m+1)x(n+1) de custos
    [0 for i in range(n+1)] ## PS: Apenas a primeira linha e a primeira coluna precisam ter o valor 0
    for j in range(m+1)
  ]

  ## Garantindo que a primeira linha e a primeira coluna possuem 0s
  for i in range(1, m+1):
    for j in range(1, n+1):
      if X[i-1] == Y[j-1]:
        C[i][j] = C[i-1][j-1] + 1
        B[i-1][j-1] = DIAGONAL
      else:
        if C[i-1][j] >= C[i][j-1]:
          C[i][j] = C[i-1][j]
          B[i-1][j-1] = CIMA
        else:
          C[i][j] = C[i][j-1]
          B[i-1][j-1] = ESQUERDA

  return (C, B)

def Print_LCS(B, X, i, j):
  if i < 0 or j < 0:
    return ''
  
  if B[i][j] == DIAGONAL:
    return Print_LCS(B, X, i-1, j-1) + X[i]
  if B[i][j] == CIMA:
    return Print_LCS(B, X, i-1, j)
  if B[i][j] == ESQUERDA:
    return Print_LCS(B, X, i, j-1)


# ---------------------------------- #

X = 'ABCBDAB'
Y = 'BDCABA'

(C, B) = LCS_length(X, Y)
m = len(X)
n = len(Y)

print('X=', X)
print('Y=', Y)
print('longest sequence length =', C[m][n])
print('longest sequence =', Print_LCS(B, X, m-1, n-1))

