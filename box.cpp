//gcc box.cpp - lstdc++
//gcc unordered_map.cpp -lstdc++
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <iterator>

#define NUMBER_OF_BOXES 25
#define ATTEMPTS 400

static int getRandom(int low, int high)
{
    return rand() % (high + 1 - low) + low;
}

int main(int args, char **argc)
{
    int wins_if_stick = 0;
    int wins_if_change = 0;

    for (int attempts = 0; attempts < ATTEMPTS; attempts++)
    {
        std::unordered_map<int, bool> boxes;

        // create some empty boxes
        for (int box = 1; box <= NUMBER_OF_BOXES; box++)
        {
            boxes.insert(std::make_pair(box, false));
        }

        int prize_box = getRandom(1, NUMBER_OF_BOXES);

        std::unordered_map<int, bool>::iterator it = boxes.find(prize_box);

        it->second = true;

        int picked_box_number = getRandom(1, NUMBER_OF_BOXES);

        // host removes boxes
        for (it = boxes.begin(); it != boxes.end();)
        {
            // We remove anything that is neither out box or contains the prize
            if (it->first != picked_box_number && it->second == false)
            {
                it = boxes.erase(it);
                continue;
            }
            it++;
        }

        it = boxes.find(picked_box_number);

        if (it->second == true)
        {
            wins_if_stick++;
        }
        else
        {
            wins_if_change++;
        }
    }
    printf("Wins on sicking to chosen box %d\n", wins_if_stick);
    printf("Wins on changing box %d\n", wins_if_change);
}