def lcworc(self, s):
  visited = {}
  start = 0
  max_len = 0
  for i, c in enumerate(s):
    if c in visited and start <= visited[c]:
      start = visited[c] + 1
    else:
      max_len = max(max_len, i - start + 1)
    visited[c] = i
  return max_len