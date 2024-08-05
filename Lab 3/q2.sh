echo "Enter pattern"
read pattern
echo "Enter directory path"
read path
if [ -e "$path" ];then
	if [ -d "$path" ]; then
        echo "Searching for items matching '$pattern' in $path..."

        # Iterate over each file and directory in the specified path
        shopt -s nullglob # Avoid issues with no matches
        for item in "$path"/$pattern; do
            # Check if the item exists
            if [ -e "$item" ]; then
                # Get the base name of the item
                item_name=$(basename "$item")
                
                # Output the matching item
                echo "Match found: $item"
            fi
        done

        # Reset shell options
        shopt -u nullglob

    else
        echo "$path is not a directory."
    fi
else
    echo "$path does not exist."
fi

