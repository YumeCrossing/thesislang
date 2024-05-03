SOURCES="src/main.cpp src/REPL.cpp"
# Only for Windows at now
EXECUTABLE="thesis.exe"
PROFILE="debug"

if ! [ -e "target" ]; then
    mkdir target
fi

if [ -e "target/$PROFILE" ]; then
    rm --dir "target/$PROFILE"
fi

mkdir "target/$PROFILE"

# Build by GCC
g++ $SOURCES -I inc/ -o "target/debug/$EXECUTABLE"
