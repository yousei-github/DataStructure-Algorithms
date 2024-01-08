# Shell script for searching text in files

# Shell variable:

# To declare static array for storing the text to search
findTextArray=(
"temp"
"temp2"
)

fileType1="*.c*" # Source file type
fileType2="*.h" # Header file type

# To print all elements of an array
echo ${findTextArray[@]}
# To print particular element
echo ${findTextArray[1]}
# Size of an array
echo ${#findTextArray[@]}

# Directory array
directoryArray=(
# "."
"./Cplusplus/source/"
"./Cplusplus/source/LinkedList/"
"./Cplusplus/include/"
"./Cplusplus/include/LinkedList/"
)

# Iterate the loop until the counter is less than a number
counter=0
while [ $counter -lt ${#directoryArray[@]} ] # -lt is less than operator
do
    # Print the values
    # echo "$counter"

    # if..elif..else..fi statement
    if [ $counter == `expr 0` ]
    then
        echo "[0]"
    elif [ $counter == `expr 1` ]
    then
        echo "[1]"
    elif [ $counter -lt `expr 0` ]
    then
        echo "[Error]"
        break
    else
        echo "[$counter]"
    fi
    
    # Get length of an array
    arraylength=${#findTextArray[@]}
    # use for loop to read all values and indexes
    for (( i=0; i<${arraylength}; i++ ));
    do
        # echo "index: $i, the given element is: ${findTextArray[$i]}"
        command="find ${directoryArray[$counter]} -type f -name $fileType1 -o -name $fileType2 | xargs grep -l ${findTextArray[$i]}"
        # echo "Execute command: $command"
        # echo "[Output]:"
        # Execute the command
        eval "$command"
        # echo "[Finish]"
    done

    # Increment the value
    counter=`expr $counter + 1`
done

echo "[Finish All]"
