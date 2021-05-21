

在源码窗口中的调试指令：

 :Run [args]        运行程序，可带参数 [args]，或沿用上一次运行的参数
 :Arguments {args}  设置下一次运行所用参数

 :Break     在当前行加断点
 :Clear     删除当前行的一个断点

 :Step      = gdb "step" 
 :Over      = gdb "next"
 :Finish    = gdb "finish"
 :Continue  = gdb "continue"
 :Stop      中断程序
