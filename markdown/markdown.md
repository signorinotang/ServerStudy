MarkDown学习笔记
====  
1.关于MarkDown 
----
* 它基于纯文本，方便修改和共享  
* 几乎可以在所有的文本编辑器中编写  
* 很容易转换为 HTML 文档或其他格式
* 适合用来编写文档、记录笔记、撰写文章  

2.MarkDown基本用法
----  
2.1 段落  
* 空行  
* 加入\<br\>
* 前一行末尾加入至少2个空格  

2.2 标题  
* T1<br>====
* T2<br>----
* ####T3#### 对称的若干#号
* ####T4     只有左边#号  
T3 T4 两侧需空格  

2.3 引用  
* 每行前面加上\>
* 可以嵌套引用\>\>

2.4 列表
* 可以使用\* \+ \-作为标记
* 无序列表项的开始是：符号 空格
* 有序列表项的开始是：数字 . 空格

2.5 代码
* 使用一对\`插入代码行
* 使用一对```插入整段代码 在后面跟上代码类型 如js c++ 具体请看3.2

2.6 分割线
* 三种分割线 在一行中使用3个或者更多的  ***   ----  ____
* 多个字符之间可以有空格  但是不能有其他字符

2.7 超链接

>这里顺便用到了列表 *前加2个空格 可以进行缩进形成如下格式
* 2.7.1 行内式  
  * 格式为\[link text\](URL "title text")
  * 普通链接\[Google\](http://www.google.com/)
  * 本地链接\[MarkDown\](./MarkDown.md)
  * 包含title的链接 \[Google\](http://www.google.com/ "Google") （个人理解 title的作用就是说明 标记 没发现在链接中有什么用）
  * 图片一样只是多个叹号 \!\[GitHub](https://avatars2.githubusercontent.com/u/3265208?v=3&s=100 "GitHub,Social Coding")
* 2.7.2 参考式
  * 先定义链接内容\[link\]: http://www.google.com/ "Google"
  * 定义链接\[Google\]\[link\]
  * 也可以省略 识别符，使用链接文本作为 识别符 \[Google\][]         [Google]: http://www.google.com/ "Google"
  * 图片一样只是多个叹号 \!\[GitHub][github]          [github]: https://avatars2.githubusercontent.com/u/3265208?v=3&s=100 "GitHub,Social Coding" 
>参考式相对于行内式有一个明显的优点，就是可以在多个不同的位置引用同一个 URL 如全文都可以写\[Google\]\[link\]

2.8 斜体 粗体
* 使用 \*内容\* 或者 \_内容\_包括的文本会变为斜体 
* 使用 \*\*内容\*\* 或者 \_\_内容\_\_包括的文本会变为粗体
* 中间不允许出现空格 必须成对使用 

2.9 转译 
* 特殊字符 需要用\转译输出

3.扩展语法
----
3.1 删除线
* 被波浪线\~\~内容\~\~包括的会被删除线

3.2 代码块语法高亮
* 三个 ``` 要独占一行
* 在上面的代码块语法基础上，在第一组 ``` 之后添加代码的语言，如 'javascript' 或 'js'，即可将代码标记为 JavaScript

3.3 表格
* 使用 | 来分隔不同的单元格，使用 - 来分隔表头和其他行
```
name | age
---- | ---
LearnShare | 12
Mike |  32

```


参考文档 [MarkDown](http://xianbai.me/learn-md/article/about/readme.html)  
编辑器推荐 [VisualStudioCode](https://code.visualstudio.com/)  

