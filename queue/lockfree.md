lockfree无锁队列笔记
====  
1.引子
----
* 谈到并发程序设计，有几个概念是避免不了的。
  * 锁：锁是用来做并发最简单的方式，当然其代价也是最高的。详[LOCK](../base/LOCK.md)
  * CAS: 使用CAS时不像上锁那样需要一次上下文切换，但是也需要处理器锁住它的指令流水线来保证原子性，并且还要加上Memory Barrier来保证其结果可见。详[CAS](../base/CAS.md)
  * Memory Barrier: 大家都知道现代CPU是乱序执行的，也就是程序顺序与实际的执行顺序很可能是不一致的。在单线程执行时这不是个问题，但是在多线程环境下这种乱序就可能会对执行结果产生很大的影响了。memory barrier提供了一种控制程序执行顺序的手段, 关于其更多介绍，可以参考[Memory Barrier](http://en.wikipedia.org/wiki/Memory_barrier)
  * Cache Line：cache line解释起来其实很简单，就是CPU在做缓存的时候有个最小缓存单元，在同一个单元内的数据被同时被加载到缓存中，充分利用 cache line可以大大降低数据读写的延迟，错误利用cache line也会导致缓存不同替换，反复失效。 
  
  
  
  
参考博客  
[blob1](http://www.ibm.com/developerworks/cn/aix/library/au-multithreaded_structures2/index.html#list1)  
[blob2](http://www.360doc.com/content/16/1229/11/39496432_618623131.shtml)
