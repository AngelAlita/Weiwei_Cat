#include "bits/stdc++.h"
#include "grlist.h"

using namespace  std;

void menu();
void Init();

// �˵�
void menu()
{
    printf("***************************���ֻ�У԰***************************\n");
    printf("���еص�:\n");
    printf("1.�������г��� 2.С������ 3.�������� 4.���簲ȫ�ռ�ѧԺ 5.���� 6.�ഺ�㳡 7.ͼ��� 8.һ��A 9.���� 10.�Ŀ�¥\n");
    printf("1.��ѯ�ص�\n");
    printf("2.�����ص�֮�����̾���\n");
    printf("3.�˳�\n");
}

void Init()
{

}
int main(int argc, char** argv)
{
    Graph* G;
    FILE *fid;

    if (argc != 2) {
        cout << "Usage: grdijkl1 <file>\n";
        exit(-1);
    }

    if ((fid = fopen(argv[1], "rt")) == NULL) {
        cout << "Unable to open file |" << argv[1] << "|\n";
        exit(-1);
    }

    Init();
    while(true){
        menu();
        int input;
        cout<<"��ѡ����Ĳ���:";
        cin >> input;
        if(input == 1){

        }else if(input == 2){

        }else if(input == 3){
            break;
        }
    }

}




