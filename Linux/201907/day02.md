# Linux基础 - Day02

回声
```
echo  参数

echo  hello
效果：hello

echo  hello  world
效果：hello world
这是 2 个参数

echo  "hello world"
效果：hello world
这是 1 个参数

echo 默认带有换行效果
比如，直接执行：
echo
不加任何参数，效果是一个空行

-n 选项，可以去除自带的换行效果
echo  -n  "hello"
```

echo 不同颜色
```
常用的颜色范围: 30~37
echo  -e  "\033[30m 黑色字 \033[0m"

30  31  32  33  34  35   36   37
黑  红  绿   黄  蓝  紫  天蓝  白

背景颜色范围：40~47
echo  -e  "\033[40;37m 黑底白字 \033[0m"

40;37m  黑底白字
41;30m  红底黑字
42;34m  绿底蓝字
```

转义符
```
echo    I'm Lilei.
不会直接显示内容，而是等待用户输入另一个单引号来结束字符串

解决：
echo  I\'m  Lilei.
\ 的意义，是把 ' 回归本来的样子，去除其它所有特殊的功能（字符串的界定）

其它转移符：
\t  \n
```

输出重定向
```
命令执行完，默认把结果显示在屏幕上
如果不想显示在屏幕上，可以用重定向

>
“覆盖”重定向

date  >  a.txt
无论之前 a.txt 里内容是什么，都会被当前的日期时间所覆盖

echo hello world  >  a.txt
无论之前 a.txt 里内容是什么，都会变成“hello world”

>>
“追加”重定向

cal  >>  a.txt
a.txt 里原有内容保持不变，在最后另起一行，加上了当前月份的日历
```

思考：如何清空文件内容
```
echo "" > a.txt
其实还是会有一个空行

echo  -n  ""  >  a.txt
不带有换行功能，但这样写比较复杂

> a.txt
清空内容
```

统计字数
```
wc  文本文件名
(word 字 count 统计)

wc  a.txt
效果：
1     2      12     a.txt
行数  字数  字节数  文件名

-l 选项，表示查看行数(line)
wc  -l  a.txt
效果：1

-w 选项，表示查看字数(word)
wc  -w  a.txt
效果：2
```

查看文本文件内容
```
cat  文本文件名
（concatinate 连接）

cat  a.txt
cat  b.txt  c.txt

-n 选项，会显示行号（number）
cat  -n   a.txt
带有行号显示文本内容
```

其它两种查看方式
```
head   文本文件名
查看文本文件的头 10 行(默认)

head   a.txt

可以加上整数作为选项，表示查看前几行
head  -3  a.txt
查看 a.txt 的头 3 行

tail   文本文件名
查看文本文件的末尾 10 行(默认)

tail   a.txt
tail  -5  a.txt
查看 a.txt 的末尾 5 行
```

# vim 编辑器
Linux 系统里的文本编辑器

基本使用
```
vim  文本文件名

如果文件已存在，则直接打开进行编辑
如果不存在，编辑并保存内容后会自动创建，不保存则不创建

【三种模式】

编辑模式
   按 i 键，进入编辑模式（insert 插入）
   按 o 键，在当前行的下方另起一行进入编辑模式
   按 O 键，在当前行的上方另起一行进入编辑模式
   按 Esc 键，退出编辑模式（escape 摆脱）

一般模式
   通过 vim 命令进入的模式

末行模式
   在一般模式下，按英文冒号:键进入末行模式
   :w   保存（write 写）
   :q   退出（quit  退出）
   :wq  保存并退出 （write  quit）
   :q!  强制退出，不保存，直接退出
   :set nu    临时显示行号（number）
   :set nonu  临时取消行号
```

让"行号"永久生效
```
在当前用户的家目录里，有个 .vimrc 文件。
如果没有，可自行创建。写入：
set nu
保存并退出

以后再使用 vim 时，都会显示行号

如果想指定 tab 键为 4 个空格的宽度
可以另起一行，写入：
set  tabstop=4
保存并退出
```

查找功能
```
在一般模式下，直接按"/"或"?"，可以进入查找模式
然后输入关键字，回车，开始查找

/关键字   从上往下查找
?关键字   从下往上查找

按 n 键，切换下一个匹配项（next）
```

替换功能
```
先输入英文冒号:进入末行模式
格式如下：
: 范围 s/old/new/选项

【范围】
不写  表示只把“当前行”的 old 改为 new
%     表示把“全文”的 old 都改为 new
5,9   表示把第 5~9 行的 old 改为 new
.,+2  当前行，以及接下来的两行

【s】
(substitute) 表示即将使用替换功能

【选项】
c  每次替换前，确认是否删除(y/n/a)
i  忽略大小写、不区分大小写(ignore)
e  不显示错误信息(error)
```

复制、粘贴、剪切
```
在一般模式下

复制   nyy  (yanked 猛拉、复制)
(n表示整数，比如3、4，如果是1，可省略)
从当前行开始，复制 n 行

如果n>=3，系统会提示“复制了n行”
否则，不提示


粘贴   np   (paste 粘贴)
在当前行下方，把刚才复制的内容粘贴 n 遍


剪切（删除）  ndd  (delete 删除)
从当前行开始，删除 n 行
其实并不是真的删除，而是放到剪切板里

如果紧接着做了“粘贴”操作，则是剪切
否则相当于删除
```

练习
```
先执行 cal > cal.txt
把当前月份的日历放入 cal.txt
使用 vim 把内容变为：

日 一 二 三 四 五 六
28 29 30 31
 7  8  9 10 11 12 13
      七月 2019
14 15 16 17 18 19 20
21 22 23 24 25 26 27
14 15 16 17 18 19 20
```

其它
```
撤销   u  (undo)
重做   ctrl + r   (redo)

跳转行
ngg  (n 是整数，表示目标行数)
或者在末行模式下 :n  
跳到第1行     gg
跳到最后1行   G

在打开文件的同时，跳到第 7 行  
vim  a.txt  +7


调节“内容”在屏幕中的显示位置
zt 置顶当前行，通常用来查看完整的下文 (top)
zz 将当前行移到屏幕中部
zb 移到底部 (bottom)


调节“光标”在屏幕中的位置
H 可以移动到屏幕的首行
M 到屏幕中间
L 到屏幕尾行


如果使用 vim 命令时，没加任何参数
相当于新建一个暂时没有名字的文件
在保存时，要指定文件的名字
w   a.txt
q

或者 wq  a.txt
```

在 vim 里，按页查看内容
```
每次翻半页
ctrl + u  (up 上)
ctrl + d  (down 下)

每次翻一页
ctrl + f  (forward 前进)
ctrl + b  (backward 后退)
```

管道   |
```
命令1  |  命令2
把命令1执行完的结果，通过管道，给命令2继续处理

ls  |  head
列出当前目录下的前 10 个文件

显示文本文件的前 5 行，并带有行号
cat  -n  a.txt | head -5

bc 计算器
echo  1+2  |  bc
```

练习
```
使用管道，显示七月份日历的第3、4、5行

      七月 2019     
日 一 二 三 四 五 六
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 31

参考：
cal  |  head  -5  |  tail  -3
```

临时设置别名
```
alias  别名="本来的命令"
alias  qu3="cal | head -5 | tail -3"

执行：qu3

通过命令设置的别名，是临时生效
重启终端以后，别名不存在

取消临时别名
unalias  qu3
```

永久设置别名
```
需要修改配置文件
在当前用户的家目录里，有个隐藏文件 .bashrc
（bash  resource 资源）
把设置别名的语句，写入该文件
重新打开终端

列出系统里的别名
alias

查询某个别名的信息
alias  别名
alias  gos
效果：alias gos='ssh  root@172.25.0.11'
```


几个口诀
```
数据库：  增、删、改、查
服务器：  ip、主机名、搭yum
软件管理：装包、修改配置、启服务
```

一些快捷键
```
通用快捷键：
home    把光标跳转到行首
end     把光标跳转到行尾
ctrl + home  把光标跳转到整个文档开头
ctrl + end   把光标跳转到整个文档末尾
shift + 字母键   临时输入大写

delete  删除光标后的内容
删除文本内容时，同时按 ctrl 键，可以删除单词


Linux里的快捷键：
ctrl + L  清空整个屏幕内容
ctrl + u  清空光标左侧内容
ctrl + c  结束当前的进程
ctrl + w  删除光标左侧的单词


windows里的快捷键：
win + E   打开我的电脑（计算机）
win + d   回到桌面（desktop）
win + L   锁屏(lock 锁) 
```

通配符
```
*  
可以匹配任意长度的字符	
ls   *.txt
列出当前目录下，所有 .txt 后缀的文件

?  
可以匹配 1 位字符
ls   ?.txt
列出名字只有 1 位字符、后缀是 txt 的文件
ls   ??.txt
列出名字是 2 位字符、后缀是 txt 的文件

ls  a?b.txt
ls  a*b.txt
```

计算器  bc
```
(binary  compute)

+   -   *    /      %
加  减  乘  求商  求余

1+2
3-4
5*6
12/5
3%5
```

文件的复制、移动
```
复制  cp  (copy)
cp   要复制的文件   要复制到的地方
cp  a.txt  music
cp  a.txt  b.txt  c.txt  music

最后一个参数，表示要复制到的地方，
其余参数，表示要复制的文件（可以是多个）

复制文件夹
cp  -r  abc/  music/

保持文件本身的归属关系
cp  -p  文件名   /mnt

========================
远程复制文件  scp
(secure  安全的  copy)

scp    1.zip   root@172.25.0.11:/root
把本机当前目录下的 1.zip
以远程机器(172.25.0.11)root的身份拷贝到 /root 下

scp    root@172.25.0.11:/root/a.txt   .
把远程的 a.txt 文件，拷贝到本机的当前目录下

========================
剪切  mv  (move)
mv   要移动的文件   要移动到的地方
mv  a.txt  music
mv  a.txt  b.txt  c.txt  music

移动文件夹
mv  ddd/   music/

重命名
mv  a.txt     music/bbb.txt
cp  date.txt  music/date02.txt

mv  date.txt  date03.txt
mv  music  pic
```

打包压缩
```
打包
tar  -cvf  打包后的文件名   要打包的文件列表

tar  -cvf  a.tar  a.txt  b.txt  music
(create 创建 view 可见 file 文件)

-f  选项必须在最后，后面直接跟压缩包的名字

列出压缩包里的内容
tar  -tf  a.tar
(t 表示list，列出)

=============================
打包并压缩
tar -zcvf  a.tar.gz  a.txt  b.txt  music

=============================
展开
tar  -xvf   a.tar
（x 表示extract，展开）
默认把a.tar里的内容展开到当前目录

-C  选项，可以展开到指定目录
tar  -xvf  a.tar  -C  目录名

=======================
解压并展开
tar  -zxvf  test.tar.gz
```

单位常识（1024）
```
1TB = 1024GB
1GB = 1024MB
1MB = 1024KB
1KB = 1024B
```


