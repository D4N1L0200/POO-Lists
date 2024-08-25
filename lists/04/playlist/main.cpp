#include <iostream>

#include "playlist.hpp"

int main() {
    Playlist playlist("Hype", "Playlist for energetic songs");

    playlist.addSong(Song("Racemization", "Camellia", "PLANET//SHAPER", 5 * 60 + 12));
    playlist.addSong(Song("Ambergris", "Camellia", "Ashed Wings", 4 * 60 + 1));
    playlist.addSong(Song("Drenched in Air", "Camellia", "Ashed Wings", 4 * 60 + 54));

    std::cout << playlist.getInfo() << std::endl;

    for (auto song : playlist.getSongs()) {
        std::cout << song.getInfo() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
