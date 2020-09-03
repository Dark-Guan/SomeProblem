#include <stdio.h>

int func(int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum+=i;
    }
    return sum;
}


int main(){
    int i;
    long result=0;
    for(i =0;i<=100;i++){
        result +=i;
    }
    printf("result[1-100]=%d\n",result);
    printf("result[1-250]=%d\n",func(250));
    return 0;
}

/*
gcc -g gdb_test.c -o test // 编译时加上 -g 选项
list or | 列出代码
break 16 在16行处设置断点
break func 在func 处设置断点
info break 查看断点信息
r 运行程序， run 的简写
n next 吓一条指令
c continue 程序继续运行
p i print i 的简写
bt backtrace 查看函数堆栈
finish 退出函数
q qort 退出调试

启动 gdb的方法；
gdb <program>
gdb <program> core // core 是程序执行后的 coredump后产生的文件
gdb <program> <PID> // PID 制定函数的进程ID，gdb会自动attach 上去，program 应该在 <PATH>环境中搜索到；

-symbol <file>
-s <file>
从指定文件获取符号表
-se <file> 从制定文件读取符号表，并把它应用在可执行文件当中；

-core <file> 
-c <file>
调试是 coredump 的 core 文件；

-directory <directory> 
-d <directory> 
加入一个源文件的搜索路径，默认路径是<path> 所定义的路径；

gdb -help 查看帮助

gdb 开启之后 用 help 查看可用命名

help <class> 查看一类命令
help <command> 查看命令

b 'func 加两次tab键，可以显示其他和func同名的重载函数；

在gdb中运行 shell 程序 shell <command-string>
make <make-args>可以运行make程序；

1. set args 设置程序参数; show args 显示程序参数
2. path <dir> 设置程序运行路径 show paths; set
environment varname [=name] 设置环境变量；如: set env USER=hchen show environment [varname] 查看环境变量；

3. 工作目录 cd <dir> pwd 和 shell 中一样

4.info terminal，显示终点
run > outfile 重定向
tty tty /dev/ttyb 制定输入输出终端设备；

调试已经在运行的程序
ps 查看 进程ID；（PID）在gdb中用 attach 命令来挂接进程PID，并用detach 来取消挂接进程 

gdb 程序的暂停方式； breakpoint watchpoint catchpoint signals， thread stops , 恢复用 c 或者 continue
info program 查看程序是否在运行，如果退出，说明退出的原因；

break filename：func
break filename：linenumber
break 

break if <condition> 如 break if i=100

break 没有参数表示在下一条指令停止
break *address 在程序运行的内存地址出停止

info breakpoint [n]
info break [n]

watch <expr> 表达式值变化是停止程序
rwatch <expr> 表达上被读是停止程序
awatch <expr> 表达式被读或者被写的时候停止程序；

ifno watchpoints 查看观察点

catch <event> 当event 发生是 停止
<event> 可以是 throw 抛出异常 catch 捕捉异常；

tcathc <event>只设置一次捕捉点，发送之后停止；

停止维护点：
clear  清除所有
clear <function>
clear <filename.function>
clear <linenum>
clear <filename.linenum>

delete [breakpoint][range] 简写 d 无参数删除所有 
disable [breakpoint][range] 简写 dis 无参数全部禁止

enable [breakpoint] once range.. 停一次
enable [breakpinnt] delete range.. 停一次然后删除

condition <brnum> <expr> 修改断点的停止条件为 <expr>
condition <brnum> 停止所有条件
ignore <brnum> <count> 忽略断点号多少次；

自动化调试
commands [brum]
.. commmand-list ..
end
当断点触发是，gdb会运行其中的命令；
break foo if x>0
commands
printf "x is %d",x
continue
end

b String::after C++ 的重载函数比较多，gdb 会给出列表选择

c [ignore-count] [ignore-count] 有值表示忽略几次中断；
continue [ignore-count]
fg [ignore-count]

step [count] [count] 缺失为下一条，有值表示执行后面几个指令
next [count]
set step-mode
set step-mode on 没有debug信息也停住程序，方便查看机器码
set step-mode off

finish

u util 退出循环体

stepi si
nesti ni
display/i $pc 
查看汇编代码

signals 信号是一种软中断

handle <sig> <keyword> 单个 SIGKILL 或者范围 SIGIO-SIGKILL 也可以是关键词 all
keyworks 包含多个或一个 nostop stop print noprint pass noignore(交个程序处理) nopass ignore （不交给程序处理）

break <linespec> thread <threadno>
ifno threads 可以查看线程；
如果没有 <threadno> 将绑定到全部的线程

如(gdb) break frik.c:13 thread 28 if bartab > lim

查看栈信息 
backtrace bt 

backtrace <n> 打印 n 层栈

frame <n>
f <n>
切换当前栈；
up <n> down <n> 


搜索源代码：
forward-search <regexp>
search <regexp>
reverse-search <regexp>

制定源文件的路径
directory <dirname>
dir <dirname>
show directories

查看源代码对于汇编
print <expr>
print /<f> <expr>

f制定格式 /x十六进制

print 
print *array@len 打印数字array 全部的内容

查看内存
x/<n/f/u> <address>
examine/<n/f/u> <address>

如 x/3uh 

*/