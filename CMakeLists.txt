name: Build and Test PyFlow

on:
  push:
    branches: [main]
  pull_request:

jobs:
  build-test:
    runs-on: ${{ matrix.os }}
    strategy:
      fail-fast: false
      matrix:
        os: [ubuntu-latest, windows-latest, macos-latest]
        python-version: ["3.7", "3.8", "3.9", "3.10"]
        exclude:
          - os: macos-latest
            python-version: "3.7"
    steps:
      - uses: actions/checkout@v3

      - name: Set up Python ${{ matrix.python-version }}
        uses: actions/setup-python@v4
        with:
          python-version: ${{ matrix.python-version }}

      - name: Install build tools on Ubuntu
        if: runner.os == 'Linux'
        run: sudo apt-get install build-essential

      - name: Install build tools on Windows
        if: runner.os == 'Windows'
        run: |
          choco install visualstudio2019buildtools
          choco install cmake

      - name: Install build tools on macOS
        if: runner.os == 'macOS'
        run: |
          xcode-select --install || true

      - name: Install dependencies
        run: |
          python -m pip install --upgrade pip setuptools wheel
          pip install pybind11 pytest

      - name: Build wheel
        run: python setup.py bdist_wheel

      - name: List wheel files
        run: ls dist/

      - name: Install package
        run: pip install dist/*.whl

      - name: Run tests
        run: |
          cd tests/python
          pytest

