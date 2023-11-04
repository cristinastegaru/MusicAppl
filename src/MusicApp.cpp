#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Artist_class.hpp"
#include "Song_class.hpp"
#include "User.hpp"
#include "MusicApp_class.hpp"

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

//For running Cmake: mkdir build
//                   cmake -S . -B build
//                   cmake --build build
int main()
{
    MusicApplication::MusicApp spotify;
    MusicApplication::Premium_User user1("Cristina Stegaru", "cristina.stegaru@student.upt.ro", "cristina1!");
    spotify.add_user(user1);
    MusicApplication::Normal_User user2("Maria Stegaru", "maria.stegaru@student.upt.ro","maria1!");
    spotify.add_user(user2);

    MusicApplication::Artist artist1("Ghost Town", "rock");
    spotify.add_artist(artist1);
    MusicApplication::Song song1("Hell");
    artist1.add_song(song1);
    user1.follow_artist(spotify, "Ghost Town");
    user1.show_following_artists();

    cout << endl << "------------------" << endl << "Shallow copy" << endl;
    // Shallow copy
    MusicApplication::Song song2("Hello");
    song2 = song1;

    cout << song1.get_song_name() << endl;
    cout << song2.get_song_name() << endl;
    song1.rename_song("Heaven");
    cout << song1.get_song_name() << endl;
    cout << song2.get_song_name();
    cout << endl << "------------------" << endl << "Deep copy" << endl;

    // Deep copy
    MusicApplication::Artist artist2(artist1);
    cout << artist1.get_name() << endl;
    cout << artist2.get_name() << endl;
    artist1.rename_artist("New Town");
    cout << artist1.get_name() << endl;
    cout << artist2.get_name() << endl;
    cout << endl << "------------------\n";

    //Move constructor
    MusicApplication::Artist artist3("Gorillaz", "Alternative");
    MusicApplication::Artist artist4(move(artist3));
    cout << artist4.get_name();
    cout << endl << "------------------\n";
    // Deep copy - copy constructor for artist: for example, the artist wants to recreate their account while keeping the same information but adding songs only to the second account
    // Shallow copy - for songs, for example, two artists collaborate

    //Inheritance
    user1.account_status();
    user2.account_status();
    cout << endl << "------------------\n";
    //Interface
    user1.type_of_account();
    user2.type_of_account();

}
