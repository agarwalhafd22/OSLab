# Prompt the user to enter a file or directory name
echo "Enter the file or directory name:"
read filename

# Check if the input is a directory
if [ -d "$filename" ]; then
    echo "$filename is a directory."
# Check if the input is a regular file
elif [ -f "$filename" ]; then
    echo "$filename is a regular file."
# If it's neither a directory nor a regular file
else
    echo "$filename is neither a directory nor a regular file or it does not exist."
fi


