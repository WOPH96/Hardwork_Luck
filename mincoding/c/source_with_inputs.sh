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

// 필요 변수 선언

void input_f()
{
    FILE *fp = fopen(\"${prob_number}_input.txt\", \"r\");
    if (fp == NULL)
    {
        printf(\"파일 열기 실패 \\\n \");
        return 1;
    }

    // 변수 입력 공간

    // fscanf(fp, \"%d %d\", &num1, &num2);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( \"%d %d\", &num1, &num2);

    // 변수 입력 공간
}

int main()
{

    input();

    return 0;
}
" >> ${prob_number}/${prob_number}.c


#open
code ${prob_number}/${prob_number}.c
code ${prob_number}/${prob_number}_input.txt