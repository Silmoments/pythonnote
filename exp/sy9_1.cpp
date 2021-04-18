#include<fstream>
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
int main()
{
	int i,j,k=0;
	int a[100]={2,3};
	for(i=3;i<100;i=i+2)
	{   
		for(j=2;j<=i-1;j++)
		if(i%j==0) break; 	
	    if(j>=i) {	 a[k]=i;        k++;  }
	}
	//文本文件 
	fstream outfile("prime1.txt",ios::out);
	if(!outfile)
     {
     	cerr<<"打开文件binary.dat失败"<<endl;
		cerr<<"文件不存在或者文件损坏"<<endl;
		cerr<<"按任意键退出!"<<endl;
		getch();
		exit(1); 
     }
     
    int count=0;
	for(i=0;i<k;i++)                   
    {
        outfile<<setw(6)<<a[i];
        count++;
        if(count%10==0)     outfile<<endl;  
    }
    outfile.close();
    
    fstream infile("prime1.txt",ios::in);
    if(!infile)
     {
     	cerr<<"打开文件binary.dat失败"<<endl;
		cerr<<"文件不存在或者文件损坏"<<endl;
		cerr<<"按任意键退出!"<<endl;
		getch();
		exit(1); 
    }
    for(i=0;i<k;i++)                   
    {
        infile>>a[i];
		cout<<a[i]<<" "; 
    }
    cout<<endl;
    infile.close();

	//二进制文件
	ofstream ofile("prime2.dat",ios::binary);
	if(!ofile)
     {
     	cerr<<"打开文件prime2.dat失败"<<endl;
		cerr<<"文件不存在或者文件损坏"<<endl;
		cerr<<"按任意键退出!"<<endl;
		getch();
		exit(1); 
     }
    for(i=0;i<k;i++)                   
    {
        ofile.write((char*)&a[i],sizeof(a[i])); 
    }
    ofile.close();
    
    ifstream ifile("prime2.dat",ios::binary);
    if(!ifile)
     {
     	cerr<<"打开文件prime2.dat失败"<<endl;
		cerr<<"文件不存在或者文件损坏"<<endl;
		cerr<<"按任意键退出!"<<endl;
		getch();
		exit(1); 
     }
     
    for(i=0;i<k;i++)                   
        ifile.read((char*)&a[i],sizeof(a[i]));  
    ifile.close();
    for(i=0;i<k;i++)  
	cout<<a[i]<<" ";
    return 0;
}
