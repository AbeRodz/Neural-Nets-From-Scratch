import time
import numpy as np

N = 512

if __name__ == "__main__":

    A = np.random.randn(N,N).astype(np.float32)
    B = np.random.randn(N,N).astype(np.float32)

    flop = N*N*N*2
    print(f"{flop/1e9:.2f} GFLOP")

    for i in range(100):
        st = time.monotonic()
        C = A @ B
        et = time.monotonic()
        s = et - st
        print(f"{flop/s*1e-12:.2f}TFLOPS/S")