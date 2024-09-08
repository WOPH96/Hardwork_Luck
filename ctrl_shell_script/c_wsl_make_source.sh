
if [ -z $1 ] ; then
    echo "insert the paramter as a name of problem"
    exit 0
fi

#crete
# 입력값이 숫자인지 확인
if [[ "$1" =~ ^[0-9]+$ ]]; then
  # 현재 디렉토리 이름 가져오기
  current_dir=$(basename "$PWD")
  # 새로운 변수 생성
  prob_number="${current_dir}-${1}"
else
  # 입력값을 그대로 변수에 저장
  prob_number="$1"
fi


directory_of_source="C"
source_path="${prob_number}/${directory_of_source}"

mkdir -p ${source_path}
touch ${source_path}/${prob_number}.c
touch ${source_path}/${prob_number}_input.txt
echo "#include <stdio.h>

// 필요 변수 선언

// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen(\"${prob_number}_input.txt\", \"r\");
    if (fp == NULL)
    {
        printf(\"파일 열기 실패 \\\n \");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, \"%d \", &num1);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( \"%d \",  &num2);

    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();

    return 0;
}
" >> ${source_path}/${prob_number}.c
# 실수방지를 위한 이어쓰기

#open
code ${source_path}/${prob_number}.c
code ${source_path}/${prob_number}_input.txt
