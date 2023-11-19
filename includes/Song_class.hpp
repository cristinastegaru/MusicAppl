#ifndef SONG_CLASS_H
#define SONG_CLASS_H

#include <string>
using namespace std;

namespace MusicApplication {
    class Song {
    private:
        string *name_song;

    public:
        Song(string name_s);
        ~Song();
        string get_song_name();
        void rename_song(string new_name);
        Song(const Song& deep_copy_song);
        void operator=(const Song& copy);
    };
}
#endif