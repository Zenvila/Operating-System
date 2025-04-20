#!/bin/bash

# Hardcoded filenames
source_file="sourcefile.c"
new_file="newfile.c"


# Step 2: Copy to new file
cp "$source_file.c" "$new_file.c"
echo "Copied contents to $new_file"

# Step 3: Show menu using if-else
echo ""
echo "Choose an option (IF block):"
echo "1. Compile"
echo "2. Run"
echo "3. Display contents"
read -p "Enter choice: " choice

if [ "$choice" -eq 1 ]; then
    gcc "$new_file" -o output
    echo "Compiled to 'output'"
elif [ "$choice" -eq 2 ]; then
    ./output
elif [ "$choice" -eq 3 ]; then
    cat "$new_file"
else
    echo "Invalid choice."
fi

# Step 4: Show same menu using case
echo ""
echo "Choose an option (SWITCH block):"
echo "1. Compile"
echo "2. Run"
echo "3. Display contents"
read -p "Enter choice: " option

case "$option" in
    1) gcc "$new_file" -o output
       echo "Compiled (via case).";;
    2) ./output;;
    3) cat "$new_file";;
    *) echo "Invalid choice (via case).";;
esac

