cmake_minimum_required(VERSION 3.5)

project(STD_DS LANGUAGES C)

add_executable(STD_DS main.c SeqList.h SeqStack.h SeqList.c SeqStack.c SeqQueue.h SeqQueue.c LinkList.h LinkList.c BTree.h BTree.c)
