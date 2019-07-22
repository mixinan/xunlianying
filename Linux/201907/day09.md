# Shell基础 - Day02

## find命令
在`指定目录`查找`符合条件`的文件  
递归查找，掘地三尺
```
find  目录  选项  选项值   
```
常用选项
```
name    名字
-name "*.txt"

type    类型
-type f   (file 文件)
-type d   (directory  文件夹)

user    用户名
-user student

mindepth  层数
-mindepth 3   至少从第3层开始找

maxdepth  层数
-maxdepth 3   最多找3层

size    大小
-size +1G
```

查找到以后的操作
```
-exec  命令  \;

find  /  -type f -user student -exec cp -p {} /mnt \;

cp -p 目的是保持文件的归属关系
```

## 条件判断 test

数字比较
```
-eq   相等(equal)
-ne   不等(not equal)
-lt    小于(less than)
-gt  大于(greater than)
-le   小于等于(less  equal)
-ge  大于等于(greater equal)

test   表达式
test  80 -lt 90

echo $? 
保存上一条命令"是否成功执行"的结果
0   表示成功
非0 表示不成功

简化的写法：
[ 80 -eq 90 ]

中括号的内部，要加空格
等效于
test 80 -eq 90
```

字符串比较
```
=    判断是否"相等"
!=   判断是否"不相等"

a="hello"
[ $a = "world" ]
[ $a != "world"]
```

关于文件的判断
```
-f  (file)  判断是否为文件
-d  (directory) 判断是否为文件夹
-e  (exists  存在)  判断是否存在
-r  (read)  判断是否可读
-w  (write) 判断是否为可写
-x  (execute)   判断是否为可执行

[ -f  a.txt  ]
判断 a.txt 是否为文件
```

练习
```
创建文件 test.sh
如果当前目录里存在 a.txt，删除它
否则，创建它
```

## 分支语句

第一种
```
如果成立，执行。否则，啥也不干。

if [ 条件判断 ];then
    如果条件成立，执行这里的语句
fi
```

第二种
```
如果成立，执行对应语句。
否则，执行其它的语句。

if [ 条件判断 ];then
    如果成立，执行这里的语句
else
    如果不成立，执行这里的语句
fi
```

第三种
```
如果 条件1 成立，执行对应语句1
否则，如果 条件2 成立，执行对应语句2
否则，如果 条件3 成立，执行对应语句3
否则，执行对应语句4

程序最终，只会执行其中一种情况

if [ 条件1 ];then
    对应语句1
elif [ 条件2 ];then
    对应语句2
elif [ 条件3 ];then
    对应语句3
else
    对应语句4
fi
```

## 三种界定符

" "  双引号
```
支持变量的解析

a=10
echo  "hello $a"
效果：hello 10

练习：
a=60
echo "小明的体重是$akg"
效果：小明的体重是

系统误以为变量名称是 akg
而 akg 变量并不存在，所以为空

解决：
${变量名} 可以界定变量名
echo "小明的体重是${a}kg"
效果：小明的体重是60kg
```

' '  单引号
```
不支持变量的解析

a=10
echo  'hello $a'
效果：hello $a
```

` `  反撇号
```
变量=`命令`
可以先执行` `里面的命令，然后把执行结果，赋值给变量

比如：
a=`date`
echo $a
效果：2019年7月9日 15:33:18

也可以使用 $(命令)
a=$(date)  效果等同于  a=`date`
```

周期性任务
```
crontab   -u   用户名   -e

u   (user 用户)
    如果不指定用户，默认是当前用户
e   (edit 编辑)
l   (list 列出)
r   (remove 删除)

分  时  日  月  周   要执行的命令或脚本
*   *   *   *   *   date >> time.txt
每分钟，都执行一次 date >> time.txt

30  2   *   *   *   /root/backup.sh
每天的2:30，执行一次脚本 backup.sh

crontab  -l   -u  student
列出用户 student 的周期任务计划
```

练习
```
date   +%Y
可以得到今年的年份（2019）

%Y  年（year）
%m  月（month）
%d  日（day）
%H  时（hour）
%M  分（minute）
%S  秒（second）

需求：
每天凌晨 2:30 备份 /root 文件夹内容
命名格式： 年月日.tar.gz

time=`date  +%Y%m%d`
file=${time}.tar.gz
效果：20190709.tar.gz

tar  -zPcf  $file  /home
如果要备份绝对路径的文件，需要加 P 选项
```

特殊文件 /dev/null
```
可以丢弃某些数据，让它不显示在终端里

useradd  lisi
echo  123456 | passwd --stdin lisi  > /dev/null
```

序列
```
seq  数字
seq  9
效果：1 2 3 4 5 6 7 8 9

```

yum 源介绍
```
存放的路径
/etc/yum.repos.d

[hello]
name = abc
gpgcheck = 0
enabled = 1
baseurl = http://content.example.com/rhel7.0/x86_64/dvd

另一种简便的方法：
yum-config-manager  --add-repo=源的地址
需要对生成的文件进行编辑，加入：
gpgcheck=0
```
