#!/usr/bin/env zsh
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

directory_of_source="C++"
source_path="${prob_number}/${directory_of_source}"

mkdir -p ${source_path}
touch ${source_path}/${prob_number}.cpp
touch ${source_path}/${prob_number}_input.txt
touch ${source_path}/${prob_number}_idea.txt
echo "// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성

// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(){
}

void input() {

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen(\"${prob_number}_input.txt\", \"r\", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}


void print() {

} " >> ${source_path}/${prob_number}.cpp
# 실수방지를 위한 이어쓰기

#open
code ${source_path}/${prob_number}.cpp
code ${source_path}/${prob_number}_idea.txt
code ${source_path}/${prob_number}_input.txt
