# we have a wall, and we are connecting a fence to it on two points to get the max area
# considering the wall as a rod, the fence as a string. we have a semicircle
# The area of semicircle: (r^2)/(2PI)
# 1/(PI*2) = ~0.15915494309

while True:
  l = int(input())
  if l == 0: break
  print("%.2f" % (l*l*0.15915494309))
