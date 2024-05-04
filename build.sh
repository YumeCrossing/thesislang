SOURCES="src/main.cpp src/CLI.cpp"
# Only for Windows at now
EXECUTABLE="thesis.exe"
PROFILE="debug"

if ! [ -e "target" ]; then
    mkdir target
fi

if [ -e "target/$PROFILE" ]; then
    rm -rf --dir "target/$PROFILE"
fi

mkdir "target/$PROFILE"

# Build by GCC
g++ $SOURCES -I inc/ -I 3rdparty/fmt/include/ -o "target/$PROFILE/$EXECUTABLE"
