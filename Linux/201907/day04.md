# Linux基础 - Day04

前后端的交互过程
```
用户输入 jd.com
DNS服务：负责把 jd.com 域名，解析为服务器ip
jd 服务器得到客户端的请求，查询数据库
把数据发送(响应)给客户端

数据：
文本内容
页面文件 index.html
图片资源 1.jpg 2.png
...

前端的作用：
帮助用户发送请求
接受服务端发来的响应数据
解析、渲染数据，以图文形式显示给用户

后端的作用：
接收前端发来的请求数据
访问数据库
把得到的数据结果，响应给前端
```

## 给系统安装软件
```
查看仓库信息
yum  repolist

列出仓库里所有的软件包
yum  list

列出包含tree关键字的软件包信息
yum list | grep tree

安装软件
yum  install  软件名
yum  install  tree

免确认安装
yum  -y  install  tree

卸载软件
yum  remove  软件名
yum  remove  tree

免确认卸载
yum  -y  remove  tree
```

执行命令的原理
```
执行命令输入的单词，类似于超链接、快捷方式
其实在系统里，有它对应的程序
每次执行命令时，其实是执行程序

查看命令对应的程序路径
which  ls
```

部署 apache 网站服务器
```
安装软件包
yum  -y  install  httpd

服务的管理：

查看服务的状态
systemctl  status  服务名

启动服务
systemctl  start  服务名

关闭服务
systemctl  stop  服务名

重启服务
systemctl  restart  服务名

开机自启动服务
systemctl  enable  服务名
```

网站上线
```
apache 服务器的默认路径
/var/www/html

可以把想给用户的资源，放到该目录下

访问网页内容
在浏览器里，输入ip地址（对应服务器的默认路径）
或者资源的具体路径
```

创建链接
```
硬链接
ln  源文件  新文件
ln  a.txt   b.txt
新文件，可以不依赖于源文件
如果源文件删除，新文件不受影响

软链接(soft)
ln  -s  源文件  新文件
ln  -s  a.txt   s.txt
新文件，需要依赖于源文件
```

