#ifndef PODCAST_HPP
#define PODCAST_HPP

#include <iostream>
using namespace std;

namespace MusicApplication {
template<typename T>
class Podcast {
private:
    T podcast_name;

public:
    Podcast(T name);
    void display_info();
};

    template<typename T>
    Podcast<T>::Podcast(T name) : podcast_name(name) {}

    template<typename T>
    void Podcast<T>::display_info() {
        cout << "Podcast: " << podcast_name <<endl;
    }
}

#endif 