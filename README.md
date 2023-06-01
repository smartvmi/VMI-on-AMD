# KVMi for AMD64

This repository contains code to enable hyper-single-stepping on AMD64 processors using KVMi together with LibVMI.
Furthermore, it also contains programs to test against some of the weaknesses of previous approaches and benchmarking code.

## Usage

Apply the provided patch files to [`kvmi-v7`](https://github.com/KVM-VMI/kvm/tree/kvmi-v7) and [`libvmi`](https://github.com/libvmi/libvmi).
Then proceed as usual. APIs are identical to those for Intel processors.
Please note that your application needs to handle certain privileged instructions during single-stepping to achieve correctness and stealthiness (see the provided example).
