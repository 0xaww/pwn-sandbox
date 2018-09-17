# pwn-sandbox

[English](README.md)

pwn-sandbox 是一个AWD线下赛的pwn题沙盒工具，可以防止gamebox被攻破。

## 功能
1. 保护敏感系统调用，如 fork, execve, clone 等.
2. 记录攻击流量.

## 用法
在原始可执行文件名后添加 `-orig` 后缀，并将 `pwn-sandbox` 重命名为原始可执行文件名.

流量和系统调用会记录到 `/tmp/.binaryname/` 路径。 `timestamp-std` 是标准输入输出流量， `timestamp-n` 是其他文件描述符的流量， `timestamp-syscall` 是系统调用记录。

## 流量解析/分析工具
运行 `python analyser --help` 并阅读代码了解详情.

## 原理
阅读 `ptrace(3)` 了解详情.

## 从源码构建.
```
autoreconf --install
./configure
make
make install # Optional, this binary will not install to system dir.
```

推荐使用静态编译来避免不同环境的libc差异，用 `./configure LDFLAGS=-static` 启用。

## 许可证
[GPLv2 License](License) 欢迎 star, fork, feedback(via issue).

