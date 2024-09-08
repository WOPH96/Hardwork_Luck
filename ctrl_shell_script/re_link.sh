
find . -mindepth 2 -name "*.sh" -delete
# find . -mindepth 2 -name "*.sh" -print
sleep 3
# 현재 디렉토리의 모든 하위 디렉토리 이름을 배열에 저장
subdirs=($(find . -maxdepth 1 -type d -not -path .))

# 배열의 모든 요소를 순회하며 wsl_make_problem_dir.sh 스크립트 호출
for subdir in "${subdirs[@]}"; do
    ./wsl_make_problem_dir.sh "$subdir"
    echo "$(pwd)/${subdir} 완료"
done

find .vscode -maxdepth 1 -name "c*.sh" -delete
# find . -maxdepth 1 -name "c*.sh" -delete