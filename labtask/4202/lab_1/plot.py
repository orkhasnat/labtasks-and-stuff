# import matplotlib.pyplot as plt
# #import numpy as np

# voltage=[0.1,0.8,0.9,1,1.1,1.3,1.6,1.7,1.8,1.9,2,2.2,2.4]
# current=[-1,5,10,12.5,14.5,25,37.5,43.5,47,55,60,78,95]
# plt.scatter(voltage,current)
# plt.title("I-V Characteristics")
# plt.ylabel("Current")
# plt.xlabel("Voltage")
# plt.show()


X=[0.1,0.8,0.9,1,1.1,1.3,1.6,1.7,1.8,1.9,2,2.2,2.4] ##voltage
Y=[-1,5,10,12.5,14.5,25,37.5,43.5,47,55,60,78,95]  ##current

# solve for a and b
def best_fit(X, Y):

    xbar = sum(X)/len(X)
    ybar = sum(Y)/len(Y)
    n = len(X) # or len(Y)

    numer = sum([xi*yi for xi,yi in zip(X, Y)]) - n * xbar * ybar
    denum = sum([xi**2 for xi in X]) - n * xbar**2

    b = numer / denum
    a = ybar - b * xbar

    print('best fit line:\ny = {:.2f} + {:.2f}x'.format(a, b))

    return a, b

# solution
a, b = best_fit(X, Y)
#best fit line:
#y = 0.80 + 0.92x

# plot points and fit line
import matplotlib.pyplot as plt
plt.scatter(X, Y)
yfit = [a + b * xi for xi in X]
#plt.plot(X, yfit)
plt.title("I-V Characteristics")
plt.ylabel("Current")
plt.xlabel("Voltage")
plt.show()


#####################################################################

# voltage(V)        current(mA)
# 0.1                N/A~
# 0.2                N/A~
# 0.3                N/A~
# 0.4                N/A~
# 0.5                N/A~
# 0.6                N/A~
# 0.7                N/A~
# 0.8                5~
# 0.9                10~
# 1.0                12.5~
# 1.1                14.5~
# 1.2                18~
# 1.3                25~
# 1.4                26.5~
# 1.5                32~
# 1.6                37.5~
# 1.7                43.5~
# 1.8                47~
# 1.9                50
# 2                  53~
# 2.1                
# 2.2                62~
# 2.3                
# 2.4                73~
# 2.5    
# 2.8                           