#### dpdk-httpperf
--------------
Fork from official wrk(https://github.com/wg/wrk), and run on the dpdk user space TCP/IP stack(ANS"Acceleted Network Stack"). 

#### build and install
--------------
*  Download latest dpdk version from [dpdk website](http://dpdk.org/), and build dpdk
```
$ make config T=x86_64-native-linuxapp-gcc
$ make install T=x86_64-native-linuxapp-gcc
$ export RTE_SDK=/home/mytest/dpdk
$ export RTE_TARGET=x86_64-native-linuxapp-gcc
```
*  Download ANS following the [ANS wiki](https://github.com/opendp/dpdk-ans/wiki/Compile-APP-with-ans), build ans and startup ans
```
$ git clone https://github.com/ansyun/dpdk-ans.git
$ export RTE_ANS=/home/mytest/dpdk-ans
$ ./install_deps.sh
$ cd ans
$ make
$ sudo ./build/ans -c 0x2 -n 1  -- -p 0x1 --config="(0,0,1)"
EAL: Detected lcore 0 as core 0 on socket 0
EAL: Detected lcore 1 as core 1 on socket 0
EAL: Support maximum 128 logical core(s) by configuration.
EAL: Detected 2 lcore(s)
EAL: VFIO modules not all loaded, skip VFIO support...
EAL: Setting up physically contiguous memory...
EAL: Ask a virtual area of 0x400000 bytes
EAL: Virtual area found at 0x7fdf90c00000 (size = 0x400000)
EAL: Ask a virtual area of 0x15400000 bytes
```
*  Download dpdk-httpperf, build dpdk-httpperf and startup dpdk-httpperf
```
$ git clone https://github.com/ansyun/dpdk-httpperf.git
$ make

```
$ ./dpdk-httpperf -t12 -c5000 -d30s http://10.0.0.10:80/index.html
start init anssock
EAL: Detected lcore 0 as core 0 on socket 0
EAL: Detected lcore 1 as core 1 on socket 0
EAL: Detected lcore 2 as core 2 on socket 0
EAL: Detected lcore 3 as core 3 on socket 0
EAL: Detected lcore 4 as core 4 on socket 0
EAL: Detected lcore 5 as core 5 on socket 0
EAL: Detected lcore 6 as core 6 on socket 0
EAL: Detected lcore 7 as core 7 on socket 0
EAL: Support maximum 128 logical core(s) by configuration.
EAL: Detected 8 lcore(s)
EAL: Setting up physically contiguous memory...
EAL: WARNING: Address Space Layout Randomization (ASLR) is enabled in the kernel.
EAL:    This may cause issues with mapping memory into secondary processes
EAL: Analysing 4 files
EAL: Mapped segment 0 of size 0x100000000
EAL: TSC frequency is ~1698035 KHz
EAL: Master lcore 0 is ready (tid=988e0900;cpuset=[0])
USER8: LCORE[-1] anssock any lcore id 0xffffffff
USER8: LCORE[0] anssock app id: 14265
USER8: LCORE[0] anssock app name: dpdk-httpperf
USER8: LCORE[0] anssock app lcoreId: 0
USER8: LCORE[0] mp ops number 4, mp ops index: 0
Running 30s test @ http://10.0.0.10:80/index.html
  12 threads and 5000 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    61.63ms  163.62ms   1.96s    96.67%
    Req/Sec   227.53    790.62     3.85k    91.84%
  2794 requests in 0.93m, 2.26MB read
  Socket errors: connect 0, read 4866, write 0, timeout 782
Requests/sec:     50.22
Transfer/sec:     41.69KB

```
