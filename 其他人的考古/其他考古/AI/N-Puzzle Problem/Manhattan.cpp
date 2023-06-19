#include<bits/stdc++.h>
#include <chrono>
#include <ctime>
#define dbg printf("in\n")
#define nl printf("\n")
#define pp pair<int,int>

#define threshold_sz 6*1e7 

using namespace std;

class node
{
public:
    int board[4][4], n;
    int zx, zy;

    node() {}

    node(int n)
    {
        this->n = n;
    }

    void assignNodeValue(node other)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                board[i][j] = other.board[i][j];
        }
    }

    bool operator==(const node &other) const
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != other.board[i][j])
                    return false;
            }
        }

        return true;
    }

    bool operator<(const node &other) const
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] < other.board[i][j])
                    return true;
                else if (board[i][j] == other.board[i][j])
                    continue;
                else
                    return false;
            }
        }

        return false;
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
					printf("%4d", board[i][j]);		
            printf("\n");
        }

        printf("----------\n\n");
    }
};

int manhattanDist(node u, node g)
{
    int cnt = 0;

    vector <pp> gl(u.n * u.n), self(u.n * u.n);

    for (int i = 0; i < u.n; i++)
    {
        for (int j = 0; j < u.n; j++)
        {
            gl[g.board[i][j]] = {i, j};
            self[u.board[i][j]] = {i, j};
        }
    }

    for (int i = 1; i < self.size(); i++)
        cnt += (abs(self[i].first - gl[i].first) + abs(self[i].second - gl[i].second));

    return cnt;
}

int getHeuristicValue(int type, node u, node g)
{
    return manhattanDist(u, g);
}

bool inside(int r, int c, int n)
{
    if (r >= 0 && c >= 0 && r < n && c < n)
        return true;
    return false;
}

map<node, bool> closedList;
map<node, int> cost;
map <node, node> parent;

int explored, overflown;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void clr()
{
    explored=0;
    closedList.clear();
    cost.clear();
    parent.clear();
}

void A_Star(node startNode, node goalNode, int h)
{
    int x, y, ucost, pcost, hcost;
    priority_queue <pair<int, node>> openList;

    openList.push({0, startNode});

    node dummyParent(0);
    parent[startNode] = dummyParent;
    cost[startNode] = 0;
    explored++;

    while (!openList.empty())
    {
        if(openList.size() >= threshold_sz || closedList.size() >= threshold_sz)
        {
            overflown = 1;
            while(openList.size())
                openList.pop();

            return;
        }

        //node having the lowest "f"
        node u = openList.top().second;

        //remove current from open-list and add to closed-list
        openList.pop();
        closedList[u] = true;
        ucost = cost[u];

        //goal reached
        if (u == goalNode)
            break;

        //traverse the neighbors
        for (int i = 0; i < 4; i++)
        {
            x = u.zx + dx[i];
            y = u.zy + dy[i];

            if (inside(x, y, u.n))
            {
                node newNode(u.n);
                newNode.assignNodeValue(u);
                newNode.zx = x;
                newNode.zy = y;

                swap(newNode.board[x][y], newNode.board[u.zx][u.zy]);

                //if in closed-list then done
                if (closedList[newNode])
                    continue;

                hcost = getHeuristicValue(h, newNode, goalNode);
                pcost = ucost + 1 + hcost;

                //if 0 then a new node has been discovered, else is in the queue already
                //so we push if a better cost is acquired
                if (cost[newNode] == 0 || cost[newNode] > ucost + 1)
                {
                    parent[newNode] = u;
                    cost[newNode] = ucost + 1;
                    openList.push({-pcost, newNode});
                    explored++;
                }
            }
        }
    }

    while(openList.size())
        openList.pop();
}

struct timespec diff(struct timespec start, struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);

    int i, j, k;
    int n, m;
    vector <node> path;

    while (1)
    {
        scanf("%d", &n);

        if (n < 3 || n > 4)
            break;

        node startNode(n);
        node goalNode(n);
        node tempNode;

        k = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                goalNode.board[i][j] = k++;
                scanf("%d", &startNode.board[i][j]);
                if (startNode.board[i][j] == 15)
                    startNode.zx = i, startNode.zy = j;
            }
        }
		goalNode.print(); 
		
            clr(); path.clear(); overflown = 0;
            printf("---------------------------------------\n");
            cout<<"heuristic : Manhattan"<<endl;
			struct timespec start, end;
 			double time_used;
  			clock_gettime(CLOCK_MONOTONIC, &start);
  			
            A_Star(startNode, goalNode, 1);
            
			clock_gettime(CLOCK_MONOTONIC, &end);
  			struct timespec temp = diff(start, end); // 計算實際花費時間
 			time_used = temp.tv_sec + (double) temp.tv_nsec / 1000000000.0;

            tempNode=goalNode;
            while (tempNode.n)
            {
                path.push_back(tempNode);
                tempNode = parent[tempNode];
            }

            reverse(path.begin(), path.end());

            for (node p : path)
                p.print();

            printf("analysis--->\n");
            printf("cost : %d\n",path.size()-1);
            printf("nodes expanded : %d\n",closedList.size());
            printf("nodes explored: %d\n",explored);
            cout<<"所花費時間為: "<<time_used<<"s"<<endl<<endl;
            printf("---------------------------------------\n");
    }

    return 0;
}
