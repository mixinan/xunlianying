# Database基础 - Day01

MySQL、Mariadb、Oracle、SQL Server 等产品，使用 SQL 语言

安装、部署、数据备份、恢复、数据库集群

```
yum  -y   install   mariadb-server   mariadb
systemctl   start   mariadb
systemctl   enable   mariadb
mysql  -uroot
```

基本命令
```
show   databases;
显示所有的库

use  库名;
使用某个库

select  database();
查询正在使用的数据库

show  tables;
显示当前数据库里所有的数据表

desc    表名;
描述这个表的信息

create   database   student;
创建数据库
```
创建数据表
```
CREATE TABLE 表名 (
    属性名 数据类型 [约束条件],
    属性名 数据类型 [约束条件],
    ...
    属性名 数据类型 [约束条件]
);

create  table  info(
    sid     int,
    name    char(20),
    age     int
);

show  create table  表名;
显示创建某个表的语句
```

插入数据（增）
```
insert into 表名 (字段1,字段2,...) values(值1,值2,...);

insert into 表名 (字段1, 字段2) values(值1,值2);

insert into 表名  values(值1,值2,... );

【一次添加多条数据】
insert  into  表名  values 
(值1, 值2, ...),
(值1, 值2, ...),
(值1, 值2, ...);
```

删除
```
delete  from  表名;
把表内数据全部删除

delete  from  表名  where  kid=2;
删除表内 kid 是 2 的一条数据

truncate   表名;
把表内数据全部删除
```
TRUNCATE 和 DELETE 的区别

1. delete语句，后面可以跟where子句，来删除满足条件的部分记录，而truncate语句，只能用于删除表中的所有记录。

2. truncate语句，清空表中的数据后，再添加记录时，自动增加字段的默认初始值重新从1开始，而使用delete删除后，再添加记录时，自动增加字段的值，是在原来的基础上加1。

3. delete语句，每删除一条记录，都会在日志中记录，而使用truncate语句，不会在日志中记录删除的内容，因此，truncate语句的执行效率比delete语句高。


查看表中的数据
```
select   *   from   表名;
查看表内所有字段的数据

select  kemu  from  kecheng;
查看 kecheng 表里的 kemu 数据

select  kid,kemu  from  kecheng;
查看 kecheng 表里的 kid,kemu 数据
```

支持中文
```
create  table  t1(
    id  int,
    name  char(20)
)default charset=utf8;
```


数据类型
```
int     (integer 整数)
char    (character 字符)

char(20)     固定长度（用空间换时间）
varchar(20)  可变长度（用时间换空间）
```

修改、更新
```
update   表名   set   字段="值"  where  条件;

update  menu  set  price="12"  where  name="炒鸡蛋";
update  menu  set  price="50",class=2 where id=5;
```

主键 primary key
```
create  table  t6(
    id   int   primary  key,
    name  varchar(20)
);

insert   into   t6  values (1, "hello");

insert   into   t6  values (1, "world");
报错：不能重复

insert   into   t6  values (null, "world");
报错：不能为空
```
自增长 auto_increment
```
create  table  t7(
    id   int   primary  key  auto_increment,
    name  varchar(20)
);

insert  into  t7  values(null,"hello");
insert  into  t7 (name)  values("world");
```

条件语句
```
name="凉拌牛肉"
name 值是“凉拌牛肉”的，符合条件

class!=2
class 值不等于2的，符合条件

id<5
id 值小于5的，都符合

id  in(1,3,6)
id 值在1、3、6里，都符合

delete  from  menu  where  id  in (1,3,5);

id  not in(1,3,6)
id 值不在1、3、6里，则符合

delete  from  menu  where  id  not  in (1,3,5);

is  null
为空，则符合条件

is  not  null
不为空，则符合条件

between  ... and  ...
在...和...之间

delete  from  menu  where  id  between  3  and  6;
删除 id 值在 3 和 6 之间的数据

【逻辑运算】
逻辑与  and 或 &&
逻辑或  or  或 ||
逻辑非  not

delete  from  menu  where  id<4  and  class=2;
delete  from  menu  where  id<4  &&  class=2;
delete  from  menu  where  id<4  or  class=2;
delete  from  menu  where  id<4  ||  class=2;
```
