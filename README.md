# premakeExample
## 1 简介
本文讲解如何基于premake5创建一个典型的C++解决方案，该解决方案包含三个项目：
- 一个依赖GLFW动态库的的动态库项目ExampleDll
- 一个依赖ExampleDll动态库的窗口程序APP
- 一个基于Catch的单元测试程序

## 2 你需要准备
- premake5.exe程序
- 一个文本编辑器
- 一个支持C++11的编译器，因为源代码使用了C++11特性
- 一个支持OpenGL 1.1的显卡

## 3 文件的组织结构
首先需要确定整个解决方案中源代码、三方库、二进制等文件的组织结构，本文中的使用的代码结构如下：
> premakeExample/  
> &emsp;|--premake5.lua （premake脚本文件） 
> &emsp;|--prj/ (生成的解决方案与各项目配置文件路径)  
> &emsp;|--build/   
> &emsp;|&emsp;|--target/ (目标生成路径)  
> &emsp;|&emsp;|--obj/ （中间文件生成路径）  
> &emsp;|--bin/ (最终发布的二进制文件路径)  
> &emsp;|--3rd/ (第三方库文件路径)  
> &emsp;|&emsp;|--Catch (Catch单元测试框架头文件路径)  
> &emsp;|&emsp;|--glfw （glfw三方库相关文件路径）  
