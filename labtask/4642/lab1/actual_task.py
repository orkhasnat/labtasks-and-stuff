import numpy as np
import matplotlib.pyplot as plt


def sign(x):
  return -1 if x<0 else 0 if x==0 else 1
def eval_equ(f,x):
  sum=0
  y=1
  for i in f[::-1]:
    sum+=i*y
    y*=x
  return sum

def bisection_method(f, xl, xu, epsilon):
  #write your implementation here
  global count,errs
  count=0
  xm_old=0
  errs=[]
  while True:
    count+=1
    xm = (xl + xu) / 2
    err=abs((xm-xm_old)/(xm+0.0000001))
    # err=np.array(err)
    # errs.append(err)
    # np.append(errs,err)
    errs.append(err)
    # print(errs)
    xm_old=xm
    f_midpoint = eval_equ(f, xm)
    if abs(f_midpoint) < epsilon:
      return xm
    elif sign(f_midpoint) == sign(eval_equ(f, xl)):
      xl = xm
    else:
      xu = xm


#Write a driver code here for calling the function and testing it
# count=0
f1= np.array([1,-2,0,4])
f2=np.array([1,-2,-3])
# print(eval_equ(f1,-1))
# print(bisection_method(f1,-3,3,0.01))
print(bisection_method(f2,2,6,0.01))

iters=np.arange(0,count)
print(iters,errs)
plt.plot(iters, errs)
plt.title("Iterations vs values plot")
plt.xlabel("Iteration")
plt.ylabel("Relative Error")
plt.show()
