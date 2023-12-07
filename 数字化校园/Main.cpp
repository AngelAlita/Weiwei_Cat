#include "bits/stdc++.h"
#include "grlist.h"

using namespace  std;

map<string,int>name_id;
map<int,string>id_name;
int* pre;//ǰ������ ��¼·��


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

//�����ڽӱ�
template<typename Graphl>
Graphl* createGraph(FILE* fid){
    int numVertex, numEdge;
    fscanf(fid, "%d %d", &numVertex, &numEdge);
    Graphl* G = new Graphl(numVertex);
    int u, v, w;
    while (fscanf(fid, "%d %d %d", &u, &v, &w) == 3) {
        G->setEdge(u, v, w);
    }
    return G;
}


Graphl* Init(FILE* fid)
{
    name_id["�������г���"] = 1;
    name_id["С������"] = 2;
    name_id["��������"] = 3;
    name_id["���簲ȫ�ռ�ѧԺ"] = 4;
    name_id["����"] = 5;
    name_id["�ഺ�㳡"] = 6;
    name_id["ͼ���"] = 7;
    name_id["һ��A"] = 8;
    name_id["����"] = 9;
    name_id["�Ŀ�¥"] = 10;
    id_name[1] = "�������г���";
    id_name[2] = "С������";
    id_name[3] = "��������";
    id_name[4] = "���簲ȫ�ռ�ѧԺ";
    id_name[5] = "����";
    id_name[6] = "�ഺ�㳡";
    id_name[7] = "ͼ���";
    id_name[8] = "һ��A";
    id_name[9] = "����";
    id_name[10] = "�Ŀ�¥";
    Graphl* G;
    G = createGraph<Graphl>(fid);
    return G;

}

void description(int id){
    if(id == 1) printf("1.�������г���:����У��Ψһһ�����г��̣��ɽ��������ӡ���װ���ӵ�");
    if(id == 2) printf("2.С�����ţ����ż������ǵ���վ������ѧ����������ʮ�ַ���");
    if(id == 3) printf(" 3.�������У�����������ƷһӦ��ȫ����ӵ�йض�����ѩ���ǵȶ�ҵ���,��ѧ���Ǽ���ϲ���ĵط�" );
    if(id == 4) printf("4.���簲ȫ�ռ�ѧԺ:���簲ȫ�ռ�ѧԺ���ڵأ������Ƽ���");
    if(id == 5) printf("5.���򳡣�ѧ��������������������ᣬ���ʱ�ڶమ�������ͬѧ������ˮ�ĵط�");
    if(id == 6) printf(" 6.�ഺ�㳡���ٰ���ֻ�������ĵط�");
    if(id == 7) printf(" 7.ͼ��ݣ�ѧ��ѧϰ������ĵط����ɽ����鼮");
    if(id == 8) printf(" 8.һ��A���������¥��Ľ�ѧ¥���ɾ����㣬�����������޽���������");
    if(id == 9) printf(" 9.���ţ��ſھۼ��˺ܶ�óԵĵ��̣���ѧʱ��ӵ������ѧ��������");
    if(id == 10) printf(" 10.�Ŀ�¥��������ʷ�Ļ���Ϣ�Ľ�ѧ¥�����˼ѧԺ����ѧԺ�Ⱦ��ڴ˴�");
}


int minVertex(Graph* G, int* D) { // Find min cost vertex
    int i, v = -1;
    // Initialize v to some unvisited vertex
    for (i=0; i<G->n(); i++)
        if (G->getMark(i) == UNVISITED) { v = i; break; }
    for (i++; i<G->n(); i++)  // Now find smallest D value
        if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
            v = i;
    return v;
}

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph* G, int* D, int s) {
    int i, v, w;
    for (i=0; i<G->n(); i++) {      // Process the vertices
        v = minVertex(G, D);
        if (D[v] == INFINITY) return; // Unreachable vertices
        G->setMark(v, VISITED);
        for (w=G->first(v); w<G->n(); w = G->next(v,w))
            if (D[w] > (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
    }
}


int main(int argc, char** argv)
{
    Graphl* G;
    FILE *fid;

    if (argc != 2) {
        cout << "Usage: grdijkl1 <file>\n";
        exit(-1);
    }

    if ((fid = fopen(argv[1], "rt")) == NULL) {
        cout << "Unable to open file |" << argv[1] << "|\n";
        exit(-1);
    }

    G = Init(fid);
    if (G == NULL) {
        cout << "Unable to create graph\n";
        exit(-1);
    }


    while(true){
        menu();
        int input;
        cout<<"��ѡ����Ĳ���:" << endl;
        cin >> input;
        if(input == 1){
            cout << "��������Ҫ��ѯ�ĵص����ƣ�" << endl;
            string place_name;
            cin >> place_name;
            cout << "��ţ�" << name_id[place_name] << endl;
            cout << "���ƣ�" << place_name << endl;
            cout << "��飺" ;
            description(name_id[place_name]);

        }else if(input == 2){
            int D[G->n()];
            for (int i=0; i<G->n(); i++) {// Initialize
                D[i] = INFINITY;
                pre[i] = -1;
            }

            int id1,id2;
            cout << "��Ҫ��ѯ�������ص㣨��ţ�" ;
            cin  >> id1 >> id2;
            D[id1] = 0;
            Dijkstra(G, D, 0);
            cout << D[id2] << endl;

        }else if(input == 3){
            break;
        }
    }

}




