
if [ -z $1 ] ; then
    echo "큰 문제 번호를 입력해주세요. (ex, 18-1은 18)"
    exit 0
fi

prob_dir=$1
mkdir -p ${prob_dir}

top_dir=$(git rev-parse --show-toplevel)
script_dir=${top_dir}/ctrl_shell_script

ln -s "${script_dir}/c_wsl_make_source.sh" "${prob_dir}/c_wsl_make_source.sh"
ln -s "${script_dir}/cpp_wsl_make_source.sh" "${prob_dir}/cpp_wsl_make_source.sh"