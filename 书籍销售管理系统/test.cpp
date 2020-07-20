/*
 * ch10 ex10-2
 * test.cpp
 *
 *2��ĳ������۸����ڿ���־���鼮������CD��VCD ��DVD���������������Ʒ��
Ϣ�����νṹ��
��1���ڿ���־���ڿ��������п��š��������ڡ��ںš��۸����Ϣ��
��2���鼮�����������ߡ������硢ISBN���۸����Ϣ��
��3������CD ��CD �����ݳ����ࣩ�ߡ������Ŀʱ�䡢�۸����Ϣ��
��4��VCD ��DVD ��Ƭ������Ŀʱ�䡢�۸����Ϣ��
�����Ҫһ���鼮���۹���ϵͳ���ٶ�ÿ����Ʒ����Ϣ����ͨ��ɨ����������ϵͳ��
��ʵ��ϵͳ����ģ�����Ʒ�۸������嵥��ӡ������

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
