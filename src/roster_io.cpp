#include "roster_io.h"

#include <fstream>
#include <sstream>

// TODO (Checkpoint 1): implement save_roster.
// Remove [[maybe_unused]] from a parameter once you use it.
bool save_roster(const std::vector<Mech>& roster,
                 const std::string& path) {
    std::ofstream saveMech(path);

    if (!saveMech) {
        return false;
    }

    for (const Mech& mech : roster) {
        saveMech << mech.name() << ","
            << mech.hp() << ","
            << mech.attack() << ","
            << mech.armor() << "\n";
    }

    return true;
}


// TODO (Checkpoints 2 and 3): implement load_roster.
bool load_roster(const std::string& path,
                 std::vector<Mech>& roster,
                 int& skipped_lines) {

    std::ifstream loadMech(path);

    if (!loadMech) {
        return false;
    }

    std::vector<Mech> temp_roster;
    std::string line;
    skipped_lines = 0;

    while (std::getline(loadMech, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string name;
        int hp = 0;
        int attack = 0;
        int armor = 0;
        char comma1 = '\0';
        char comma2 = '\0';

        if (std::getline(ss, name, ',') && (ss >> hp >> comma1 >> attack >> comma2 >> armor)) {
            temp_roster.emplace_back(name, hp, attack, armor);
        }
    }

    roster = std::move(temp_roster);
    return true;
}

// TODO (Checkpoint 4): implement append_line.
bool append_line(const std::string& path,
                 const std::string& text) {
    std::ofstream file(path, std::ios::app);
    if (!file) {
        return false;
    }

    file << text << "\n";
    return true;
}
