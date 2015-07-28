__author__ = 'xyin'
from multiprocessing import Pool
import time

def foo(bar):
  for i in range(3):
    print bar + str(i)
    if bar == 'a':
      time.sleep(0.5)
    elif bar == 'b':
      time.sleep(0.8)
    else:
      time.sleep(0.2)
  return bar


tests = ['a','b','c']
pool = Pool(processes=3)
result = []
for i in range(3):
    result.append(pool.apply_async(foo,(tests[i])))
# results = pool.map(foo, tests)
# #pool.join()
# for result in results:
#   print result
# pool.close()
# pool.join()
print 'hei'
for i in range(3):
  returnValue = result[i].get()
  print 'process ' + tests[i] + ' finished, return value: ' + returnValue
print 'done'
