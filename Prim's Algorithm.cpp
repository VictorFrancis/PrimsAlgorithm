#include<iostream>
#include<cstdlib>

#define WHITE 0 //not visited
#define BLACK 1 //visited
#define INF -1

using namespace std;

void create_nodes(int nodes, int** &edges, int* &parents, int* &colors){

    edges=new int*[nodes];
    parents=new int[nodes];
    colors=new int[nodes];

}

void populate_nodes(int nodes, int** &edges, int* &parents, int* &colors, int high, int low){

    for(int i=0; i<nodes; i++){
        edges[i]=new int[nodes];
        for(int j=0; j<nodes; j++){
            if(i!=j){
                edges[i][j]=low+rand()%(high-low+1);
                parents[i]=i;
                colors[i]= WHITE;
            }

            else{
                edges[i][j]=0;

            }

        }

    }


    }

void display_graph(int nodes, int** edges){

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

}
//This function finds the vertex with the minimum key value
//from the set of vertices not in MST
int minValue(int nodes, int* minWeightOfEdges, int* nonMstList){

    int minValue=INF;
    int minIndex;

    for(int i=0; i<nodes; i++){
        //nonMSTList is not visited && minWeightOfEdges is less than min Value
        if(nonMstList[i]==WHITE && minWeightOfEdges[i]<minValue){

            //update minValue with minWeightofEdges[i]
            minValue=minWeightOfEdges[i];
            minIndex=i;

        }
    }

    return minIndex;

}

void display_MST(int* parent,int nodes, int** edges){

        cout<<"Edge: "<<"Weight: "<<endl;

        for(int i=0; i<nodes; i++){
            cout<<"Edge: "<<parent[i]<<" -> "<<i<<"Weight: "<<edges[i][parent[i]];
        }

    }

void create_MST(int start,int nodes, int** edges, int* parent, int* colors,
                int* nonMstList, int* minWeightOfEdges){

    //set of vertices not in MST list yet
    nonMstList=new int[nodes];

    //used to pick the minimum weight edge
    minWeightOfEdges=new int[nodes];

    //storing constructed MST
    int minIndex;

    for(int i=start; i<nodes; i++){

        //all minWeight to INF
        minWeightOfEdges[i]=INF;

        //marking the all the vertices not in MST
        nonMstList[i]=WHITE;

        //including the first vertex in MST, by making it 0, so it is picked first
        //first node is always root of MST
        minWeightOfEdges[0]=0;
        parent[0]=INF;

        }

    for(int i=start; i<nodes-1; i++){

        //picking the minimum index
        //from set of vertices not in MST list
        minIndex=minValue(nodes,minWeightOfEdges,nonMstList);

        //marking the picked index to visited
        nonMstList[minIndex]=BLACK;

        }

    for(int i=start; i<nodes; i++){
            //updating minWeightOfEdges and parent index of vertices of the picked node
            //considering vertices that are not in MST yet
        if(edges[minIndex][i] && nonMstList[i]==WHITE && edges[minIndex][i]<minWeightOfEdges[i]){

            //updating minWeightOfEdges when edge[minIndex][v] is smaller than minWeightOfEdges
            //nonMSTList is WHITE for vertices not yet in MST
            //edge[minIndex] is non zero for adjacent vertices
            parent[i]=minIndex;
            minWeightOfEdges[i]=edges[minIndex][i];

            }
        }

        display_MST(parent,nodes,edges);


        }


int main(){

    int nodes;
    int high,low;

    cout<<"Enter number of nodes: ";
    cin>>nodes;
    cout<<"Enter range high, low: ";
    cin>>high>>low;
    cout<<endl;

    int **edges;
    int *parents;
    int *colors;

    create_nodes(nodes,edges,parents,colors);
    populate_nodes(nodes,edges,parents,colors,high,low);
    display_graph(nodes,edges);

    int startNode;
    cout<<"Enter Starting Node: ";
    cin>>startNode;
    cout<<endl;

    int *nonMstList;
    int *minWeightOfEdges;

    create_MST(startNode,nodes,edges,parents,colors,
               nonMstList,minWeightOfEdges);

    return 0;

    //n=number of nodes
    //Time Complexity = (n^2)+(n^2)+[n+(n-1)]+n+n
    //                = (n^2)+5n-1

}
