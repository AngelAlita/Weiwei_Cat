#include "bits/stdc++.h"
#include "grlist.h"

using namespace  std;

map<string,int>name_id;
map<int,string>id_name;



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
    name_id["海豚自行车行"] = 1;
    name_id["小西南门"] = 2;
    name_id["华联超市"] = 3;
    name_id["网络安全空间学院"] = 4;
    name_id["网球场"] = 5;
    name_id["青春广场"] = 6;
    name_id["图书馆"] = 7;
    name_id["一教A"] = 8;
    name_id["南门"] = 9;
    name_id["文科楼"] = 10;
    id_name[1] = "海豚自行车行";
    id_name[2] = "小西南门";
    id_name[3] = "华联超市";
    id_name[4] = "网络安全空间学院";
    id_name[5] = "网球场";
    id_name[6] = "青春广场";
    id_name[7] = "图书馆";
    id_name[8] = "一教A";
    id_name[9] = "南门";
    id_name[10] = "文科楼";
}

void jianjie(int id){
    if(id == 1) printf("1.海豚自行车行:川大校内唯一一家自行车铺，可进行修理车子、安装车子等");
    if(id == 2) printf("2.小西南门：出门即是文星地铁站，紧挨学生生活区，十分方便");
    if(id == 3) printf(" 3.华联超市：各种生活用品一应俱全，还拥有关东煮、蜜雪冰城等多家店铺,是学生们极其喜爱的地方" );
    if(id == 4) printf("4.网络安全空间学院:网络安全空间学院所在地，充满科技风");
    if(id == 5) printf("5.网球场：学生们曾多次在这里做核酸，如今时众多爱好网球的同学挥洒汗水的地方");
    if(id == 6) printf(" 6.青春广场：举办各种活动及宣传的地方");
    if(id == 7) printf(" 7.图书馆：学生学习、读书的地方，可借阅书籍");
    if(id == 8) printf(" 8.一教A：具有最高楼层的教学楼，干净方便，并且有最新修建的卫生间");
    if(id == 9) printf(" 9.南门：门口聚集了很多好吃的店铺，放学时间拥有最大的学生流动量");
    if(id == 10) printf(" 10.文科楼：具有历史文化气息的教学楼，马克思学院、法学院等就在此处");
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
        cout<<"请选择你的操作:" << endl;
        cin >> input;
        if(input == 1){
            cout << "请输入您要查询的地点名称：" << endl;
            string place_name;
            cin >> place_name;
            cout << "序号：" << name_id[place_name] << endl;
            cout << "名称：" << place_name << endl;
            cout << "简介：" ;
            jianjie(name_id[place_name]);

        }else if(input == 2){

        }else if(input == 3){
            break;
        }
    }

}




