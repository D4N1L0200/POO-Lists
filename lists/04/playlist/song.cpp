#include "song.hpp"

Song::Song(string title, string artist, string album, int playTime) {
    if (title.empty() || artist.empty() || album.empty() || playTime <= 0) {
        throw std::invalid_argument("Song must have all fields filled");
    }

    this->title = title;
    this->artist = artist;
    this->album = album;
    this->includeTime = time(nullptr);
    this->playTime = std::chrono::seconds(playTime);
}

string Song::getTitle() {
    return this->title;
}

string Song::getArtist() {
    return this->artist;
}

string Song::getAlbum() {
    return this->album;
}

time_t Song::getIncludeTime() {
    return this->includeTime;
}

std::chrono::seconds Song::getPlayTimeSeconds() {
    return this->playTime;
}

std::string Song::getPlayTimeFormatted() {
    auto mins = std::chrono::duration_cast<std::chrono::minutes>(this->playTime);
    auto secs = std::chrono::duration_cast<std::chrono::seconds>(this->playTime % std::chrono::minutes(1));

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << mins.count() << ":"
       << std::setw(2) << std::setfill('0') << secs.count();

    return ss.str();
}

string Song::getIncludeTimeFormatted() {
    // Create a tm struct to hold the local time
    std::tm *tm_ptr = std::localtime(&this->includeTime);

    // Create a buffer to hold the formatted string
    char buffer[20];

    // Format the time into the buffer
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S %d/%m/%y", tm_ptr);

    // Convert the buffer to a std::string and return it
    return std::string(buffer);
}

string Song::getInfo() {
    return this->title + " by " + this->artist +
           " from " + this->album +
           " - " + this->getPlayTimeFormatted() +
           " - Added at " + this->getIncludeTimeFormatted();
}
