# documentclass 

\documentclass[a4paper]{article(book, report, ...)}

\begin{document}

Hello World !  % This is your content

\end{document}

# title

        \documentclass[UTF8]{ctexart}
        \title{你好，world!}
        \author{Liam}
        \date{\today}
        \begin{document}
        \maketitle
        你好，world!
        \end{document}

# List

1. Unordered List
 
        \begin{itemize}
        \item Item.
        \item Another Item.
        \end{itemize}

2. Ordered List

        \begin{enumerate}
        \item Item.
        \item Another Item.
        \end{enumerate}

# Paragraph and section

- \paragraph{} and \subparagraph{}
- \section{} and \subsection{}
- use \tableofcontents to create contents


- \newpage
- \newline  or \\
- \bigskip :空行

> 在report/ctexrep中，还有\chapter{·}；在文档类book/ctexbook中，还定义了\part{·}

# Footnotes

        Hi let me introduce myself\footnote{\label{myfootnote}Hello footnote}.
        ... (later on)
        I'm referring to myself \ref{myfootnote}.


# Table

        \begin{table}[h!]
          \centering
          \caption{Caption for the table.}
          \label{tab:table1}
          \begin{tabular}{l|c||r}
            1 & 2 & 3\\
            \hline
            a & b & c\\
          \end{tabular}
        \end{table}

- \usepackage{booktabs} for a visually better table.
- h (here) — same location
- t (top) — top of page
- b (bottom) — bottom of page
- p (page) — on an extra page
- ! (override) — will force the specified location


> 先写\caption{}再写\label{}

# Images

- \usepackage{graphicx}

        \begin{figure}
        \includegraphics[width=\linewidth]{filename.jpg}
        \includegraphics[scale=0.5]{HardwareInfo}
        \caption{What is it about?}
        \label{fig:whateverlabel}
        \end{figure}

- \includegraphics[width = .8\textwidth]{a.jpg}
这样图片的宽度会被缩放至页面宽度的百分之八十，图片的总高度会按比例缩放。

# Code

1. 

        \begin{verbatim}
        #include <iostream>
        
        int main()
        {
        	std::cout << "hello world!\n";
        	return 0;
        }
        \end{verbatim}

2. including insert code inline, make custom styles code, choose a specific language for code, import code from another file within the same directory.... With this method, you dont use {verbatim}, but include a package package named listings.

        \usepackage{listings}
        \usepackage{color}
        
        \lstdefinestyle{mystyle}{
        keywordstyle=\color{magenta},
        backgroundcolor=\color{yellow},
        commentstyle=\color{green},
        basicstyle=\footnotesize,
        }
        \lstset{style=mystyle}

        \begin{lstlisting}[language=Python]
        print "Hello World!"
        \end{lstlisting}
        \lstinputlisting[language=C++]{hello.cpp} %import a file named hello.cpp in the same directory
        \lstinline{} %inset inline code



# Math

- 使用 $ ... $ 可以插入行内公式，使用 \[ ... \] 可以插入行间公式
- \begin{equation} ...  \end{equation}
- \usepackage{amsmath}

        Einstein 's $E=mc^2$.
        \[ E=mc^2. \]
        \begin{equation}
        E=mc^2.
        E=mc^{2\pi}
        E=log_23
        \end{equation}
        $\sqrt{x}$, $\frac{1}{2}$.
- https://liam.page/2014/09/08/latex-introduction/


# 

##页边距

将纸张的长度设置为 20cm、宽度设置为 15cm、左边距 1cm、右边距 2cm、上边距 3cm、下边距 4cm，导言区

        \usepackage{geometry}
        \geometry{papersize={20cm,15cm}}
        \geometry{left=1cm,right=2cm,top=3cm,bottom=4cm}

##页眉页脚

在页眉左边写上我的名字，中间写上今天的日期，右边写上我的电话；页脚的正中写上页码；页眉和正文之间有一道宽为 0.4pt 的横线分割，可以在导言区加上如下几行：

        \usepackage{fancyhdr}
        \pagestyle{fancy}
        \lhead{\author}
        \chead{\date}
        \rhead{152xxxxxxxx}
        \lfoot{}
        \cfoot{\thepage}
        \rfoot{}
        \renewcommand{\headrulewidth}{0.4pt}
        \renewcommand{\headwidth}{\textwidth}
        \renewcommand{\footrulewidth}{0pt}


## 行间距

- 我们可以通过 setspace 宏包提供的命令来调整行间距。比如在导言区添加如下内容，可以将行距设置为字号的 1.5 倍：

        \usepackage{setspace}
        \onehalfspacing

## 段间距
我们可以通过修改长度 \parskip 的值来调整段间距。例如在导言区添加以下内容

\addtolength{\parskip}{.4em}
则可以在原有的基础上，增加段间距 0.4em。如果需要减小段间距，只需将该数值改为负值即可。
