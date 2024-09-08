# 하위 디렉토리에서 re_link.sh 파일 찾기
find . -name "re_link.sh" -print0 | while IFS= read -r -d '' file; do
  # 파일이 있는 디렉토리로 이동
  dirname "$file" | xargs -0 cd
  
  # re_link.sh 실행
  ./re_link.sh

  # 이전 디렉토리로 돌아가기
  cd -
done