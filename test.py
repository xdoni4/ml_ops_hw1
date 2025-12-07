import time
import numpy as np
from cholesky_cpp import cholesky

def test(k: int):
    A = np.random.random((k, k)) + 1
    A = A.astype(np.float64)
    A = A @ A.T
    start = time.time()
    L_np = np.linalg.cholesky(A)
    end_np = time.time()
    L_cpp = cholesky(A)
    end_cpp = time.time()
    assert np.allclose(L_np, L_cpp, atol=1e-3, rtol=1e-8)
    return end_np - start, end_cpp - end_np

for k in [3, 10, 100, 1_000, 2_000]:
    time_np, time_cpp = test(k)
    print(f"Numpy time: {time_np:3f} s, our binding time: {time_cpp:3f} s, test passed.")
