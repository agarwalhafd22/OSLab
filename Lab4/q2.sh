echo "Enter file names (path) to delete and 0 to exit"
while true; do
    read a
    if [ "$a" = "0" ]; then
        break
    fi
    if [ -e "$a" ]; then
        rm "$a"
        echo "Deleted '$a'"
    else
        echo "The file '$a' doesn't exist"
    fi
done

