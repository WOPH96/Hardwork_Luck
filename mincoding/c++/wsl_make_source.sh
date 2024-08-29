#!/usr/bin/zsh
if [ -z $1 ] ; then
    echo "insert the paramter as a name of problem"
    exit 0
fi

#crete
prob_number=$1
mkdir -p ${prob_number}
touch ${prob_number}/${prob_number}.cpp
touch ${prob_number}/${prob_number}_input.txt
echo "#include <iostream>
#include <vector>

using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(\"${prob_number}_input.txt\", \"r\", stdin);


    return 0;
}" >> ${prob_number}/${prob_number}.cpp


#open
code $1/$1.cpp
code $1/$1_input.txt
cd $1