#ifndef NOTE_H
#define NOTE_H

#include <chrono>
#include <cstdint>
#include <string>

class Note
{
public:
    Note();

private:
    uint64_t                              id;
    std::chrono::system_clock::time_point createdAt;
    std::chrono::system_clock::time_point updatedAt;
    std::string                           content;
};

#endif // NOTE_H
