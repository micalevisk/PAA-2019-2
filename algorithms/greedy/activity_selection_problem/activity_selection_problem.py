def max_compatible_activies(S, F, ids):
  #                         |  |
  #                         |  +--> finish times
  #                         +--> start times
  n = len(ids) # number of activities
  A = [ ids[0] ] # the first actitivy is always selected
  i = 0

  for m in range(1, n):
    if S[m] >= F[i]:
      A.append( ids[m] )
      i = m

  return A


# --------------------------------- #

ids   = ['1', '2', '3', '4', '5', '6', '7'] ## Sorted by finish time
start = [  2,   1,   6,   5,   8,   4, 10 ]
finish= [  6,   7,   9,  11,  12,  13, 14 ]

print(
  max_compatible_activies(start, finish, ids)
)

