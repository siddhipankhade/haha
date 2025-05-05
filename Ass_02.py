class SetADT:
    def __init__(self):
        self.data = []
    
    def contains(self, value):
        return value in self.data
    
    def insert(self, value):
        if not self.contains(value):
            self.data.append(value)
            return True
        return False
    
    def remove(self, value):
        if self.contains(value):
            self.data.remove(value)
            return True
        return False
    
    def get_size(self):
        return len(self.data)
    
    def union(self, set2):
        set3 = SetADT()
        for i in self.data:
            set3.insert(i)
        for i in set2.data:
            set3.insert(i)
        return set3
    
    def intersection(self, set2):
        set3 = SetADT()
        for i in self.data:
            if set2.contains(i):
                set3.insert(i)
        return set3
    
    def difference(self, set2):
        set3 = SetADT()
        for i in self.data:
            if not set2.contains(i):
                set3.insert(i)
        return set3
    
    def subset(self, set2):
        return all(self.contains(i) for i in set2.data)
    
    def display(self):
        print("{" + ", ".join(map(str, self.data)) + "}")

s1 = SetADT()
s2 = SetADT()

while True:
    print("1. Insert.")
    print("2. Remove.")
    print("3. Contains.")
    print("4. Size")
    print("5. Display.")
    print("6. Intersection.")
    print("7. Union.")
    print("8. Difference.")
    print("9. Subset.")
    print("0. Exit.")
    
    ch = int(input("Enter Your Choice: "))
    
    if ch == 1:
        if s1.insert(int(input("Enter Value: "))):
            print("Value Inserted")
        else:
            print("Already Present")
        if s2.insert(int(input("Enter Value: "))):
            print("Value Inserted")
        else:
            print("Already Present")
    elif ch == 2:
        if s1.remove(int(input("Enter Value: "))):
            print("Value Removed")
        else:
            print("Not Found")
    elif ch == 3:
        if s1.contains(int(input("Enter Value: "))):
            print("Value Already Present.")
        else:
            print("Value Not Present.")
    elif ch == 4:
        print("Size of Set =", s1.get_size())
    elif ch == 5:
        s1.display()
    elif ch == 6:
        '''s2 = SetADT()
        for val in [1, 11, 2, 21]:
            s2.insert(val)'''
        s3 = s1.intersection(s2)
        s3.display()
    elif ch == 7:
        '''s2 = SetADT()
        for val in [1, 11, 2, 21]:
            s2.insert(val)'''
        s3 = s1.union(s2)
        s3.display()
    elif ch == 8:
        '''s2 = SetADT()
        for val in [1, 11, 2, 21]:
            s2.insert(val)'''
        s3 = s1.difference(s2)
        s3.display()
    elif ch == 9:
        '''s2 = SetADT()
        for val in [1, 2]:
            s2.insert(val)'''
        if s1.subset(s2):
            print("s1 is a subset of s2")
        else:
            print("s1 is not a subset of s2")
    elif ch == 0:
        break