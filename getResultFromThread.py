from multiprocessing.pool import ThreadPool
import time

def foo(bar):
  for i in range(3):
    print bar + str(i)
    if bar == 'a':
      time.sleep(0.5)
    elif bar == 'b':
      time.sleep(0.8)
    else:
      time.sleep(1.2)
  return bar


tests = ['a','b','c']
pool = []
result = []
for i in range(3):
  pool.append(ThreadPool(processes=i+1))
  result.append(pool[-1].apply_async(foo, (tests[i])))
for i in range(3):
  returnValue = result[i].get()
  print returnValue