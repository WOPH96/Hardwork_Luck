# # 스크립트 실행 디렉토리 기억
# pushd .

# # 하위 디렉토리에서 re_link.sh 파일 찾기
# find . -name re_link.sh -print0 | while IFS= read -r -d '' file; do
#   # 파일이 있는 디렉토리로 이동
#   dirname "$file" | xargs -0 cd

#   # re_link.sh 실행
#   if [ -x ./re_link.sh ]; then
#     ./re_link.sh
#   else
#     echo "re_link.sh not found or not executable in $(pwd)"
#   fi

#   # 이전 디렉토리로 돌아가기
#   cd -
# done

# # 처음 디렉토리로 복귀
# popd


pushd .

cd ./baekjoon
./re_link.sh

popd

pushd .
cd ./mincoding/problem
./re_link.sh
popd

pushd .
cd ./programmers
./re_link.sh
popd