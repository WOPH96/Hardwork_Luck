#!/usr/bin/env zsh
if [ -z "$1" ]; then
    echo "문제 이름을 파라미터로 입력해주세요."
    exit 1
fi

# $1이 존재하는 디렉토리인지 확인하고, 존재하지 않으면 생성
if [ ! -d "$1" ]; then
    mkdir -p "$1" || {
        echo "디렉토리 생성 실패: $1"
        exit 1
    }
else
    # $1이 디렉토리이고, 기존 링크 파일이 존재하면 삭제
    for file in wsl_make_problem_dir.sh re_link.sh; do
        if [ -f "$1/$file" ]; then
            rm "$1/$file" || {
                echo "기존 파일 삭제 실패: $1/$file"
                exit 1
            }
        fi
    done
fi

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