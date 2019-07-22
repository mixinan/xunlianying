# web基础 - Day03 

## CSS定位
```
属性：position
取值：relative  absolute  fixed
      相对        绝对     固定
```
相对定位：
以元素本来的位置作为参照
```css
positon: relative;
top: 10px;
left: 20px;

从左边挪动20px，从上边挪动10px
```

固定定位：
以屏幕为基准，设置元素的位置
```css
position: fixed;
bottom: 0;
right: 0;

距离底部 0
距离右边 0
在屏幕的右下角
```

练习
```css
在页面上有4个div
宽、高都是100px，不同的背景颜色
分别显示在页面左上角、右上角、左下角、右下角
```

绝对定位：找到上层有“定位方式”的元素，以该元素为基准，设置自身的定位。如果上层元素都没有定位方式，则以 body 为基准
```
position: absolute;
top: 10px;
left: 20px;
```

html:
```
<div id="parent">
    <div  id="son"></div>
</div>
```
css:
```
#parent{
    width: 200px;
    height: 200px;
    background: aquamarine;
    margin-left: 55px;
    margin-top: 88px;
    position: relative;   /*加上定位方式*/
 }

#son{
    width: 100px;
    height: 100px;
    background: red;
    position: absolute;
    top: 10px;
    left: 8px;
 }
```

设置标记的显示、隐藏
```
属性：display
取值：block(默认)、none、flex

#app{
    width: 100px;
    height: 100px;
    display: none;
    background: red;
}
```

把列表设置为横向显示
```
给ul设置
display: flex;
```

与悬停状态的结合使用
```
li>ul {
    display: none;
}

li:hover>ul {
    display: block;
}
```

关键帧动画
```html
@keyframes donghua {
    0%{
        height: 36px;
        color: blue;
        margin-top: 0;
    }
    50%{
        height: 88px;
        margin-top: 50px;
    }
    100%{
        height: 40px;
        color: yellow;
        margin-top: 30px;
    }
}


#app{
    animation: donghua 2s infinite alternate;
}

关键帧名字   播放一次的时间  播放次数   是否轮流反向播放
```
