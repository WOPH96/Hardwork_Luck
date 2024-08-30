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
echo '#include <stdio.h>
#define MAX_LEN 1000
#define NUMBER_OF_LINE 5
int main()
{
    FILE *fs;
    char str[NUMBER_OF_LINE][MAX_LEN];
    int num = 0;

    fs = fopen("3-1_input.txt", "r");
    if (fs == NULL) {
        printf("파일을 열 수 없습니다.\\n");
        return 1;
    }

    while (fgets(str[num], MAX_LEN, fs) != NULL) {
        printf("%s", str[num]);
        num++;
    }

    fclose(fs);
    return 0;
}' >> ${prob_number}/${prob_number}.c


#open
code ${prob_number}/${prob_number}.c
code ${prob_number}/${prob_number}_input.txt