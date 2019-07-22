# Shell基础 - Day06

括号的用法
```
${}    功能：处理并显示变量
$[]    功能：数学运算
$()    功能：执行命令，等效于`命令`
```

## ${} 的其它用法

字符串替换
```
${a/old/new}

a="hello world"
echo  ${a/o/w}  
把符合条件的第一个内容，进行替换

echo  ${a//o/w}  
把符合条件的所有内容，进行替换
```

掐头去尾
```
【掐头】
${str#*关键字}
最短匹配，找到符合条件的第一个内容，进行处理

${str##*关键字}
最长匹配，找到符合条件的最后一个内容，进行处理

举例：

str="a.tar.gz"
echo ${str#*.}
tar.gz

echo ${str##*.}
gz


【去尾】
${str%关键字*}
最短匹配，找到符合条件的第一个内容，进行处理

${str%%关键字*}
最长匹配，找到符合条件的最后一个内容，进行处理
```

练习
```
编写脚本 chhouzhui.sh
批量修改文件后缀

read -p "要修改的后缀:" a
read -p "目标后缀:" b

for  name   in  `ls  *.$a`
do
    file=${name%.*}
    new=$file.$b
    mv  $name  $new
    sleep 0.1
    echo "$name ====> $new"
done
```

控制流程的关键字
```
continue   继续下一次循环
break      结束循环
exit       退出程序
```
练习
```
打印1~10之间的数字，但不包括6
for  a  in  `seq 10`
do
    if [ $a -eq 6 ];then
        continue
    fi
    echo  $a
done
```

字符串的初值
```
编程脚本，输入用户名、密码
自动帮助用户注册该帐号

read -p "input username:" name
if [ -z $name ];then
    echo "您未输入用户名，程序退出!"
    exit
fi

read -p "input password:" password
password=${password:-123456}

useradd $name
echo $password | passwd  --stdin  $name
```

字符串的判断
```
=      字符串是否相等
!=     字符串是否不相等

-z  $a    
字符串的长度是否为0（zero）

! -z  $a
字符串长度是否不为0（变量是否初始化）
```

文件的判断
```
-d -f -r -w -x -e 

-s  文件名
文件存在，并且内容长度>0

编写脚本，删除当前目录下的所有“空文件”
for   a  in  `ls  *.txt`
do
    if [ ! -s $a ];then
        rm -f  $a
    fi
done
```

## unset
```
临时设置的变量、函数，可以用unset删除
a="hello"

echo $a
hello

unset a
echo $a
没有内容
```

# awk
从文件里提取符合条件的数据
```
awk   [选项]     '[条件]{指令}'   文件

$1  第一列
$2  第二列
...
NR  行数(number)
NF  列数(number  of  fields)

awk   -F:   '/root/{print $1}'    /etc/passwd  

-F   指定“分隔符”
    如果未指明，默认以空格、制表符作为分隔

【条件】
1、正则表达式
2、==   !=   >   <    <=   >=

【指令】
print 打印
执行时机：BEGIN{ }  [条件]{ }   END{ }
```

练习
```
从 /etc/passwd 里，找到默认终端是 bash 的用户
从 /etc/shadow 里，找到这些用户对应的密码字符串
把它们保存在文件 password.txt 里

users=`awk -F: '/bash$/{print $1}' /etc/passwd`

for  user  in  $users
do
   grep $user  /etc/shadow | awk -F: '{print $1,"==>",$2}' >> password.txt

   echo  >> password.txt
done
```


作业
```
编写一个脚本 lines.sh
可以通过它，得到指定后缀文件的总行数

read -p "请输入文件后缀:" houzhui
sum=0
for i in `ls *.$houzhui`
do
   sleep 0.1
   wc -l $i
   line=`wc -l  $i | awk '{print $1}'`
   let sum+=line
done

echo
echo "=========="
echo
echo "一共写了 $sum 行"
echo
```