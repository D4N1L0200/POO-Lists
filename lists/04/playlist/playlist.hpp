#pragma once

#include <vector>

#include "song.hpp"

using std::vector;

class Playlist {
private:
    string name;
    string description;
    vector<Song> songs;

public:
    Playlist(string name, string description);
    ~Playlist() = default;

    string getName();
    string getDescription();
    vector<Song> getSongs();
    void addSong(Song song);
    std::chrono::seconds getPlayTime();
    string getPlayTimeFormatted();
    string getInfo();
};