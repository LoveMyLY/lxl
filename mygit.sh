#########################################################################
# File Name: mygit.sh
# Author: LoveZJT
# mail: 151220055@smail.nju.edu.cn
# Created Time: 2017年06月01日 星期四 17时43分08秒
#########################################################################
#!/bin/bash
echo tar:压缩文件
echo git:git
read menu
case "$menu" in 
	"tar" )
		read name
		echo 压缩文件名：
		tar -cf $name .
		;;
	"git" )
		i=0
		echo 0:初始化
		echo 1:不初始化
		read i
		if [ $i -eq 1 ]
		then
			git init
		fi
		git add .
		git commit -m $1
		git remote add origin $2
		#git pull origin master
		#git push -u origin $3
		;;
esac
