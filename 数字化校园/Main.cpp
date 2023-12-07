#include "bits/stdc++.h"
#include "grlist.h"

using namespace  std;

void menu();
void Init();

// 菜单
void menu()
{
    printf("***************************数字化校园***************************\n");
    printf("所有地点:\n");
    printf("1.海豚自行车行 2.小西南门 3.华联超市 4.网络安全空间学院 5.网球场 6.青春广场 7.图书馆 8.一教A 9.南门 10.文科楼\n");
    printf("1.查询地点\n");
    printf("2.两个地点之间的最短距离\n");
    printf("3.退出\n");
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
        cout<<"请选择你的操作:";
        cin >> input;
        if(input == 1){

        }else if(input == 2){

        }else if(input == 3){
            break;
        }
    }

}




