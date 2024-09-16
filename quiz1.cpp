#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
#include <print>
#include <map>

namespace RestaurantLineup {
    class Database {
        std::deque<std::string> waiting_list;
        std::unordered_map<
            std::string,
            std::deque<std::string>::iterator
        > name_to_pos_table;
        std::deque<std::string>::iterator current_seat_pos = waiting_list.begin();

    public:
        void build();

        void add_name(const std::string& name) {
            waiting_list.push_back(name);
            name_to_pos_table[name] = current_seat_pos++;
        }

        void remove_name(const std::string& name) {
            waiting_list.erase(name_to_pos_table.at(name));
            name_to_pos_table.erase(name);
        }

        void seat() {
            name_to_pos_table.erase(waiting_list.front());
            waiting_list.pop_front();
        }

        void print() {
            for (const auto& name : waiting_list)
                std::print("Name: {}\n", name);
        }
    };
}

// namespace RainyResearch {
//     struct Element {
//         double rainfall, latitude, time;
//     };

//     class Database {
//         std::multimap<> map;

//     public:
//         void build();
//         void record_data(double r, double l, double t);
//         double peak_rainfall(double l, double t);
//     };
// }

int main() {
    RestaurantLineup::Database db;

    db.add_name("Michael");
    db.add_name("Richard");
    db.add_name("James");

    db.remove_name("Richard");

    db.print();
}
