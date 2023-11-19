#ifndef MUSICAPP_CLASS_HPP
#define MUSICAPP_CLASS_HPP

#include <vector>
using namespace std;
#include "Artist_class.hpp"
#include "User.hpp"

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

