# pwn-sandbox

[中文版](README-zh.md)

pwn-sandbox is a sandbox tool for pwner to protect your own gamebox on AWD CTF Challenges.

## Capabilities
1. Protect sensitive syscall like fork, execve, clone etc.
2. Record traffic from other teams.

## Usage
Add `-orig` postfix to original binary name and change `pwn-sandbox` to original binary name. 
Traffic and syscall will log into `/tmp/.binaryname/` directory. `timestamp-std` is stdin/stdout log, `timestamp-n` is other fds' log, `timestamp-syscall` is syscall log.

## Traffic parser/analyser
Run `python analyser --help` and read the source code to see details.

## How this thing work?
See `ptrace(3)` for more details.

## Build from source.
```
autoreconf --install
./configure
make
make install # Optional, this binary will not install to system dir.
```

It is better to build with static link to prevent libc differences between gamebox and your own rootfs. Use `./configure LDFLAGS=-static` to enable it.

## License
[GPLv2 License](License) Star, fork, feedback(via issue) is welcomed.

