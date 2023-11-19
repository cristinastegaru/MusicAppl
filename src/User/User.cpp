#include<iostream>
#include <string>
#include <vector>
using namespace std;
#include "../includes/User.hpp"
#include "../includes/Artist_class.hpp"
#include "../includes/MusicApp_class.hpp"

namespace MusicApplication {
    User::User(string username_given, string email_given, string password_given)
        {
            username = username_given;
            email = email_given;
            password = password_given;
        }
    
    Premium_User::Premium_User(string username, string email, string password) : User(username, email, password) {
    }

    Normal_User::Normal_User(string username, string email, string password) : User(username, email, password) {
    }


        void Premium_User::follow_artist(MusicApp app, string artist_name)
        {
            vector<Artist> artists = app.get_artists();
            for (Artist artist : artists)
                if(artist.get_name() == artist_name)
                {
                    following_artists.push_back(artist);
                }
        }

        void Premium_User::show_following_artists()
        {
            for (Artist artist : following_artists)
                cout<<artist.get_name();
        }

        string User::get_username()
        {
            return username;
        }

        void User::account_status()
        {
            cout<<"Account = "<< get_username()<<"\n";
        }

        void Premium_User::type_of_account()
        {
            cout<<"Premium account! \n";
        }

        void Normal_User::type_of_account()
        {
            cout<<"Normal account! \n";
        }
}