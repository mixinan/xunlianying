# Shell基础 - Day03

## 循环语句

for 循环
```
for  变量名  in   列表
do
    要循环执行的语句
done

每次从列表里取出一项，赋值给变量
该变量可以直接在循环语句里使用
```
列表
```
第一种：
for   a   in  5 6 8 10 55
do
    echo $a
done


第二种：

for   a   in  `seq  9`
do
    echo $a
done


第三种：

for   a   in  {1..9}
do
    echo $a
done


第四种（Linux命令）：

for  a  in  `ls  *.txt`
do
    echo $a
done
```

数学运算
```
$[数学表达式]

i=10
i=$[i+1]

+  -  *  /   %

let  a++
a++ 等效于  a=$[a+1]
a-- 等效于  a=$[a-1]

a+=1  等效于  a=$[a+1]
a*=8  等效于  a=$[a*8]
```

while 循环
```
while  [ 条件 ]
do
    循环语句
done


死循环：
while  true
do
    循环语句
done


while [ 2 -eq 2 ]
do
    循环语句
done
```

终止循环
```
break

停止当前所在的循环
程序继续往下执行
```

在 vim 里批量缩进
```
ctrl + v    进入视图模式
shift + i   进入编辑状态
用“空格”控制第一行的缩进（之后其它几行会自动跟它对齐）
按 Esc 键退出编辑状态
```



查看文件夹本身的信息
```
ls   /home
列出 home 目录下的内容

ls  -l  /home
列出 home 目录下内容的详细信息

ls  -d   /home
列出 home 目录本身

ls  -ld   /home
列出 home 目录本身的详细信息


思考：
如何列出当前目录下的所有文件夹（不包含文件）
ls   -d   */
```

自己定义脚本，给系统增加功能
```
创建脚本 lsdir.sh

for  name  in  `ls`
do
    if [ -d $name ];then
        echo  -n  "$name  "
    fi
done

chmod  u+x  lsdir.sh
/root/lsdir.sh
```

如果想让脚本以“命令”形式执行
```
第一种：
chmod  u+x  lsdir.sh
在家目录 .bashrc 里写入
alias  lsdir='/root/lsdir.sh'

source  .bashrc
执行：lsdir


第二种：
chmod  u+x  lsdir.sh
cp  /root/lsdir.sh   /usr/bin/lsdir
执行：lsdir
```

# 练习
九九乘法表
```
for  n   in  `seq 9`
do
   for i in `seq $n`
   do
        echo -en "${i}x${n}=$[i*n]\t"
   done
   echo
done
```

求一个数的绝对值
```
让用户输入一个整数
计算机显示它的绝对值

read  -p  "请输入一个整数:"  n
if [ $n -gt 0 ];then
        echo $n
else
        echo $[-n]
fi
```

列出1~100之间的所有奇数
```
for n in `seq 100`
do
    if [ $[n%2] -ne 0 ];then
        echo -n "$n "
    fi
done
echo
```

求 1~100 之间所有整数的和
```
sum=0
for a in `seq 100`
do
   let sum+=a
done
echo "最终结果是$sum"
```

随机值
```
echo  $RANDOM
范围：0~32767

范围太大，限定范围：

一个整数对5求余，结果范围：0~4
一个整数对8求余，结果范围：0~7
一个整数对n求余，结果范围：0~(n-1)

        100              0~99

限定在0~99之间
$[RANDOM%100]
```

主机名
```
查看主机名
hostname

修改主机名
vim  /etc/hostname

写入：
guoxn.2hao.cc

简单的设置方法：
hostnamectl  set-hostname  主机名
效果等同于：
在 /etc 下，创建文件 hostname
写入指定的主机名
```

