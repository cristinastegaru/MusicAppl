#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Artist_class.hpp"
#include "Song_class.hpp"
#include "User.hpp"
#include "MusicApp_class.hpp"


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


//For running Cmake: mkdir build
//                   cmake -S . -B build
//                   cmake --build build
int main()
{
    MusicApp spotify;
    User user1("Cristina Stegaru", "cristina.stegaru@student.upt.ro", "cristina1!");
    spotify.add_user(user1);
    Artist artist1("Ghost Town","rock");
    spotify.add_artist(artist1);
    Song song1("Hell");
    artist1.add_song(song1);
    user1.follow_artist(spotify,"Ghost Town");
    user1.show_following_artists();


    cout<<endl<<"------------------"<<endl<<"Shallow copy"<<endl;
    //shallow copy
    Song song2("Hello");
    song2 = song1;

    cout<<song1.get_song_name()<<endl;
    cout<<song2.get_song_name()<<endl;
    song1.rename_song("Heaven");
    cout<<song1.get_song_name()<<endl;
    cout<<song2.get_song_name();
    cout<<endl<<"------------------"<<endl<<"Deep copy"<<endl;

    //deep copy
    Artist artist2(artist1);
    cout<<artist1.get_name()<<endl;
    cout<<artist2.get_name()<<endl;
    artist1.rename_artist("New Town");
    cout<<artist1.get_name()<<endl;
    cout<<artist2.get_name()<<endl;
    cout<<endl<<"------------------";
    //deep copy - copy constructor la artist: de exemplu, artistul doreste sa isi refaca contul pastrand aceleasi informatii dar, pe viitor, sa adauge melodii doar pe al doilea cont
    //shallow copy - la melodii, de exemplu 2 artisti colaboreaza


}
