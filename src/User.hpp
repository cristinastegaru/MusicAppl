#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "MusicApp_class.hpp"
using namespace std;

class User {
private:
    string username;
    string email;
    string password;
    vector<Artist> following_artists;

public:
    User(string username, string email, string password);

    void follow_artist(MusicApp app, string artist_name);
    void show_following_artists();
};

#endif
