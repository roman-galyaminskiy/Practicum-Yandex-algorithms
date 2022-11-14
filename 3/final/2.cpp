// Отчет: https://contest.yandex.ru/contest/23815/run-report/74165628/

#include <iostream>
#include <vector>

class Participant {
public:
    Participant(std::string name, int solved, int penalty) {
        this->name = name;
        this->solved = solved;
        this->penalty = penalty;
    }
    
private:
    std::string name;
    int solved;
    int penalty;

friend bool operator== (const Participant& p1, const Participant& p2);
friend bool operator< (const Participant& p1, const Participant& p2);
friend std::ostream& operator<<(std::ostream& os, const Participant& p);
};

bool operator== (const Participant& p1, const Participant& p2)
{
    return p1.name == p2.name &&
        p1.solved == p2.solved &&
        p1.penalty == p2.penalty;
}

// При сравнении двух участников выше будет идти тот, у которого решено больше задач. 
// При равенстве числа решённых задач первым идёт участник с меньшим штрафом. 
// Если же и штрафы совпадают, то первым будет тот, у которого логин идёт раньше в 
// алфавитном (лексикографическом) порядке.
bool operator< (const Participant& p1, const Participant& p2)
{
    return !(p1 == p2) && (p1.solved < p2.solved ||
        (p1.solved == p2.solved && p1.penalty > p2.penalty) ||
        (p1.solved == p2.solved && p1.penalty == p2.penalty && p1.name > p2.name));
}

std::ostream& operator<<(std::ostream& os, const Participant& p)
{
    os << p.name; // << ' ' << p.solved << ' ' << p.penalty;
    return os;
}

size_t partition(std::vector<Participant>& vec, int l, int r) {
    // пофиксил выбор произвольного pivot-а
    // добавил файл со сравнением работы и подсчетом swap-ов
    srand((unsigned)time(NULL));
    size_t pivot = rand() % (r - l + 1) + l;
    std::swap(vec[pivot], vec[r]);

    int j = l - 1;
    
    for (size_t i = l; i < r; i++)
    {
        if (vec[r] < vec[i]) {
            ++j;
            std::swap(vec[i], vec[j]);
        }
    }
    ++j;
    std::swap(vec[j], vec[r]);    

    return j;
}

void quick_sort(std::vector<Participant>& vec, int l, int r) {
    if (l < r) {
        size_t pivot = partition(vec, l, r);
        quick_sort(vec, l, pivot - 1);
        quick_sort(vec, pivot + 1, r);
    }
}

int main() {
    std::vector<Participant> arr;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::string name;
        int solved;
        int penalty;
        std::cin >> name >> solved >> penalty;
        arr.push_back(Participant(name, solved, penalty));
    }
    quick_sort(arr, 0, arr.size() - 1);

    for (auto &&i : arr)
    {
        std::cout << i << '\n';
    }
    return 0;
}