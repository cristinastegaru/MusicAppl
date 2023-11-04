#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <vector>
#include "MusicApp_class.hpp"
using namespace std;

namespace MusicApplication {
    class UserBase {
    public:
        virtual void type_of_account() = 0;
    };
}

namespace MusicApplication {
    class User {
    private:
        string username;
        string email;
        string password;

    public:
        User(string username, string email, string password);
        void account_status();
        string get_username();
    };

    class Premium_User : public User, public UserBase{
    private:
        vector<Artist> following_artists;
    public:
        Premium_User(string username, string email, string password);
        void follow_artist(MusicApp app, string artist_name);
        void show_following_artists();
        void type_of_account();
    };

    class Normal_User : public User, public UserBase{   
    public:
        Normal_User(string username, string email, string password);
        void type_of_account();
    };
}
#endif
