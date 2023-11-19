#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
#include "../includes/Artist_class.hpp"
#include "../includes/Song_class.hpp"
#include "../includes/User.hpp"
#include "../includes/MusicApp_class.hpp"
#include "../includes/Podcast_class.hpp"

    template <typename UserType>
    void print_user_info(UserType& user) {
        cout << "Username: " << user.get_username() << endl;
        cout << "Account Type: ";
        user.type_of_account();
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
    
    cout << endl << "------------------\n";
    //Functie templetizata
    print_user_info(user1);
    print_user_info(user2);

    cout << endl << "------------------\n";
    //Clasa template
    MusicApplication::Podcast<string> podcast1("Ghost Tales");
    podcast1.display_info();

    MusicApplication::Podcast<int> podcast2(1984);
    podcast2.display_info();
    cout << endl << "------------------\n";
    //Unique pointer
    unique_ptr<MusicApplication::Podcast<string>> podcastPtr(new MusicApplication::Podcast<string>("My favorite purchases of May!"));
    podcastPtr->display_info();
    cout << endl << "------------------\n";
    //Share pointer
    shared_ptr<MusicApplication::Song> songPtr = make_shared<MusicApplication::Song>("Sacrifice");

    cout << "Count before creating new pointers: " << songPtr.use_count() << endl;
    {
        shared_ptr<MusicApplication::Song> songPtr2 = songPtr;
        shared_ptr<MusicApplication::Song> songPtr3 = songPtr;

        cout << "Count after creating two new pointers: " << songPtr.use_count() << endl;
    }

    cout << "Count after deleting two pointers: " << songPtr.use_count() << endl;



}