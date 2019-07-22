# Shell基础 - Day04

逻辑运算
```
并且    &&
或者    ||
非      !

[ 条件1 ] && [ 条件2 ] 
两个条件都成立，结果才成立

[ 条件1 ] || [ 条件2 ] 
只要有一个条件成立，结果就成立

[ -f  $name ]
如果是文件，成立
[  ! -f  $name ]
如果不是文件，则成立


在1~10之间的数，如果“大于5”并且“是偶数”，就显示出来

for  a  in  `seq  10`
do
    if [ $a -gt 5 ] && [ $[a%2] -eq 0 ];then
        echo  $a
    fi
done
```

闰年
```
能被4整除并且不能被100整除
或者
能被400整除

read  -p  "请输入年份："  year
if [ $[year%4] -eq 0 ]&&[ $[year%100] -ne 0  ] || [ $[year%400]  -eq  0  ];then
    echo "$year是闰年"
else
    echo "$year不是闰年"
fi
```

开机执行某条命令
```
/etc/profile

在最后增加一行，写入要执行的命令
每次开机，都会执行
```

## 函数

> 需要反复执行的代码段，可以单独给它们起个名字。以后需要执行这段代码时，直接执行该名字即可

函数定义和调用
```
函数名(){
    执行的代码段
}

show(){
    date
    cal
    pwd
    ls
}

调用函数
show
```

获取函数的返回值
```
sum(){
  sum=0
  for  a  in `seq 100`
  do  
    let sum+=a
  done
  echo $sum
}

result=`sum`
echo $result
```

往函数里传入参数
```
调用函数时，可以在函数名后面传入参数
在函数里，通过位置变量($1、$2)来接收参数

sum(){
  sum=0
  for  a  in `seq $1`
  do
    let sum+=a
  done
  echo $sum
}

read -p "请输入一个数字:" n
result=`sum $n`
echo $result
```

练习
```
创建脚本  useradd.sh
下载 http://176.4.15.36/user.txt 文件
批量创建文件里的用户，并给它们设置初始密码 123456
wget  http://176.4.15.36/user.txt
scp  user.txt   root@172.25.0.11:/root

代码：
for name in `cat user.txt`
do
   useradd  $name
   echo 123456 | passwd  --stdin  $name  
done
```

生成随机密码
```
从"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!_[]{}().," 里随机取6位作为密码

字符串的截取
${all : 从哪儿开始取 : 取几位}

获取一个变量值的长度
${#变量名}
${#all}

随机值=$[RANDOM % 字符串的总长度]
${all : 随机值 : 1}
```
代码
```
# 创建密码的函数
createPass(){
  mima=""
  all="abcdefghijklm!_[]{}()"
  chang=${#all}
  
  for  a  in  `seq $1`
  do  
    suiji=$[RANDOM%chang]
    zimu=${all:suiji:1}
    mima=$mima$zimu
  done

  echo $mima
}

read -p "请输入密码的位数:" weishu

for  a   in  `cat  user.txt`
do
    useradd $a
    pw=`createPass $weishu`
    echo $pw | passwd  --stdin  $a  
    echo "$a===$pw" >> userpasswd.txt
done
```


# 正则表达式
```
grep  选项  '正则表达式'   文件路径

grep  -n   显示行号
grep  -v   取反
grep  -i   忽略大小写(ignore-case)
grep  -c   匹配的数量(count)
grep  -q   静默匹配（quiet, 只想知道有没有匹配到。至于匹配了什么内容，不管）$? 保存结果（0 匹配到，1 未匹配到）
grep  -E   支持扩展功能
```

基本正则
```
^   以...开头
$   以...结尾
[ ]  匹配范围内的一个字符
[^ ]  对范围取反
.     任意一个字符

[a-z]       一个小写字母
[A-Z]       一个大写字母
[a-zA-Z]    一个字母
[0-9]       一个数字
[^a-z]      不是小写字母

grep  '\.$'  anli.txt
筛选出以.结尾的内容

【符合条件的数量】

*       匹配任意个字符
\{n\}   符合条件的有n个
\{n,m\} 符合条件的有n~m个
\{n,\}  符合条件的至少有n个

grep  '[0-9]\{4\}'  anli.txt
筛选出有4个相连数字的内容

grep  '^a'   anli.txt
筛选出以a开头的内容

grep  'a$'   anli.txt
筛选以a结尾的内容

grep  '[a-z]'  anli.txt
筛选包含小写字母的内容

grep  '[A-Z]'  anli.txt
筛选包含大写字母的内容

grep  '^[A-Z]'  anli.txt
筛选以大写字母开头的内容

筛选出有内容的行（不是空行）
grep  '.'   anli.txt
grep   -v   '^$'   anli.txt
```

扩展正则
```
{n,m}   n~m个
+       至少1个
?       0或1个
|       或者
( )     组合为整体
\b      单词边界

grep  -E  '[0-9]{4}'  anli.txt
egrep  '[0-9]{4}'  anli.txt
egrep   'taste|test'  anli.txt
```

练习：
```
手机号
egrep  '\b[0-9]{11}\b'  anli.txt

邮箱
egrep  '[0-9a-zA-Z]+@[a-zA-Z0-9]{2,}\.[a-zA-Z]+'  anli.txt
```
