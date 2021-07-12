numbers = {
    "0": "ZERO",
    "1": "ONE",
    "2": "TWO",
    "3": "THREE",
    "4": "FOUR",
    "5": "FIVE",
    "6": "SIX",
    "7": "SEVEN",
    "8": "EIGHT",
    "9": "NINE"
}
#import heapq

def heappush(heap, item):
    heap.append(item)
    _siftdown(heap, 0, len(heap)-1)

def heappop(heap):
    lastelt = heap.pop() 
    if heap:
        returnitem = heap[0]
        heap[0] = lastelt
        _siftup(heap, 0)
        return returnitem
    return lastelt

def _siftdown(heap, startpos, pos):
    newitem = heap[pos]
    # Follow the path to the root, moving parents down until finding a place
    # newitem fits.
    while pos > startpos:
        parentpos = (pos - 1) >> 1
        parent = heap[parentpos]
        if newitem < parent:
            heap[pos] = parent
            pos = parentpos
            continue
        break
    heap[pos] = newitem

def _siftup(heap, pos):
    endpos = len(heap)
    startpos = pos
    newitem = heap[pos]
    # Bubble up the smaller child until hitting a leaf.
    childpos = 2*pos + 1    # leftmost child position
    while childpos < endpos:
        # Set childpos to index of smaller child.
        rightpos = childpos + 1
        if rightpos < endpos and not heap[childpos] < heap[rightpos]:
            childpos = rightpos
        # Move the smaller child up.
        heap[pos] = heap[childpos]
        pos = childpos
        childpos = 2*pos + 1
    # The leaf at pos is empty now.  Put newitem there, and bubble it up
    # to its final resting place (by sifting its parents down).
    heap[pos] = newitem
    _siftdown(heap, startpos, pos)

class Node:
    def __init__(self, ch, freq):
        self.ch = ch
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
            return self.freq < other.freq

    def __eq__(self, other):
            if (other == None):
                return False
            if (not isinstance(other, Node)):
                return False
            return self.freq == other.freq

encoded = []
prefix={}

def genString():
    id = input("What is your Id:\t")
    #id = "190041113"
    gen = "MYIDIS"
    for i in id[-4:]:
        gen = gen + numbers[i]
    print("The generated string is\t", gen)
    return gen


def frequency(str):
    freq = {}
    for ch in str:
        if not ch in freq:
            freq[ch] = 0
        freq[ch] += 1
    return freq
    


def makeHeap(freq):
    for k in freq:
        node = Node(k, freq[k])
        heappush(encoded, node) #heapq.heappush(encoded, node)

def merge():
    while(len(encoded)>1):
        #n1= heapq.heappop(encoded)
        #n2 = heapq.heappop(encoded)

        n1 = heappop(encoded)
        n2 = heappop(encoded)


        new= Node(None,n1.freq+n2.freq)
        new.left=n1
        new.right=n2
        #heapq.heappush(encoded,new)
        heappush(encoded,new)
        
def prefix_gen(root,curCode):
    if(root==None):
        return
    if(root.ch != None):
        prefix[root.ch] = curCode
        return
    prefix_gen(root.left,curCode+"0")
    prefix_gen(root.right,curCode+"1")

##---main----
str = genString()
freq = frequency(str)
#print(freq)
makeHeap(freq)
merge()
#root = heapq.heappop(encoded)
root = heappop(encoded)
curCode=""
prefix_gen(root,curCode)
for K in prefix:
    print(K+":\t"+prefix[K])




"""
The generated string is  MYIDISFOURONEONETHREE
I:      000
M:      0010
F:      0011
D:      0100
U:      0101
T:      0110
H:      0111
R:      100
O:      101
N:      1100
Y:      11010
S:      11011
E:      111

"""