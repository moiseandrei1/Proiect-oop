class linii{
    static int test;

public:
    static void dublare()
    {
        test = test * 2;
    }
        private:
        std::pair <int, int> p[11][6];
        public:
        std::pair<int, int> getnext(int a, int b)
        {
            return p[a][b];
        }
        void generarelinii()
        {
            for(int i = 1; i <= 3; i ++)
                for(int j = 1; j <= 5; j ++)
                    p[i][j] = std::make_pair(i, j);
            p[4][1] = std::make_pair(1, 1);
            p[4][2] = std::make_pair(2, 2);
            p[4][3] = std::make_pair(3, 3);
            p[4][4] = std::make_pair(2, 4);
            p[4][5] = std::make_pair(1, 5);

            p[5][1] = std::make_pair(3, 1);
            p[5][2] = std::make_pair(2, 2);
            p[5][3] = std::make_pair(1, 3);
            p[5][4] = std::make_pair(2, 4);
            p[5][5] = std::make_pair(3, 5);

            p[6][1] = std::make_pair(1, 1);
            p[6][2] = std::make_pair(1, 2);
            p[6][3] = std::make_pair(2, 3);
            p[6][4] = std::make_pair(3, 4);
            p[6][5] = std::make_pair(4, 5);

            p[7][1] = std::make_pair(3, 1);
            p[7][2] = std::make_pair(3, 2);
            p[7][3] = std::make_pair(2, 3);
            p[7][4] = std::make_pair(1, 4);
            p[7][5] = std::make_pair(1, 5);

            p[8][1] = std::make_pair(2, 1);
            p[8][2] = std::make_pair(1, 2);
            p[8][3] = std::make_pair(1, 3);
            p[8][4] = std::make_pair(1, 4);
            p[8][5] = std::make_pair(2, 5);

            p[9][1] = std::make_pair(2, 1);
            p[9][2] = std::make_pair(3, 2);
            p[9][3] = std::make_pair(3, 3);
            p[9][4] = std::make_pair(3, 4);
            p[9][5] = std::make_pair(2, 5);

            p[10][1] = std::make_pair(1, 1);
            p[10][2] = std::make_pair(2, 2);
            p[10][3] = std::make_pair(2, 3);
            p[10][4] = std::make_pair(2, 4);
            p[10][5] = std::make_pair(1, 5);
        }
};