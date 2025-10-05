<!-- @format -->

# 🧩 Friend System CLI

“你好呀～要做朋友吗？”

> 一个温柔又有点调皮的命令行小世界，由 **Lian** 构筑。💕

---

## 🧱 Build 构建指南

你可以在 **Linux** 或 **Windows** 上轻松编译本项目。  
下面是两种系统的推荐方式～

### 🐧 Linux / macOS

```bash
cd FriendSystemCli
mkdir -p build
gcc main.c     mylib/menu.c     mylib/play.c     mylib/system.c     mylib/friend.c     mylib/output.c     mylib/audit.c     mylib/fileio.c     -o build/friendsystem
```

> 💡 如果系统提示 `gcc: command not found`，请先安装编译器：
>
> ```bash
> sudo apt install build-essential     # Ubuntu / Debian
> sudo pacman -S base-devel            # Arch Linux
> sudo dnf install gcc                 # Fedora
> ```

---

### 🪟 Windows (MinGW / MSYS2)

#### 使用 MinGW 手动编译：

```bash
cd FriendSystemCli
mkdir build
gcc main.c ^
    mylib/menu.c ^
    mylib/play.c ^
    mylib/system.c ^
    mylib/friend.c ^
    mylib/output.c ^
    mylib/audit.c ^
    mylib/fileio.c ^
    -o build\friendsystem.exe
```

---

## 🚀 Run 运行项目

### 🐧 Linux / macOS

```bash
cd build
./friendsystem
```

### 🪟 Windows

```powershell
cd build
.riendsystem.exe
```

> 程序会自动启用 UTF-8 控制台输出，支持中文台词与表情～ 🌈
>
> 如果你看到主菜单，那说明一切正常！

---

## 🧰 Directory Structure 目录结构

```
FriendSystemCli/
├── main.c
├── mylib/
│   ├── menu.c
│   ├── play.c
│   ├── system.c
│   ├── friend.c
│   ├── output.c
│   ├── audit.c
│   ├── fileio.c
│   ├── menu.h
│   ├── friend.h
│   ├── system.h
│   └── ...
└── build/
    ├── data/
    │   └── friends.csv
    ├── log/
    │   └── audit.log
    └── friendsystem(.exe)
```

> 日志、提示、错误信息都被分类储存，方便未来扩展 🎀；

---

## 🧠 Notes

-   所有中文字符串默认使用 **UTF-8 编码**。
-   若出现乱码，请在终端设置编码为 UTF-8 或使用 MSYS2 环境。
-   Windows 下编译时，建议使用 `gcc` 而非 `cl`。
-   后续版本或许将支持：
    -   用户功能；
    -   多语言界面；
    -   日志查看；
    -   彩色输出。

---
