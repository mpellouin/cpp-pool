/*
** EPITECH PROJECT, 2022
** day08
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string serial);
        Droid(const Droid &replicate);
        ~Droid();

        Droid &operator=(const Droid &other);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        Droid &operator<<(size_t &);
        bool operator()(const std::string *, size_t xp);
        // std::ostream &operator<<(std::ostream&, const Droid&);

        std::string getId(void) const;
        void setId(std::string);
        size_t getEnergy(void) const;
        void setEnergy(size_t);
        size_t getAttack(void) const;
        size_t getToughness(void) const;
        std::string *getStatus(void) const;
        void setStatus(std::string *);
        void setBattleData(DroidMemory *data);
        DroidMemory *getBattleData(void) const;
    private:
        std::string Id;
        size_t Energy = 50;
        const size_t Attack = 25;
        const size_t Toughness = 15;
        std::string *Status;
        DroidMemory *BattleData;
};

std::ostream &operator<<(std::ostream &s, const Droid &droid);

#endif /* !DROID_HPP_ */
