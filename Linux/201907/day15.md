# Database基础 - Day02

练习：单词本
```
库名：words
表名：cmd
字段：
id   整数   主键   自增长
mingling    字符类型(20)
miaoshu     字符类型(100)
默认编码 utf8

添加6条数据
```

参考脚本
```
drop  database  if  exists  words;
create  database  words;
use  words;
create table cmd(
    id  int primary key auto_increment,
    mingling varchar(20),
    miaoshu varchar(100)
)default charset=utf8;

insert into cmd(mingling,miaoshu) values
("date","显示日期时间"),
("cd","切换文件夹"),
("pwd","打印当前目录"),
("touch","创建文件"),
("rm","删除"),
("alias","起别名");

select  *   from   cmd;
```

# 修改表结构
```
查看表结构：
desc  表名;

修改表结构：
alter  table  表名
    操作  字段  类型(宽度);

【字段】
添加字段     add
删除字段     drop
修改字段类型 modify
修改字段名   change

指定位置    after   first

【表】
修改表名     rename

修改表的默认编码
alter table  表名  default charset=utf8;

修改表的默认引擎
alter table  表名  engine=innodb;
```

## add 添加字段
```
alter table emp
    add ename char(10);

alter table emp
    add eposition char(10) first;

alter table emp
    add ephone char(10) after salary;
```
## drop 删除字段
```
alter table emp
    drop salary;
```

## modify 修改字段类型、长度、位置

```
alter table emp
    modify ename char(20);
	
alter table emp
    modify ename char(20) first;
	
alter table food
    modify fname varchar(20) after fid;
```

## change 修改字段名(同时可以指定位置)

```
alter table emp
    change  ephone  telephone char(15);

alter table emp
    change  ephone  telephone char(15) first;
```

## rename 修改表名

```
alter table 旧名称 
    rename 新名称;
```

# 约束条件

## not null 不能为空
```
create table t1(
    id int not null,
    name varchar(20)
);

insert into t1 values(null,"michael");
ERROR 1048 (23000): Column 'id' cannot be null
错误：id 列不能为空

insert into t1 (name) values("dog");
```

## default  默认值
```
create table t2(
    id int not null,
    name varchar(20) default "wuming"
);

insert  into  t2 (id) values(2);

create table t3(
    id int not null,
    age int default 18
);

insert into t3 (id) values (1);
```

## unique 唯一
```
create table t4(
    id int unique,
    age int
);

insert  into  t4 values(1,18);
insert  into  t4 values(2,23);
insert  into  t4 values(1,23);
ERROR 1062 (23000): Duplicate entry '1' for key 'id'
错误：id 键位上的值 1 重复了
```

## 错误处理
```
Can't create database 'dicdb'; database exists
数据库已经存在，不能再次创建

You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'valuse
(null,"ls","列出")' at line 1

有个SQL语法错误，在第一行的'valuse (null,"ls","列出")'旁边

Unknown column 'a' in 'field list'
在字段列表里，没有“a”这一列

update student set buzhu=buzhu*2 where age=(select max(age) from student);
ERROR 1093 (HY000): You can't specify target table 'student' for update in FROM clause

在MySQL里，不能先select一个表的记录，再按此条件更新同一个表的记录。解决办法是，将select得到的结果，再通过中间表select一遍，这样就规避了错误。

```

## like 模糊查找 
```
%    任意长度
_    一个字符

select * from words where mingling like "%w%";
包含w的内容

select * from user where  name like '_ _ _';
值是3个字符的内容
```


## 正则表达式 
regular  expression
```
^ $  .   [a-z]  
*  {n,m}  + ?

where 字段名  regexp   '正则表达式’;

select * from user  where  name  regexp '^..$';
名字是两位字符的
```

数据表
```
表名：student
字段：
id  int
name  varchar(20)
score  int
age  int
buzhu  int
字符编码 default charset=utf8

添加6条记录
```

脚本
```
create  table  student(
	id  int,
	name  varchar(20),
	score int,
	age int,
	buzhu int
)default charset=utf8;
```

 ## 聚集函数
 ```
avg(字段名)	//统计字段平均值(average)
sum(字段名)	//统计字段之和
min(字段名)	//统计字段最小值
max(字段名)	//统计字段最大值
count(字段名)	//统计字段值个数

select  avg(score)  from user ;
select  sum(buzhu)  from user;
select  min(score) from user;
select  max(age) from user;
select  count(*) from user where score<60;
```

嵌套查找
```
查询“成绩最高的学生”的所有信息
select * from student
    where score=
      ( select max(score) from student );
```

## 四则运算
```
+  -  *  /  %

age > 18 的学生，buzhu+50
update student set  buzhu=buzhu+50  where age>18;

查询所有学生的姓名和出生年份
select name,2019-age  as  birthday from  student;

as 可以起别名，用于更友好地显示查询结果
as 也可以省略，用空格代替

select name,2019-age  birthday from student;
```


## 查询结果排序 order by  
```
SQL查询  order   by   字段名   [ asc | desc ];

默认是升序(asc)排列

descend   降落、下降
ascend	  上升、升高

select * from student order by buzhu desc;

select * from student order by score asc;
```		


## 限制查询结果显示行数 limit
```
limit  N;
//显示查询结果前N条记录

limit  offset,count;
//从offset下标开始，取count条记录

select * from student order by score desc limit 3;
查询成绩前三名的学生信息

select * from student order by score desc limit 2,3;
```

## 复制表
```
create  table   表名   SQL查询；

【备份表(带有数据)】

create table  新表名称  select * from  旧表名称;
show tables;
desc   新表名称;
select  *  from  新表名称;

新表的编码格式(charset)，可能与旧表不一样
通过“ show  create  table  新表 ”查看引擎及编码

【快速建表(不带数据)】
让查询条件不成立，比如 where  5 < 1

create table  新表名称  
  select  * from  旧表名称  where  5 < 1;
```

删库删表
```
drop  table  表名;
drop  database  库名;

文件保存的路径
/var/lib/mysql

逻辑备份数据库
mysqldump   -uroot    words  >  /root/words.sql
```
