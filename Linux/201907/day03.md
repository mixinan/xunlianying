# Linux基础 - Day03

命令提示符的含义
```
[student@room9pc01 ~]$

student     当前用户名
@           在...(at)
room9pc01   当前主机名
~           当前所在的文件夹
$           当前是普通用户权限
#           当前是管理员权限
```

查看 ip 地址
```
ifconfig  
ifconfig | head -2
```

历史记录
```
history

效果：
59  pwd
60  cd

!59
执行第59条命令

在家目录里，有个隐藏文件 .bash_history
记录执行过的命令
```

重置并启动虚拟机
```
rht-vmctl  reset  classroom
等待至少5秒钟
rht-vmctl  reset  server

双击server
点击not listed?
username: root
password: redhat
```

远程连接服务器
```
ssh   用户@ip地址
ssh   root@172.25.0.11

-X 选项，支持远程打开图形界面
ssh  -X  root@172.25.0.11
```

看两台电脑能否通信
```
ping  ip地址
ping  172.25.0.11

Linux系统默认一直发送数据
使用 ctrl + c 人为结束发送

ping  -c  6  -i  0.3  ip地址
(count 数量)
(interval 间隔时间，单位是秒，不能小于0.2)
```

# 用户

两种身份
```
管理员   root
普通用户 student
```

创建用户
```
useradd  用户名
useradd  guoxn

指定用户的 id 号：
user  -u  9527  huaan
创建一个用户叫 huaan，id 是 9527

在"户口本"里查看用户信息
cat  /etc/passwd
```

删除用户
```
userdel  用户名
（delete 删除）
不加任何选项，只删除 passwd 文件里的信息，家目录还在
删除家目录： rm  -rf  /home/用户名 

userdel   -r  用户名
把用户相关的内容，全部删除（包括家目录）
```

给用户设置密码
```
root 给"普通用户"指定密码
passwd guoxn
输入两次新密码
不需要知道旧密码

普通用户给自己设置密码
passwd
先输入旧密码：
输入新密码2次（需要很复杂）：
```

练习
```
创建用户 kobe  michael  wade
分别给他们设置密码如下：
kobe     brant
michael  jordan
wade     jordan

另一种设置密码的办法：
echo  密码 | passwd  --stdin  用户名  
（standard 标准的 input 输入）
```

切换用户
```
su
(switch 切换 user)

root ===>  普通用户
su - 用户名
不需要密码，直接就能切换

普通用户 ===>  root
su
需要输入 root 密码
```

交互式与非交互式
```
交互式
用户输入一条命令，执行一条
或者系统需要提示用户输入

非交互式
用户把所有要执行的命令，写入脚本文件
直接执行该脚本文件

1、显示时间
2、创建用户abc
3、给用户设置密码123456
4、显示户口本的最后一行

vim  user.sh

写入：
date
useradd abc
echo 123456 | passwd --stdin abc
tail -1 /etc/passwd

执行脚本：
bash  user.sh
```

## 权限
```
查看文件的权限
ls  -l   文件名

drw-r--r--

第一位：表示文件类型
d   表示文件夹
-   表示文件
l   表示链接

后九位：表示权限
rw-　　　r--　　　r--
用户　　　组　　　其它
user     group    other
u        g        o

权限分类：rwx
r  读  (read)
w  写  (write)
x  执行 (execute)
```

设置权限
```
+   u+x  g+w
-   o-r
=   u=rwx  o=---

完整格式
chmod  u+x,g+w  user.sh
chmod  +x   user.sh

验证是否修改成功
ls  -l  user.sh
```

练习
```
创建文件 0702.txt
修改权限为  rwx------
查看 0702.txt 的权限
```

用数字形式设置权限
```
rwx-
4210

chmod  644  user.sh 
rw-r--r--

777
rwxrwxrwx
```

查找文件里的关键字内容
```
grep   关键字    文件路径
它会把包含关键的一整行内容，都显示出来
它的查找结果，以行为单位

查看有没有 abc 用户
grep   abc   /etc/passwd
```
