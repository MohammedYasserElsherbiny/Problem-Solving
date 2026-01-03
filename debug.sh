#!/bin/bash

# --- Configuration ---
TARGET_DIR="Current Problem"
OUTPUT_NAME="program_debug"
# -g is CRITICAL. It adds debug symbols. 
# -O0 ensures the compiler doesn't optimize away variables you want to see.
COMPILER_FLAGS="-g -O0 -std=c++17 -Wall" 

# --- 1. Check if directory exists ---
if [ ! -d "$TARGET_DIR" ]; then
    echo "❌ Error: Directory '$TARGET_DIR' not found."
    exit 1
fi

# --- 2. Enter directory ---
cd "$TARGET_DIR" || exit

# --- 3. Find the .cpp file ---
CPP_FILE=$(ls *.cpp 2>/dev/null | head -n 1)

if [ -z "$CPP_FILE" ]; then
    echo "❌ Error: No .cpp file found in '$TARGET_DIR'."
    exit 1
fi

# --- 4. Compile with Debug Flags ---
echo "🐞 Compiling with debug symbols..."
g++ $COMPILER_FLAGS "$CPP_FILE" -o "$OUTPUT_NAME"

if [ $? -ne 0 ]; then
    echo "🔥 Compilation failed. Fix errors before debugging."
    exit 1
fi

# --- 5. Launch GDB ---
echo "✅ Compilation successful. Launching GDB..."
echo "------------------------------------------------"
echo "💡 GDB TIP: Type 'run' to start, 'break main' to stop at start."
echo "------------------------------------------------"

# This launches the debugger loaded with your program
gdb -q "./$OUTPUT_NAME"