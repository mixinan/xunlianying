# web基础 - Day01
```
HTML        网页结构
CSS         网页样式
JavaScript  动态效果
```

## HTML
```
hyper       超级
text        文本 a  b  c
markup      标记 <html></html>
language    语言
```

标记写法
```
双标记
<html></html>
<head></head>

单标记
<br>  或  <br />
<img> 或  <img />

如果要把标记进行嵌套
建议用 tab 缩进（结构一目了然，便于代码维护）
```

## 编写网页文件 a.html

网页结构
```
<!doctype  html>
<html>
    <head>
        <title>网页标题</title>
        <meta  charset="utf-8">
    </head>
    <body>
        在此编写给用户看的内容
    </body>
</html>
```

文档类型声明
```
<!doctype  html>
doc   document 文档
type  类型
```
head标记里，写入文档信息
```
网页标题  <title>京东</title>
字符编码  <meta  charset="utf-8">
```

# 常用标记(元素、标签)
```
加粗   b
(bold)
<b>要加粗的内容</b>   

下划线   u
(underline)
<u>要加下划线的内容</u>

斜体  i
(italic)
<i>要倾斜的内容</i>

段落  p
(paragraph)
<p>这里写段落内容</p>

下标   sub
H2O   水的化学表达式
H<sub>2</sub>O

上标   sup
8的平方
8<sup>2</sup>

简单记忆办法：
圆圈在上(p)，是上标
圆圈在下(b)，是下标
```

超链接
```
<a href="http://blog.2hao.cc">万码千钧</a>
网页上显示超链接“万码千钧”
点击跳转到 http://blog.2hao.cc

<a href="#a1">锚点</a>
<a id="a1">要跳转到的目标位置</a>

常用的属性：

id="a1"
给标记起一个唯一的身份标识
在同一个页面里，id 不能重复

href="http://blog.2hao.cc"
点击跳转到的地址
如果值为“#”，跳到页面顶部

target="_self"
打开目标网页的方式：在当前页面
如果未指定，默认是“_self”

target="_blank"
打开目标网页的方式：另起一个页面

title="hello"
当鼠标悬停在标记上时，显示提示语
```

列表
```
无序列表  ul
(unorder  list)

有序列表  ol
(order  list)

列表项  li
(list  item)

<ul>
    <li>三国演义</li>
    <li>水浒传</li>
    <li>西游记</li>
    <li>红楼梦</li>
</ul>
```

行内标记
```
u   b   i   img  a
在网页上，从左到右排列
```

块级标记
```
p    ul    h1   div
独占一整块，默认从上到下排列
```

图片
```
<img  src="图片路径" width="88px" />
(image 图片、source 资源)

一般，宽和高只设置其中一个
另一个，会自动等比例缩放

img 是行内标记

思考：如何让图片可以点击，跳转到别的页面？
把图片嵌套在 a 标记内
```

表格
```
table
表格行  tr  (table  row)
单元格  td  (table  data)

<table border="1" cellspacing="0" cellpadding="8">
    <tr>
        <td>姓名</td>
        <td>年龄</td>
        <td>性别<td>
    </tr>
    <tr>
        <td>小明</td>
        <td>18</td>
        <td>男<td>
    </tr>
</table>

border  边框
cellspacing  单元格之间的空间
```

输入框
```
<input value="hello" />
```

标题  h1~h6
```
<h1>一级标题</h1>
<h3>三级标题</h3>
```

做布局的标记
```
<div>
    嵌套其它标记
</div>
```

按钮
```
<button>我是按钮</button>
```
