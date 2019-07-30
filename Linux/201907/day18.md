# Database基础 - Day05

练习
```
主机名：mysql51
ip：192.168.4.51
yum：192.168.4.254

部署 MySQL
修改密码：123456

创建库：db1
创建表：t1
字段：
id  int  主键  自增长
name  varchar(20)
age  int

把 stu.txt 里的内容导入进来：

1,Michael,25
2,Jordan,31
3,Jim,18
4,Lily,12
5,Brown,21
6,Li Kui,33
7,Brouk,19
8,Kobe,28
```

## 数据恢复

```
已经备份好的脚本：
db1.sql    db2.sql

先在数据库里创建对应的2个库
create   database   db1;
create   database   db2;

在终端里，执行以下两个语句
mysql  -uroot  -p123456   db1  <  db1.sql
mysql  -uroot  -p123456   db2  <  db2.sql
```

## phpMyAdmin
```
安装  httpd    php    php-mysql
systemctl   start   httpd
systemctl   start   mysqld

下载好 phpMyAdmin 安装包
tar  -xf  phpMyAdmin

cd   phpMyAdmin
cp   config.sample.inc.php   config.inc.php
vim  config.inc.php
在第17行设置密码，保存并退出

把 phpMyAdmin 文件夹，移动到 /var/www/html 目录下
mv   phpMyAdmin   /var/www/html/phpmyadmin

在真机浏览器里，访问  http://192.168.4.51/phpmyadmin
账号：root
密码：123456
```

Git
```
rpm  -q   git
yum  -y   install  git

配置基本信息
git   config   --global  user.name  "guoxn"
git   config   --global  user.email  "guoxn@tedu.cn"
git   config   --global  core.editor   vim

查看配置
git  config   --list
vim   ~/.gitconfig

初始化项目

在项目的目录下，git  init
ls   -A

正常进行开发
vim  a.txt   b.sh  c.html

查看状态
git   status

在工作区的内容添加到暂存区
git   add   .

git   commit   -m  "提交的信息"
```

分支
```
查看分支
git  branch

创建分支
git  branch  分支名字

切换分支
git  checkout  分支名字
做各种开发

git  checkout  master

合并分支
git   merge   分支名字

删除分支
git  branch   -d   分支名字
```

markdown
```
# 一级标题
## 二级标题
### 三级标题

**加粗**
*斜体*

- 三国演义
- 水浒传
- 西游记

1. 三国演义
2. 水浒传

`高亮颜色`

超链接
[文本内容](网址)

图片
![文本内容](资源地址)

> 引用的语句

姓名|年龄|性别
-|-|-
小明|18|boy
小刚|20|boy
```

