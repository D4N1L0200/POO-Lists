#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

using std::string;

class Song {
private:
    string title;
    string artist;
    string album;
    time_t includeTime;
    std::chrono::seconds playTime;

public:
    Song(string title, string artist, string album, int playTime);
    ~Song() = default;

    string getTitle();
    string getArtist();
    string getAlbum();
    time_t getIncludeTime();
    string getIncludeTimeFormatted();
    std::chrono::seconds getPlayTimeSeconds();
    string getPlayTimeFormatted();
    string getInfo();
};