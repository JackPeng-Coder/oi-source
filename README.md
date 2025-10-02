# oi-source 代码库 README

这是一个算法竞赛平台（洛谷等）的个人题解与代码库，按题目来源与难度分目录管理，便于查找、复用与持续练习。

## 目录结构
- 根目录
  - `.gitignore`：忽略 VSCode 配置与编译生成的可执行文件（`*.exe`）
  - `LUOGU/`：按洛谷题目分组的源码目录
    - `D1-RUMEN/`、`D2-PUJI-/`、`D3-PUJI_TIGAO-/`、`D4-PUJI+_TIGAO/`、`D5-TIGAO+_SHENGXUAN-/`、`D6-SHENGXUAN_NOI-/`、`D7-NOI_NOI+_CTSC/` 等
    - 每个目录下以题号命名的 `Pxxxx.cpp` 文件，例如：
      - `LUOGU/D1-RUMEN/P1089.cpp`
      - `LUOGU/D2-PUJI-/P1002.cpp`
    - 目录下文件名前带中括号表示该题目尚未完成或待完善，例如：
      - `LUOGU/D2-PUJI-[40]P1037.cpp`
      - `LUOGU/D2-PUJI-/[0]P14057.cpp`

源码均为独立的可编译 C++ 程序，通常从标准输入读取数据并向标准输出打印答案。