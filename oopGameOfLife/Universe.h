#pragma once
#include <string>
#include <vector>

class Universe {
public:
    Universe();
    Universe(int, int, std::string&, std::vector<int>&, std::vector<int>&);
    Universe(std::string&, std::vector<int>&, std::vector<int>&);

    ~Universe();

    Universe(const Universe&);
    Universe(Universe&&) noexcept;

    Universe& operator=(const Universe&);
    Universe& operator=(Universe&&) noexcept;

    void setName(std::string&);
    const std::string& getName() const;

    void setCell(int, int, bool);
    bool getCell(int, int) const;

    void changeCells(std::vector< std::vector<bool> >&&) noexcept;

    const std::vector<int>& getBornRule() const;
    const std::vector<int>& getSurviveRule() const;

    int width() const;
    int height() const;

    int torus(int, int) const;

private:
    int sizeX = 0;
    int sizeY = 0;
    //bool* cells = nullptr;
    std::vector< std::vector<bool> > cells;
    std::string name;
    std::vector<int> bornRule;
    std::vector<int> surviveRule;
};