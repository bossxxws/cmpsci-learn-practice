% 创建一个有权图的邻接矩阵


% 创建一个有向图
      s = [1 1 1 2 2 3];
      t = [2 3 4 5 6 7];
weights = [3 5 2 4 1 6]; % 假设这是边的权重

%  记录是否是空程
    st = zeros(6, 6);
    st(3,2)=1;%1表示是空程

G = digraph(s, t, weights);
% 生成加权邻接矩阵
A = adjacency(G, weights);

% 设置阈值 N
N = 10; 
res=1e9;
dfs(A,1,N,st,res);

% 实现 DFS 回溯算法
function dfs(adjMatrix, startNode, N,st,res)

    n = size(adjMatrix, 1);
    visited = false(1, n);
    path = [];
    dfsHelper(startNode, 0,0);
    disp(res);
    function dfsHelper(node, weight,dis,st,res)
        visited(node) = true;
        path = [path, node];
        
        if weight == N
            if dis<res
                res=dis;
            end
            return;
        end
        
        for i = 1:n
            if adjMatrix(node, i) > 0 && ~visited(i)
                if st(node,i)<1%实线情况
                    dfsHelper(i, weight + adjMatrix(node, i),dis+adjMatrix(node,i));
                else %空程情况
                    dfsHelper(i, weight,dis+adjMatrix(node,i));
                end
            end
        end
        
        visited(node) = false;
        path = path(1:end-1);
    end
end
