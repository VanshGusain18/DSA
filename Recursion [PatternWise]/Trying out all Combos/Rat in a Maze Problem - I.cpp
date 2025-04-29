class Solution
{
public:
    void func(vector<vector<int>> &maze, vector<string> &res, string &temp, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
            return;

        if (i == n - 1 && j == n - 1)
        {
            res.push_back(temp);
            return;
        }

        maze[i][j] = 0;

        temp.push_back('D');
        func(maze, res, temp, n, i + 1, j);
        temp.pop_back();

        temp.push_back('L');
        func(maze, res, temp, n, i, j - 1);
        temp.pop_back();

        temp.push_back('R');
        func(maze, res, temp, n, i, j + 1);
        temp.pop_back();

        temp.push_back('U');
        func(maze, res, temp, n, i - 1, j);
        temp.pop_back();

        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        string temp;
        vector<string> res;
        int n = maze.size();
        func(maze, res, temp, n, 0, 0);
        return res;
    }
};