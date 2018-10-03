# https://www.spoj.com/problems/AMR10F/
# we have N columns in increasing sizes, starting with A, adjacening by D
# N*A for the bottom repeating
# The rest is the area of a triangle created below f(x)=Dx: 0.5*base*height=0.5*(N-1)*ND

numOfTests = int(input())
for case in range(numOfTests):
  N,A,D = map(int, input().split())
  cookies = N*A + (0.5*N*(N-1)*D)
  print(int(cookies))
