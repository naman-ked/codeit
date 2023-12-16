# What is Thread?
# Separate flow of execution is called thread.


# What is the difference between process and thread?
# Process is a program in execution whereas thread is a separate path of execution in a program. 
# Process is heavy weight and thread is light weight.
# Process takes more time for creation and termination whereas thread takes less time for creation and termination.

import threading
import time
def thread_func(num):
    print("Cube: {}".format(num*num*num))
    time.sleep(5)
    print("Square: {}".format(num*num))

t1=threading.Thread(target=thread_func,args=(10,))    
t2=threading.Thread(target=thread_func,args=(100,))

t1.start()
t1.join()  #wait for thread 1 to get finsihed
t2.start()

print("Main thread finished!")


def thread_func2(num):
    lock.acquire()
    print("Cube: {}".format(num*num*num))
    time.sleep(5)
    print("Square: {}".format(num*num))
    lock.release()

t3=threading.Thread(target=thread_func2,args=(10,))    
t4=threading.Thread(target=thread_func2,args=(100,))


lock=threading.Lock()
t3.start()
t4.start()

print("Main thread 2 finished!")