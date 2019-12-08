using namespace std;

//Constant expressions are ones that can be evaluated at compile time.

int j = 0;
constexpr int i = 42;


int main()
{
	constexpr int *np = nullptr; //np is a constant pointer to an integer (That is null)

	//Variables inside functions are not stored at fixed addresses.
	//To properly initialize the const expressions p and p1, it is necessary to have i and j declared outside any function.
	//This is necessary so that the addresses of i and j are constant expressions.

	constexpr const int *p = &i; //p is a constant pointer to the const integer i 
	constexpr int *p1 = &j; //p1 is a constant pointer to the integer j
}
