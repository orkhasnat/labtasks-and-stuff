# k,n=map(int,input().split())
# array=[int(x) for x in input().split()]
# #array=list(map(int,input().split()))
# print(sum(array))


class Line:
    def __init__(self, cord1, cord2):
        self.x1, self.y1 = cord1
        self.x2, self.y2 = cord2
        # self.coord=cord1 ----->atrribute

    def distance(self):
        # x1,x2=self.coord
        root = (self.x1 - self.x2) ** 2 + (self.y2 - self.y1) ** 2
        return root ** 0.5

    def slope(self):
        # x1,x2=self.coord
        return (self.y1 - self.y2) / (self.x1 - self.x2)


class Cylinder:

    pi = 3.1415

    def __init__(self, height=1, radius=1):
        self.h = height
        self.r = radius

    def volume(self):
        return self.pi * self.r * self.h * self.r

    def surface_area(self):
        return (2 * self.pi * self.r * self.h) + (2 * self.pi * self.r * self.r)


class Account:

    def __init__(self,owner,balance=0):
        self.owner=owner
        self.balance=balance
    def __str__(self):
        #if i wanted to print(bank) then i would use this *thing(constructor?? ig)
        #didnt understand it correctly 
        return f"Owner: {self.owner} \nBalance:{self.balance}"
        #this methods returns the same thing a print() returns

    def deposit(self,amount):
        self.balance+=amount 
        print(f"You've successfully deposited ${amount}.")
        print(f"Thank you for using our service {self.owner} and your balance is ${self.balance}.")
    def withdrawl(self,amount):
        if amount<=self.balance :
            self.balance-=amount
            print(f"You've successfully withdrawn ${amount}.")
        else:
            print("You dont have enough money!!")
        print(f"Thank you for using our service {self.owner} and your balance is ${self.balance}.")


if __name__ =="__main__":
    line = Line((3, 2), (8, 10))
    print(line.distance())
    print(line.slope())

    cyl = Cylinder(2, 3)
    print(cyl.volume())
    print(cyl.surface_area())

    bank=Account("Jose",5000)
    print(bank) # __str__ method lets me do this otherwise not gonna work  
    bank.deposit(500)
    bank.withdrawl(6500)
    bank.withdrawl(5400)
