#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//======================================�ı��ļ���д����

//int main()
//{
//   string name;
//   float score;
//   fstream myfile;//�ļ�������
//   myfile.open("D:\\data\\record.txt",ios::out);
//   if(!myfile){
//    cerr<<"File open or create error!"<<endl;
//    return 0;
//   }
//   while(cin>>name&&name!="exit"){
//    cin>>score;
//    myfile<<name<<" "<<score<<endl;
//
//   }
//   myfile.close();
//}
//==================================�ı��ļ��Ķ�����
int main(){
    string name;
    float score;
    ifstream myFile;
    myFile.open("D:\\data\\record.txt");
    if(!myFile){
        cerr<<"record.txt open error!"<<endl;
        return 0;

    }
    while(!myFile.eof()){
        myFile>>name>>score;
        if(myFile) cout<<name<<"\t"<<score<<endl;

    }
    myFile.close();
}

