#!/usr/bin/env zsh
# find . -mindepth 2 -name "*.sh" -delete
# find . -mindepth 2 -name "*.sh" -print
# sleep 3
# 현재 디렉토리의 모든 하위 디렉토리 이름을 배열에 저장
# subdirs=$(find . -maxdepth 1 -type d -not -path '.' -not -path './.vscode')
while IFS= read -r subdir; do
    ./make_problem_dir.sh ${subdir}
    echo "$(pwd)/${subdir} 완료"
    # 각 디렉토리에 대한 처리
done < <(find . -maxdepth 1 -type d -not -path '.' -not -path './.vscode')


# find .vscode -maxdepth 1 -name "c*.sh" -delete
# find . -maxdepth 1 -name "c*.sh" -delete