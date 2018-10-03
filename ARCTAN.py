# https://www.spoj.com/problems/ARCTAN/
# arctan(1/A) = arctan(1/B) + arctan(1/C)
# arctan(1/A) - arctan(1/B) = arctan((1/A-1/B)/(1+1/AB)) = arctan(1/C)
# (1/A-1/B)/(1+1/AB) = 1/C
# (B-A)*(AB^-1)*(1 + (AB^-1))^-1 = 
# (B-A) * (AB(1+(AB)^-1))^-1 =
# (B-A)/(AB + 1) = 1/C
# C = (AB+1)/(B-A)

numOfTests = int(input())
for case in range(numOfTests):
  A = int(input())
  MinSum = 9223372036854775807
  maxRange = 2*(A+1)
  for B in range(A+1, maxRange):
    C = (A*B+1)/(B-A)
    MinSum = min(MinSum, B + C)
  print(int(MinSum))
  
  
  
  
