/*
 * ch10 ex10-2
 * test.cpp
 *
 *2．某书店销售各种期刊杂志、书籍、音乐CD、VCD 和DVD。设计描述各种商品信
息的类层次结构：
（1）期刊杂志有期刊名、发行刊号、发行周期、期号、价格等信息；
（2）书籍有书名、作者、出版社、ISBN、价格等信息；
（3）音乐CD 有CD 名、演唱（奏）者、风格、曲目时间、价格等信息；
（4）VCD 和DVD 有片名、曲目时间、价格等信息。
书店需要一个书籍销售管理系统，假定每件商品的信息可以通过扫描条码输入系统，
请实现系统结账模块的商品价格计算和清单打印操作。

 */
#include <iostream>
#include "goods.h"
#include "cart.h"
using namespace std;

int main()
{
	Cart ct;
	Goods* gs[] = {
			new MusicCD("Eagles",12),
			new Video("Email",23),
			new Book("The DaVinci Code",22),
			new Magazine("Reader",5)
	};
	for(int i=0; i<4; i++)
		ct.addItem(gs[i]);
	cout<<ct.goodsList()<<endl;
	cout<<"Total Price: "<<ct.totalPrice()<<endl;
	for(int i=0; i<4; i++)
		delete gs[i];
}
