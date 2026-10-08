
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double R, xp, xk, dx, x, y;

    cout << "Enter R: ";
    cin >> R;

    cout << "Enter start x: ";
    cin >> xp;

    cout << "Enter end x: ";
    cin >> xk;

    cout << "Enter step dx: ";
    cin >> dx;

    if (R <= 0 || dx <= 0 || xp > xk)
    {
        cout << "Invalid parameters!" << endl;
    }
    else
    {
        cout << fixed << setprecision(4);
        cout << "------------------------" << endl;
        cout << "|     x    |     y     |" << endl;
        cout << "------------------------" << endl;

        x = xp;

        while (x <= xk + 1e-9)
        {
            if (x >= -8 - R && x <= -8 + R)
            {
                // Lower semicircle
                y = R - sqrt(R * R - (x + 8) * (x + 8));
            }
            else if (x > -8 + R && x <= -4)
            {
                // Horizontal line
                y = R;
            }
            else if (x > -4 && x <= 2)
            {
                // Descending line
                y = R + (-1 - R) * (x + 4) / 6;
            }
            else if (x > 2)
            {
                // Ascending line
                y = x - 3;
            }
            else
            {
                cout << "Function undefined for x = "
                    << x << endl;
                x += dx;
                continue;
            }

            cout << "| " << setw(8) << x
                << " | " << setw(9) << y
                << " |" << endl;

            x += dx;
        }

        cout << "------------------------" << endl;
    }

    return 0;
}

}
