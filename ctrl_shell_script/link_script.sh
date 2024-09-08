
if [ -z $1 ] ; then
    echo "insert the paramter as a name of problem"
    exit 0
fi

top_dir=$(git rev-parse --show-toplevel)
script_dir=${top_dir}/ctrl_shell_script

ln -s "${script_dir}/wsl_make_problem_dir.sh" "$1/wsl_make_problem_dir.sh"
ln -s "${script_dir}/re_link.sh" "$1/re_link.sh"