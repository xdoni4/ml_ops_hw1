FROM python:3.10-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR ./app
COPY . .

RUN pip install --no-cache-dir "scikit-build-core>=0.8" pybind11 cmake build numpy
RUN python -m build
RUN pip install dist/cholesky_cpp-0.1.0-cp310-abi3-linux_x86_64.whl

CMD ["python", "-m", "test"]