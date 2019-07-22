# Database基础 - Day04

## 数据的导入、导出

- 可以把数据库里的记录，导出到文件
- 也可以把文件里的内容，导入数据库

## 案例

```
将 /etc/passwd 的内容导入 db1.user 表
将 db1.user 表的数据导出到 /mydata/user.txt 文件
```

查看数据库默认的检索目录

```
mysql> show variables like "secure_file_priv";
+------------------+-----------------------+
| Variable_name    | Value                 |
+------------------+-----------------------+
| secure_file_priv | /var/lib/mysql-files/ |
+------------------+-----------------------+
```

修改数据库的检索目录
```
创建新的检索目录
mkdir  /mydata

设置目录的归属关系
chown  mysql  /mydata

chown  修改文件的归属关系
(own 拥有、归属)
chown   用户名    文件


在 MySQL 的配置文件 /etc/my.cnf 写入：
[mysqld]
    secure_file_priv="/mydata"

重启服务
systemctl  restart  mysqld

登录数据库后，查看检索目录
mysql> show  variables  like "secure_file_priv";
+-------------------+-----------+
| Variable_name     | Value     |
+-------------------+-----------+
| secure_file_priv  | /mydata/  |
+-------------------+-----------+

如果在配置文件里设置
secure_file_priv="/"
可将数据导出到mysql用户有写权限的任何目录
```

新建 db1 库、user 表

```
mysql -u root –p123456

create database db1;

create table db1.user(
        name char(50),
        password  char(1),
        uid int,
        gid int,
        comment  char(150),
        homedir char(50),
        shell   char(50)
);
```


拷贝文件到检索目录下
```
cp  /etc/passwd   /mydata/
```

导入数据
```
mysql> load data infile "/mydata/passwd" 
    into table user
    fields terminated by ":"
    lines terminated by "\n" ;

mysql> select  * from  user;

mysql> alter table  user
    add id int primary key auto_increment first;

mysql> select  * from  user;

如果数据字段比较多，可以使用 \G 结尾，以“列表形式”显示查询结果
select * from user\G

如果输入中途发现语法有错误，可以通过  \c 结束本次输入
alter  tabbee  user
    add  \c
```

将 db1.user 表所有记录导出到/mydata/user.txt 文件

```
查询要导出的数据
mysql> select  * from  user;

导出数据
mysql> select  * from  user  
    into  outfile "/mydata/user.txt";

默认是以制表符作为字段之间的分隔

以指定分隔符导出数据
mysql> select  * from  user  
    into  outfile "/mydata/user1.txt" 
    fields terminated by "," 
    lines terminated by "\n";

查看文件内容
cat  /mydata/user.txt
cat  /mydata/user1.txt
```

乱码问题
```
查看字符相关变量的值
show  variables  like  "%char%";

系统变量
character_set_server：默认的内部操作字符集
character_set_client：客户端来源数据使用的字符集
character_set_connection：连接层字符集
character_set_results：查询结果字符集
character_set_database：当前选中数据库的默认字符集
character_set_system：系统元数据(字段名等)字符集

临时设置对应变量的值
set  character_set_server=utf8;

永久生效：修改配置文件并重启服务
[client]
    default-character-set=utf8

[mysqld]
    character-set-server=utf8
```

## 数据备份
```
直接在终端里执行（不登录MySQL）

-A   备份所有的库和表
mysqldump   -uroot  -p123456   -A  >  /root/all.sql

备份指定的一个数据库 db1
mysqldump  -uroot  -p123456   db1  >   /root/db1.sql
不会备份建库的语句，恢复数据时，需要提前建好数据库 db1

备份 db1 库里的 user 表
mysqldump  -uroot  -p123456    db1  user  >   /root/db1_user.sql
不会备份建库的语句，恢复数据时，需要提前建好数据库 db1

-B 列出要备份的多个库名
mysqldump  -uroot  -p123456   -B  db1  db2  >   /root/db1-db2.sql
备份时，会带有建库的语句，恢复数据时，不需要提前建库
```

