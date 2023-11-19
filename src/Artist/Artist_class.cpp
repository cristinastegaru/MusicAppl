#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "../includes/Artist_class.hpp"
#include "../includes/Song_class.hpp"

 namespace MusicApplication {
    Artist::Artist(string name_given, string genre_given)
    {
        name = new string(name_given);
        genre = new string(genre_given);
    }

    Artist::Artist(const Artist& deep_copy_artist)
    {
        name = new string(*deep_copy_artist.name);
        genre = new string(*deep_copy_artist.genre);
        for (Song song : deep_copy_artist.songs) {
            Song song_copy(song);
            songs.push_back(song_copy);
        }
    }

    Artist::Artist(Artist&& move_constructor_obj)
    {
    name = move_constructor_obj.name;
    genre = move_constructor_obj.genre;
    songs = std::move(move_constructor_obj.songs);

    move_constructor_obj.name = nullptr;
    move_constructor_obj.genre = nullptr;
    }

    Artist::~Artist()
    {
        delete name;
        delete genre;
    }

    void Artist::add_song(Song added_song)
    {
        songs.push_back(added_song);
    }

    string Artist::get_name()
    {
        return *name;
    }

    void Artist::rename_artist(string new_name)
    {
        *name = new_name;
    }

    vector<Song> Artist::get_songs()
    {
        return songs;
    }

}