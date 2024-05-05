SOURCES="src/main.cpp src/CLI.cpp"

# Only being tested on Windows.
UNAME=`uname -s`
KERNEL=${UNAME: 0: 5}

if [ "$KERNEL" == "Linux" ]; then
    EXECUTABLE="thesis"
elif [ "$KERNEL" == "Darwin" ]; then
    EXECUTABLE="thesis"
elif [ "$KERNEL" == "MINGW" ]; then
    EXECUTABLE="thesis.exe"
else
    echo "Unsupported target: ${$uname -s}"
    exit -1
fi

# Passed in command-line parameters.
TARGET_NAME="\"thesis\""

# Reserved for future `--profile` extension.
PROFILE="debug"

if ! [ -e "target" ]; then
    mkdir target
fi

if [ -e "target/$PROFILE" ]; then
    rm -rf --dir "target/$PROFILE"
fi

mkdir "target/$PROFILE"

# Build by GCC
g++ $SOURCES -I inc/ -I 3rdparty/fmt/include/ -DTARGET_NAME=${TARGET_NAME} -o "target/$PROFILE/$EXECUTABLE"
