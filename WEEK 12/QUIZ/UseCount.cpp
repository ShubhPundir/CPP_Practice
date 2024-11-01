#include <iostream>
#include <memory>
using namespace std;

struct st_data{
    st_data() = default;
};

void use(const std::shared_ptr<st_data> p ){
    auto p2 = p;
    cout << p.use_count() << " "; // 4
}

int main(){
    st_data d;
    auto p1 = std::make_shared<st_data>(d); // 1
    {
        std::shared_ptr<st_data> p2 = p1; // 2
        cout << p1.use_count() << " "; // 2
    }

    auto p2 = p1; // 2
    cout << p1.use_count() << " "; // 2

    use(p1); // 4
    cout << p1.use_count() << " "; // 2

    p1.reset(); // 0
    cout << p1.use_count(); // 0
    return 0;
}