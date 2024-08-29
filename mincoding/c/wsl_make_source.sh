#!/usr/bin/zsh
if [ -z $1 ] ; then
    echo "insert the paramter as a name of problem"
    exit 0
fi

#crete
prob_number=$1
mkdir -p ${prob_number}
touch ${prob_number}/${prob_number}.c
touch ${prob_number}/${prob_number}_input.txt
echo "#include <stdio.h>
int main()
{
    


    return 0;
}" >> ${prob_number}/${prob_number}.cpp


#open
code ${prob_number}/${prob_number}.cpp
#code ${prob_number}/${prob_number}_input.txt