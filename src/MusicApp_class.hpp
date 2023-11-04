#ifndef MUSICAPP_CLASS_HPP
#define MUSICAPP_CLASS_HPP

#include <vector>
#include "User.hpp"
#include "Artist_class.hpp"
using namespace std;

namespace MusicApplication {
    class User;

    class MusicApp {
    private:
        vector<User> users;
        vector<Artist> artists;

    public:
        void add_user(User added_user);
        void add_artist(Artist added_artist);
        vector<Artist> get_artists();
    };
}
#endif

