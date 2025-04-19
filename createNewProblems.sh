# get arguments count

if [ $# -ne 2 ]; then
  echo "Usage: $0 <problemID> <problemURL>"
  exit 1
fi

ID=$1
URL=$2
NAME=$(echo "$URL" | sed 's$https://leetcode.com/problems/\([^/]*\)/.*$\1$')
echo "Problem Name: $NAME"

mkdir "$ID.$NAME"
touch "$ID.$NAME/main.cpp"
echo "#include \"../includes.hpp\"" >> "$ID.$NAME/main.cpp"

