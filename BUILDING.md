# Building instructions for Linux Fedora 25

Note: this was tested in a docker container

1. Install build dependencies

```bash
sudo dnf install -y gcc gcc-c++
```

Some libraries in Fedora 25 are too old, so we must fetch them from Fedora rawhide:

```bash
sudo dnf install -y fedora-repos-rawhide
sudo dnf install -y --enablerepo rawhide boost boost-devel cmake
```

2. Create a build directory

Do this inside of the repo root

```bash
mkdir builddir
cd builddir
```

3. Create the `Makefile` using `cmake`

```bash
cmake ..
```

4. Start the building using `make`

```bash
make
```

5. Run the built executable

```bash
./pygen
```
