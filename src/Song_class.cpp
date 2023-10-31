
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Song_class.hpp"


    Song::Song(string name_s)
    {
        name_song = new string(name_s);
    }

    Song::~Song()
    {
        delete name_song;
    }

    string Song::get_song_name()
    {
        return *name_song;
    }

    void Song::rename_song(string new_name)
    {
        *name_song = new_name;
    }

    Song::Song(const Song& deep_copy_song)
    {
        name_song = new string(*deep_copy_song.name_song);
    }


    void Song::operator=(const Song& copy) {
       name_song = new string(*copy.name_song);
    }

