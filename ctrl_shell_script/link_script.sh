#!/usr/bin/env zsh
if [ -z "$1" ]; then
    echo "상위 디렉토리 이름을 입력해주세요"
    exit 1
fi

# $1이 존재하는 디렉토리인지 확인하고, 존재하지 않으면 생성

mkdir -p "$1" || {
    echo "디렉토리 생성 실패: $1"
    exit 1
}


top_dir=$(git rev-parse --show-toplevel)
script_dir=${top_dir}/ctrl_shell_script

# 링크 생성
ln -sf "${script_dir}/wsl_make_problem_dir.sh" "$1/wsl_make_problem_dir.sh" || {
    echo "링크 생성 실패: wsl_make_problem_dir.sh"
    exit 1
}
ln -sf "${script_dir}/re_link.sh" "$1/re_link.sh" || {
    echo "링크 생성 실패: re_link.sh"
    exit 1
}

echo "링크 생성 완료"