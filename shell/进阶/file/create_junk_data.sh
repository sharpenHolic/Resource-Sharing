#!/usr/bin/bash

# dd会克隆给定的输入内容，然后将一摸一样的副本文件写入到输出
# if 输入文件 /dev/zero为一个字符设备，不断返回零值字符
# of 输出文件
# bs 大小
# count 块个数
# 总大小为 bs * count
dd if=/dev/zero of=junk.data bs=1M count=2：

# 记录了2+0 的读入
# 记录了2+0 的写出
# 2097152字节（2.1 MB，2.0 MiB）已复制，0.00371042 s，565 MB/s
