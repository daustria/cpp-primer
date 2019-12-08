enum color {red, yellow, green}; //unscoped

enum class peppers {red, yellow, green}; //scoped

color eyes = green; //colors are unscoped, no need to specify scope
peppers p = peppers::green; //need to specify scope
color hair = color::yellow;

int main()
{}
