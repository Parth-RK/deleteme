package main

import (
    "os"
    "runtime"
    "time"
)

func main() {
    _, src, _, _ := runtime.Caller(0)
    exe, _ := os.Executable()

    time.Sleep(time.Second)

    os.Remove(src)
    os.Remove(exe)
}