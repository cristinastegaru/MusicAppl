#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "User.hpp"

    User::User(string username_given, string email_given, string password_given)
        {
            username = username_given;
            email = email_given;
            password = password_given;
        }

        void User::follow_artist(MusicApp app, string artist_name)
        {
            vector<Artist> artists = app.get_artists();
            for (Artist artist : artists)
                if(artist.get_name() == artist_name)
                {
                    following_artists.push_back(artist);
                }
        }

        void User::show_following_artists()
        {
            for (Artist artist : following_artists)
                cout<<artist.get_name();
        }