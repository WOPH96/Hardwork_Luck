#!/usr/bin/env zsh

# target_dir="$1"
# if [ -z "${target_dir}" ]; then
#     echo "상위 디렉토리 이름을 입력해주세요"
#     exit 1
# fi

# # $1이 존재하는 디렉토리인지 확인하고, 존재하지 않으면 생성
# mkdir -p "${target_dir}" || {
#     echo "디렉토리 생성 실패: $1"
#     exit 1
# }


top_dir=$(git rev-parse --show-toplevel)
script_dir=${top_dir}/ctrl_shell_script

target_dirs=(baekjoon programmers mincoding/problem softeer bloodstrawberry)
# target_dirs=(${TARGET_DIRS//,/ })
# echo ${#target_dirs[@]}
for dir in ${target_dirs[@]}; do
    target_dir="${top_dir}/${dir}"
    
    ln -sf "${script_dir}/make_problem_dir.sh" "${target_dir}/make_problem_dir.sh" || {
        echo "링크 생성 실패: make_problem_dir.sh"
        exit 1
    }
    ln -sf "${script_dir}/re_link.sh" "${target_dir}/re_link.sh" || {
        echo "링크 생성 실패: re_link.sh"
        exit 1
    }

    echo "링크 생성 완료"
    
    # re_link.sh 실행
    pushd .
    cd ${target_dir}
    ./re_link.sh

    popd
    # echo "$target_dir"
done

# 링크 생성
