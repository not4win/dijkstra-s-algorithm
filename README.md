# dijkstra-s-algorithm
# Dijkstra’s Algorithm made easy :D

Hey There !
Imagine that you’re traveling to N cities and what if you want save some time and fuel? You have to calculate the shortest distance to that city. Don’t worry,a Dutch scientist, Dijkstra, has discovered a trick to make your life easier. ;) It’s called Dijkstra’s Algorithm.
This is a very important algorithm that will boost up your __competitive coding skills__ and also help you __face your interview__ may be. :P

# What is this Dijkstra’s algorithm?

__Dijkstra’s algorithm__ is an __algorithm__ for finding the shortest paths between nodes in a graph, which may represent, for example, road maps. It was derived by a computer scientist __Edsger W. Dijkstra__ in __1956.__

The best example to depict the application of Dijkstra’s algorithm is Google Maps. It gives you number of ways from one destination to the other. But, it primarily focuses on the shortest path between the 2 places.
# The algorithm
Following are the steps of Dijkstra’s algorithm:
* We assume that all the nodes are unvisited and all the nodes are at infinite distance from starting node.
* Choose the node which is closest to chosen starting node, say node ‘ i ’ and mark it as visited.
* Update the distance of all the node adjacent to ‘ i ‘, if the path is shorter than the present distance.

Now let’s see the algorithm __step by step:__
* Take a boolean array spt[] and initialize all the elements to 0 (0 = unvisited, 1 = visited)
* Create an array v[ ], which holds the distance of the nodes from starting node and initialize it to infinity (INT_MAX)
* Equate v[starting node] to 0 (because shortest distance to node from itself is 0)
* Pick the node which is not visited and is at the minimum distance from starting node(unvisited and smallest in v[ ]), say node ‘ u ‘ and mark it as visited (spt[u]=1).
* Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices.
* For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.

**Example:**

![alt text](https://github.com/samyuktaprabhu/dijkstra-s-algorithm/blob/master/img1.png)

If you have to travel from say node 0 to 8, you have several options(paths) to choose from.
* One way is 0–1–6–7–8. In this case, The distance is 3+4+1+5=13 units.
* Another way is 0–4–2–3–8. The distance is 10+6+2+2=20 units.
* Another way may be 0–4–5–3–8. The distance is 10+3+5+2=20 units again.
* May be next way is 0–1–5–6–7–8. The distance is 3+3+1+1+5=13 units.
* And so on…

There are several pathways that you can choose. Now, this was a very simple example. But now, what if you have a very very complicated network?This is the point where the concept of Dijkstra’s algorithm comes into picture.
Ok, So far so cool
Great! Let’s continue. Moving further, have a look at the graph above closely once again.
You can see all the nodes are marked red, which means they are not visited. We will mark the nodes with green color as we visit them. Let’s begin then.

We choose node 0 as starting node, equating v[0] to 0, mark 0 as visited, node 1 and 4 are adjacent to node 0 at distance of 3 and 10 respectively. This is how the partial graph looks like.

![alt text](https://github.com/samyuktaprabhu/dijkstra-s-algorithm/blob/master/img2.png)

**NOTE**: **‘in'** in the image stands for infinity i.e. we are initializing all the distances to infinity initially.

Now among node 1 and 4, since node 1 is closer to node 0, we visit node 1. Mark node 1 as visited, Now this is the important part, the distance between node 1 and node 0 is 3 but here we are not calculating the distance between a nodes adjacent to each other, we are trying to find out the shortest path from node 0 (starting node). Nodes adjacent to node 1 are 0,5,6.
Distance from 0 to 0 via 1 is 3+3=6 but we already have calculated the distance between 0 to 0 as 0 we will not update v[0], where as node 5 is at 3+3=6 units and node 6 is at 3+4=7 units away from node 0, Obviously this value is less than infinity so we update v[5] as 6 and v[6] as 7 units.

![alt text](https://github.com/samyuktaprabhu/dijkstra-s-algorithm/blob/master/img3.png)


Similarly, the next part of the graph goes this way.
And finally when you complete visiting all the nodes data structure, graph looks like this.
Further, we have the code explained in parts. In the end, you can find the entire code as one single piece.
Primary part of writing a code is to import libraries to use functions that would make the code more simplified.
So, this part of the code is all about importing libraries:
```
#include <iostream>
using namespace std;
```
The next snippet of the code does the following:
The first line takes a two dimensional array ‘a[][]’ as the matrix input.
Next line uses 1D array ‘v[]’ to keep track distance of the each visited node from selected node.
Then we set it to infinity in the beginning and 1D array ‘spt[]’ is a boolean array (value is 1 if visited. Else value is 0). All these variables are declared globally only for simplicity.
```
int a[100][100];
int v[100];
int spt[100]={0};
int n;
```
This is a function to pick the unvisited node with minimum distance from selected node.
```
int pick(){
int i=0;
int mini=0;
while(spt[mini]!=0)
mini++;
for(i=0;i<n;i++)
if(spt[i]==0 && v[i]<v[mini])
mini=i;
return mini;
}
```
The next one, is a function, which finds the shortest path from selected node and all the nodes adjacent to user picked node and equate v[that node] to the obtained shortest path.
This function can be recursive.
```
void compute(){
int i=pick();
spt[i]=1;
int j;
for(j=0;j<n;j++)
if(a[i][j]!=0 && v[j]>(a[i][j]+v[i]))
v[j]=a[i][j]+v[i];
return;
}
```
The next part of the code is the main program where in all the functions are called. They are self explanatory. Comments are also added in between.
```
int main()
{
int start;
cout<<”Enter the Dimension :”;
cin>>n;
int i,j;
# Enter the matrix of the path and its weights
cout<<”Enter the values in the matrix”;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>a[i][j];
#enter the start node of your choice
cout<<”Enter the starting node”;
cin>>start;
#Initializing the initial distances to maximum or ‘infinity’
for(i=0;i<n;i++)
v[i]=INT_MAX;
v[start]=0;
#computing the shortest path
for(i=0;i<n;i++)
compute();
cout<<endl<<”shortest_path_from_start_node_is”<<endl;
#outputs the shortest path
for(i=0;i<n;i++)
cout<<v[i]<<endl;
return 0;
}
```
That’s it, easy-peasy.
Refer the dijkstra.py file for the entire code.

Moving further, following are some points chalked down, to have a better theoretical knowledge of the algorithm.

* The code can be used for undirected graph as well as directed graphs. Directed graphs are the ones in which there is a particular direction in which one can go from node to the other. In short, the link between 2 nodes are uni-directional and not bi-directional.
* Time complexity of the code is O( v² )
* Time complexity can be reduced to O(e log v), using adjacency list representation.
* Drawback of Dijkstra’s algorithm is, it cannot be used for negative weights. It has to be used for non-negative weights only. To overcome this, we have something called Bellman-Ford algorithm. It is slower than Dijkstra’s algorithm, but more versatile, as it is capable of handling graphs in which some of the edge weights are negative numbers.

__— Written by Aditya Shenoy and Samyuktha Prabhu :)__
