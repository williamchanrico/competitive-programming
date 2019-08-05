// Can only modify this part of the code in the online editor
// Note to self: to return false, Checker::comparator must return -1
// because the problem setter said so
class Checker {
public:
    // complete this method
    static int comparator(const Player& a, const Player& b)
    {
        if (a.score == b.score)
            return (a.name < b.name ? 1 : -1);
        return (a.score > b.score ? 1 : -1);
    }
};
