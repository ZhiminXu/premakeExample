# premakeExample
## 1 简介
本文讲解如何基于premake5创建一个典型的C++解决方案，该解决方案包含三个项目：
- 一个依赖GLFW动态库的的动态库项目ExampleDll
- 一个依赖ExampleDll动态库的窗口程序APP
- 一个基于Catch的单元测试程序

## 2 你需要准备
- premake5.exe程序，下载地址。
- 一个文本编辑器
- 一个支持C++11的编译器，因为源代码使用了C++11特性
- 一个支持OpenGL 1.1的显卡

## 3 文件的组织结构
首先需要确定整个解决方案中源代码、三方库、二进制等文件的组织结构，本文中的使用的代码结构如下：
 premakeExample/
 |--premake5.lua
 |--prj/ (prj文件夹用于存放生成的整个解决方案与三个项目的配置文件)
 |--build/ 
 |&emsp;|--target/ (目标生成路径)
 |&emsp;|--obj/ （中间文件生成路径）
 |--bin/ (最终生成发布的二进制文件路径)
 |--3rd/ (存放第三方库文件)
 |&emsp;|--Catch (Catch单元测试框架头文件)
 |&emsp;|--glfw （glfw三方库相关文件）