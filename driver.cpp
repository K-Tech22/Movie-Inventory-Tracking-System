#include "store.h"
#include "iostream"

using namespace std;

int main()
{
    Store st;
    st.buildCustomerDatabase("data4customers.txt");
    st.buildMovieDatabase("data4movies.txt");
    st.processCommands("data4commands.txt");
    return 0;
}