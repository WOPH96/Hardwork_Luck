#include <iostream>

class PiggyBox
{
private:
    int coin = 0;

public:
    PiggyBox() {}
    PiggyBox(int coin) : coin{coin} {}

    void setCoin(int coin)
    {
        this->coin = coin;
    }
    int getCoin() const
    {
        return coin;
    }
};

template <typename T>
void inner_run(T &&p)
{
    p.setCoin(77);
    std::cout << p.getCoin() << std::endl;
}

template <typename T>
void run(T &&p)
{
    inner_run(std::forward<T>(p)); // l-value 참조인지, r-value참조인지 알아낼 수 있음
}

int main()
{
    PiggyBox box1{0};
    run(box1);
    run(PiggyBox{0});
    return (0);
}