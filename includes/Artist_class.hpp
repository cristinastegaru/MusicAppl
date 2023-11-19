#ifndef ARTIST_CLASS_HPP
#define ARTIST_CLASS_HPP

#include <string>
#include <vector>
using namespace std;
#include "Song_class.hpp"

namespace MusicApplication {
    class Artist {
    private:
        string *name;
        string *genre;
        vector<Song> songs;

    public:
        Artist(string name, string genre);
        Artist(const Artist& deep_copy_artist);
        Artist(Artist&& move_constructor_obj);
        void add_song(Song added_song);
        string get_name();
        vector<Song> get_songs();
        void rename_artist(string new_name);
        ~Artist();

    };
}
#endif