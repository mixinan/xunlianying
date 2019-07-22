# Database基础 - Day03

查看数据库默认的存储引擎
```
show engines;
```
修改数据库默认的存储引擎
```
systemctl  stop mariadb
vim /etc/my.cnf
[mysqld]
   default-storage-engine=myisam

systemctl  start mariadb
mysql -uroot
show engines;
```

之后新建的表，如果未指定引擎，则按默认引擎创建


修改表使用的存储引擎
```
alter table  表名 engine=myisam;
```

建表时指定存储引擎
```
create  table 表名 (
  name char(10)
) engine=innodb;
```

MYISAM 存储引擎特点：
```
支持表级锁
不支持外键、事务、事务回滚
表文件个数
表名.frm   表名.MYD  表名.MYI
表结构      数据           index信息
```

INNODB 存储引擎特点
```
支持外键 
支持行级锁
支持事务和事务回滚
表文件个数 
表名.frm  t6.ibd
表结构     数据+index信息
```
事务回滚
> 在访问过程中，任意一步操作失败，恢复之前的所有操作


工作中建表时，如何决定表使用那种存储引擎？

> select 操作多的表，适合使用myisam存储引擎，节省系统资源

> insert/update/delete 操作多的表，适合使用innodb存储引擎，并发访问量大

练习
```
库名：words
表名：t18（innodb引擎、utf8）
字段：
name  varchar(20)
age   int
score   int

表结构修改为：
id   int   主键   自增长
age
score
name
引擎：myisam

添加 3 条数据

把数据库 words 备份为  /root/words.sql
先退出数据库
mysqldump   -uroot   words  >  /root/words.sql
```

克隆一台虚拟机
```
clone-vm7
输入虚拟机编号

帐号：root
密码：123456
```

设置 ip 地址
```
nmcli  connection  modify  eth0   ipv4.method    manual ipv4.addresses    192.168.4.50/24     connection.autoconnect  yes

nmcli  connection  up  eth0

查看 eth0 的 ip 地址
ifconfig   eth0
```

设置主机名
```
hostnamectl   set-hostname   名字
exit
重新登录，可以看到效果
```

yum源的配置
```
/etc/yum.repos.d/local.repo

修改 baseurl 的 ip 地址为：192.168.4.254

yum  clean  all
清空 yum 缓存

yum  repolist
查看源的信息
```

# 安装 MySQL
```
1. 下载 MySQL 安装包
2. 传到虚拟机 scp  mysql-5.7.17.tar  root@192.168.4.50:/root
3. 在虚拟机解压 tar  -xf  mysql-5.7.17.tar   
4. 安装 yum  -y  install   mysql-comm*
```

启动服务
```
/var/lib/mysql
默认存储 MySQL 数据的目录

systemctl  start   mysqld
第一次启动 mysqld 服务时会进行初始化，在 /var/lib/mysql 目录下生成默认配置文件，需要等待一会儿

systemctl  enable  mysqld
让 mysqld 服务开机自启动
```

第一次登录
```
/var/log/mysqld.log
mysqld 的日志文件

grep  "password"  /var/log/mysqld.log
找到系统自动生成的临时密码

A temporary password is generated for root@localhost: _HpLppTp=7ue

用临时密码登录
mysql   -uroot   -p'_HpLppTp=7ue'
```
用临时密码登录后，需要重设密码
```
set  global  validate_password_policy=0;
密码策略为 0

set  global  validate_password_length=6;
密码长度为 6

密码策略的取值范围：
0 长度
1 长度、数字、大小写、特殊字符
2 长度、数字、大小写、特殊字符、字典文件
```
设置密码为 123456
```
alter  user  user()  identified by "123456";
```

## 作业
```
克隆 3 台虚拟机

主机名与对应ip： 
m11    192.168.4.11 
m22    192.168.4.22
m33    192.168.4.33

分别部署mysql，并且设置root密码为123456
```