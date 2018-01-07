class Box {
    public:
        Box(bool coin1, bool coin2);
        bool pick_coin(void);
    private:
        bool coin1, coin2;  // gold is true, silver is false
        bool picked1, picked2;
};