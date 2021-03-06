#include "RandomBot.h"

// Chooses a random column to play in
unsigned int RandomBot::chooseColumn() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, Board::FIELD_WIDTH-1);
    return dist6(rng);
}
