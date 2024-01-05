using namespace std;

long long solution(int price, int money, int count)
{
    long long total = (long long)price * count * (count + 1) / 2;
    return total <= money ? 0 : total - money;
}