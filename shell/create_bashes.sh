#!/bin/bash
# 创建一个脚本，输入名字即可

echo "脚本名字：$*"
for i in "$@"; do 
  touch $i.sh
  chmod +x $i.sh
  echo "#!/bin/bash" >> $i.sh
  echo "# "$i.sh >> $i.sh
done 
