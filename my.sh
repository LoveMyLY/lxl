#########################################################################
# File Name: mygit.sh
# Author: LoveZJT
# mail: 151220055@smail.nju.edu.cn
# Created Time: 2017年06月01日 星期四 17时43分08秒
#########################################################################
#!/bin/bash
echo tar  git
read menu
case "$menu" in 
	"tar" )
		echo "filename:\c"
		read name
		tar -cf $name .
		;;
	"git" )
		git add .
		git commit --allow-empty
		echo -e "the address of repositories:\c"
		read address
		git remote add origin $address
		echo -e "if upload<y or n>\c"
		read upload
		if upload=y
		then
			git pull origin master
			read -p "branch:\c" branch
			git push -u origin $branch
		fi
		;;
esac
