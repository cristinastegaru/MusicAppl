#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "../includes/Artist_class.hpp"
#include "../includes/Song_class.hpp"
#include "../includes/User.hpp"
#include "../includes/MusicApp_class.hpp"

namespace MusicApplication {
    void MusicApp::add_user(User added_user)
    {
        users.push_back(added_user);
    }

    void MusicApp::add_artist(Artist added_artist)
    {
        artists.push_back(added_artist);
    }

    vector<Artist> MusicApp::get_artists()
    {
        return artists;
    }
}




