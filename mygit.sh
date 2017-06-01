#########################################################################
# File Name: mygit.sh
# Author: LoveZJT
# mail: 151220055@smail.nju.edu.cn
# Created Time: 2017年06月01日 星期四 17时43分08秒
#########################################################################
#!/bin/bash
i=0
git add .
git commit -m $1
git remote add origin $2
#git pull origin master
#git push -u origin $3
read i
echo $i
if [ $i -eq 1]
then
	git init
	echo $i
fi
