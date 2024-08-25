#include "playlist.hpp"

Playlist::Playlist(string name, string description) {
    if (name.empty()) {
        throw std::invalid_argument("Playlist must have a name");
    }

    this->name = name;
    this->description = description;
}

string Playlist::getName() {
    return this->name;
}

string Playlist::getDescription() {
    return this->description;
}

vector<Song> Playlist::getSongs() {
    return this->songs;
}

void Playlist::addSong(Song song) {
    this->songs.push_back(song);
}

std::chrono::seconds Playlist::getPlayTime() {
    std::chrono::seconds sum(0);

    for (auto &&song : this->songs) {
        sum += song.getPlayTimeSeconds();
    }

    return sum;
}

std::string Playlist::getPlayTimeFormatted() {
    std::chrono::seconds playtime = this->getPlayTime();

    auto mins = std::chrono::duration_cast<std::chrono::minutes>(playtime);
    auto secs = std::chrono::duration_cast<std::chrono::seconds>(playtime % std::chrono::minutes(1));

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << mins.count() << ":"
       << std::setw(2) << std::setfill('0') << secs.count();

    return ss.str();
}

string Playlist::getInfo() {
    return this->name + " - " + this->description +
           " - " + this->getPlayTimeFormatted();
}
