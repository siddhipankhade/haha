size=10
tele_book=[None]*size
def input_data():
      Id=int(input("Enter the client id : "))
      name=input("Enter the client name : ")
      tele=int(input("Enter the client telephone no. : "))
      client_record=[Id,name,tele]
      
      for i in range(size):
            hash_key=(Id+(i*i))%size
            if(tele_book[hash_key]==None):
                tele_book[hash_key]=client_record
                print("Client record added successfully!!!!")
                return
      else:
              print("no")
                
def display():
	print("Client  |   Name  |  Telephone number")
	for i in range(size):
          if tele_book[i] is not None:
		          print(tele_book[i])
   
def search_data():
  data=int(input("Enter the Cliet ID to be searched"))
  count=0
  #hash_key=data%size
  for i in range (size):
   temp=(data+(i*i))%size
   if(tele_book[temp]!=None and tele_book[temp][0]==data):
      print("Data found")
      print("ID    name      telephone")
      print(tele_book[temp])
      print("Comparisons needed : %d"%(i+1))
      count=count+1
      return
  if count==0:
      print("No client with ID : %d found"%(data))
   
def Main():
  while True:
    print("Main Menu: ")
    print("\n\t1.Add data")
    print("\n\t2.Display data")
    print("\n\t3.Search data")
    print("\n\t4.Exit")
    ch=int(input("ENTER YOUR CHOICE : "))
    if(ch==1):
      input_data()
    elif(ch==2):
      display()
    elif(ch==3):
       search_data()
    elif(ch==4):
        print("Program Execution Stopped!!")
        exit()
    else:
       print("Wrong choice:")
Main()
quit()
'''
size=10
tele_book=[None]*size
def input_data():
      Id=int(input("Enter the client id : "))
      name=input("Enter the client name : ")
      tele=int(input("Enter the client telephone no. : "))
      client_record=[Id,name,tele]
      
      for i in range(size):
            hash_key=(Id+i)%size
            if(tele_book[hash_key]==None):
                tele_book[hash_key]=client_record
                print("Client record added successfully!!!!")
                return
      else:
              print("no")
                
     
def display():
	print("Client  |   Name  |  Telephone number")
	for i in range(size):
          if tele_book[i] is not None:
		          print(tele_book[i])
   
def search_data():
  data=int(input("Enter the data to be searched"))
  count=0
  #hash_key=data%size
  for i in range (size):
   temp=(data+i)%size
   if(tele_book[temp]!=None and tele_book[temp][0]==data):
      print("Data found")
      print("ID    name      telephone")
      print(tele_book[temp])
      print("Comparisons needed : %d"%(i+1))
      count=count+1
      return
  if count==0:
      print("No client with ID : %d found"%(data))
   
def Main():
  while True:
    print("Main Menu: ")
    print("\n\t1.Add data")
    print("\n\t2.Display data")
    print("\n\t3.search data")
    ch=int(input("ENTER YOUR CHOICE : "))
    if(ch==1):
      input_data()
    elif(ch==2):
      display()
    elif(ch==3):
       search_data()
    else:
       print("Wrong choice:")
Main()
quit()
'''