# Shell基础 - Day05

练习
```
编写脚本 getBir.sh
输入一个身份证号码，获取生日
```

代码
```
getBirth(){
 # 152536199505052233
 id=$1
 birth=${id:6:8}
 echo $birth
}

read -p "请输入身份证号:" shenfz
res=`getBirth $shenfz`
echo $res
```

## du 命令
```
（disk   usage）
查看对应文件占用磁盘的信息

du   路径
du   music/
du   a.txt

-h   human-readable 用人类易读的方式（K、M、G）显示
-s    summarize 显示总体的大小

du  -sh   music/
```


## rsync 命令
```
一个远程同步文件的工具
rsync  -av  --delete   /root/abc/   /mnt/backup
```
选项
```shell
-a
相当于-rlptgoD，-r 是递归 -l 是链接文件；-p 表示保持文件原有权限；-t 保持文件原有时间；-g 保持文件原有用户组；-o 保持文件原有属主；-D 相当于块设备文件

-v
显示同步的过程

--delete  
如果SRC中没有某文件，但DST中有，就删掉它

-n
不会真的去同步，只是模拟一下同步过程(dry-run 干跑，类似于“干打雷不下雨”)
```

# sed 工具
```
sed  选项  '条件 操作'  文件路径
sed  -i  '4d'  a.txt
```

## 选项
```
-n  （屏蔽默认输出。默认会输出全部内容）
-r  （支持扩展正则）
-i  （直接修改源文件。默认是临时修改，源文件不变）
```

## 条件：行号和正则

行号
```
sed -n '1p' /etc/passwd
打印第1行

sed -n '1,3p' /etc/passwd
打印第1~3行

sed -n '2,+3p' /etc/passwd
打印第2行，以及后面3行

sed -n '1~2p' /etc/passwd
打印第1行，以及每隔2行

sed  -n  '1p; 3p; 4p'  /etc/passwd
打印不连续的行，第一、三、四行

sed  -n  '$p'  /etc/passwd
打印最后一行（第一行不能用'^p'，应该是'1p'）
```

正则表达式
```
要把正则表达式，放入两个斜杠“/ /”之间

sed -n '/root/p' /etc/passwd
打印包含root关键字的行

sed -n  'p'  /etc/passwd
如果没有任何条件，则全部打印
```

操作
```
p   (print) 打印
d   (delete) 删除
s   替换

a   (append) 追加
i    (insert) 插入
c   (replace) 替换

sed   '2a  hello'  passwd
在第2行的后面，追加一行“hello”

sed   '5i  b=22'  passwd
在第5行的前面，插入一行“b=22”

sed  '1c  hello(){'   passwd
把第1行，替换为“ hello(){ ”
```

总结
```
sed   选项   '条件 操作'   文件名

选项： i  n  r
条件：行号，正则表达式
操作：p  d  s  a  i  c
```

## case 语句
```
【抽选人回答问题的程序】

每个人对应一个号码
系统自动获取一个随机值
选中哪个数，就显示对应的人的名字

jinli=$[RANDOM%20]
jinli=$[jinli+1]
echo -n  "正在紧张抽取中"

for i  in  `seq 8`
do
 sleep 0.3
 echo -n  "."
done

sleep 0.3
echo   "."

case  $jinli  in
1)
  echo "shimin";;
2)
  echo "manhao";;
3)
  echo "hanqin";;
4)
  echo "binghe";;
*)
  echo "teacher shen";;
esac
```

把随机值，限定在 5~123
```
对n求余数，结果范围是: 0~（n-1）

6~50
-6  -6
0~44

$[RANDOM%45+6]

37~199
-37  -37
0~162

$[RANDOM%163+37]
```
