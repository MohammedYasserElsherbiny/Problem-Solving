#!/bin/bash

# --- Configuration ---
TARGET_DIR="Current Problem"
OUTPUT_NAME="program_exec"
# You can change c++17 to c++20 or c++14 if needed
COMPILER_FLAGS="-std=c++17 -Wall -Wextra" 

# --- 1. Check if the directory exists ---
if [ ! -d "$TARGET_DIR" ]; then
    echo "❌ Error: Directory '$TARGET_DIR' not found."
    exit 1
fi

# --- 2. Enter the directory ---
cd "$TARGET_DIR" || exit

# --- 3. Find the .cpp file ---
# This finds the first .cpp file in the folder. 
# If you have specific naming like main.cpp, replace wildcard with main.cpp
CPP_FILE=$(ls *.cpp 2>/dev/null | head -n 1)

if [ -z "$CPP_FILE" ]; then
    echo "❌ Error: No .cpp file found in '$TARGET_DIR'."
    exit 1
fi

# --- 4. Compile the code ---
echo "⚙️  Compiling: $CPP_FILE..."
g++ $COMPILER_FLAGS "$CPP_FILE" -o "$OUTPUT_NAME"

# --- 5. Run only if compilation succeeded ---
if [ $? -eq 0 ]; then
    echo "✅ Build successful. Output:"
    echo "------------------------------------------------"
    
    # Run the executable
    ./"$OUTPUT_NAME"
    
    echo -e "\n------------------------------------------------"
    
    # Optional: Clean up the executable after running
    # rm "$OUTPUT_NAME" 
else
    echo "🔥 Compilation failed."
    exit 1
fi