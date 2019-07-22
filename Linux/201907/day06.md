# web基础 - Day02

## CSS
Cascading  Style  Sheets  层叠样式表

常用的样式
```css
color: red;
background: yellow;
border: 1px  solid  red;
text-shadow: 2px  2px  3px  black;
text-align: center;
font-size: 12px;
font-family: sans-serif;
cursor: pointer;
text-decoration: none;
font-weight: normal;
list-style: none;
```

## 内联样式

在开始标记里，设置 style 属性

```html
<h1 style="color:red;">一级标题</h1>
```

> 不可复用、不好维护，用得不多

## 内部样式

在head标记里，加入style标记。把样式写在style标记内

```html
<head>
    <style>
        p{
            color: red;
            background: black;
            border:1px solid red;
        }

        h1{
            color: blue;
            text-shadow: 0 0 3px  red;
        }
    </style>
</head>
```

## 外部样式

新建后缀为 .css 的文件，写入各种样式。然后在html文件的head标记里，用 `<link rel="stylesheet" href="css文件路径">` 进行关联。

## 样式层叠

可以多次给一个标记设置不同样式，它们的效果，会集中体现在标记上

如果同一个样式（比如 color），反复设置了，则遵循“就近原则”


## 尺寸的应用

单位：cm、mm、px、百分数（50%）

```css
宽度100毫米
width: 100mm;

高度200像素
height: 200px;

边框圆角半径
border-radius: 50%;
```

边框

```css
border: 边框粗细  边框样式   边框颜色;
          1px     solid     red
```

内边距
```css
padding:  8px;
1个值：上下左右均是8px

padding: 10px 20px;
2个值：上下10px，左右20px

3个值：上  左右  下
4个值：上   右   下   左

也可以单独设置
padding-top: 10px;
padding-bottom: 10px;
padding-left: 10px;
padding-right: 10px;

记住4个方位词：
上 top
下 bottom
左 left
右 right
```

外边距
```css
margin: 8px;
其它，和内边距一样设置
```

## 阴影

文字阴影
```css
text-shadow: x偏移  y偏移  阴影长度  颜色
             3px    5px    2px     red

x为正：向右偏
y为正：向下偏

值为负，朝相反方向偏移
```

边框阴影
```css
box-shadow: x偏移  y偏移  阴影长度  颜色
            3px    5px     2px    red
```

边框圆角
```css
border-radius: 10px;

值设为50%，是规则的圆形（椭圆或正圆）
```

光标样式
```css
cursor: pointer;
取值：wait、help、text、move
```

字体相关
```css
字体大小
font-size: 12px;
字体样式
font-family: 黑体;
字体粗细
font-weight: bold;
文本装饰
text-decoration: none;
取值：
underline line-through overline
  下划线   从中间穿越    上划线

去除超链接的默认下划线
text-decoration: none;
```

文字对齐
```css
text-align: center;
设置给块级标记

取值：
left center right
 左    中    右
```

## 颜色

英文单词
```
red  orange  yellow  green  blue  purple  white  black  gray  pink

弊端：单词量有限，无法描述更多颜色
```


rgb形式
```
color: rgb(80,120,66);

red
green
blue

取值范围：0~255

rgb(0,0,0)
黑色

rgb(255,255,255)
白色
```

rgba形式
```
alpha   透明度
取值范围： 0~1

color: rgba(88,99,156,0.5);
```

十六进制的形式
```
0123456789abcdef

#6位十六进制数
#c067dd
#ff0000

前2位：红
中间2位：绿
后2位：蓝

#3位十六进制数
#a56
```

# 选择器

元素选择器
```
用元素名，作为选择器
p{...}
h1{...}
```

id选择器
```
<p id="a1">测试</p>

#id值
#a1{...}
```

class选择器
```css
<p class="boy">测试</p>
<p class="girl">测试</p>
<p class="girl">测试</p>
<p class="boy">测试</p>
<h1 class="boy">标题</h1>

.类名{...}
.boy{...}
.girl{...}

提前定义好样式文件
manhao.css

.big{font-size: 36px;}
.middle{font-size: 20px;}
.small{font-size: 8px;}

<p class="big">测试</p>
<h1 class="small">标题</h1>
```

群组选择器
```css
div,p,ul,#a1,.boy,ol{...}
```

子代选择器
```css
<ul  id="u">
    <li>aa</li>
    <li>bb</li>
</ul>

<ul>
    <li>aa</li>
    <li>bb</li>
</ul>

#u>li{...}
```

后代选择器
```css
<div  id="d">
    <p>aaaaa</p>
    <div>
        <p>bbb</p>
    </div>
</div>

#d>div>p{color:red;}
效果：bbb变红色

#d>p{color:green;}
效果：aaa是绿色

#d p{color:blue;}
效果：aaa、bbb都是蓝色
```

伪类选择器
```css
<a href="#">百度</a>

默认状态
a{...}
鼠标悬停状态
a:hover{...}
鼠标按住不放
a:active{...}
访问过后
a:visited{...}
```

## 居中

让块级元素在页面里左右居中
```css
margin: 0    auto;
       上下  左右

左右设置为auto：
系统会自动计算剩余宽度，然后除以2
```

让文字在块级元素里居中
```css
让 line-height 和 height 一样

块级元素{
    height: 100px;
    text-align: center;
    line-height: 100px;
}
```

注释
```
html的注释
<!--注释的内容-->

css的注释
/*注释的内容*/
```

# 备份文件到另一台电脑

1. 把要备份的文件，打包压缩
```shell
 tar  -zcvf  guoxn.tar.gz   a.txt  b.txt
```
2. 远程拷贝到服务器的对应目录
```shell
scp  guoxn.tar.gz   student@176.4.15.38:/home/student/backup
密码：redhat
```
3. 从远程机器上，把文件复制到本机的当前目录
```
scp  student@176.4.15.38:/home/student/backup/guoxn.tar.gz   .
密码：redhat

如果资源放在了web服务器里，也可以按以下方法下载：
wget   http://176.4.15.38/guoxn.tar.gz
```






