#include <iostream>
using namespace std;
void cool(int SrcX,
          int SrcY,
          int DestX,
          int DestY)
{
    int diffX = SrcX - DestX;
    int diffY = SrcY - DestY;
    if ((diffX * diffY * (diffX + diffY) * (diffX - diffY)) == 0)
    {
        cout << "True" << endl;
        return;
    }
    cout << "False" << endl;
}
int main()
{
    int SrcX;
    int SrcY;
    int DestX;
    int DestY;
    cin >> SrcX;
    cin >> SrcY;
    cin >> DestX;
    cin >> DestY;

    while (SrcX != 0 || SrcY != 0 || DestX != 0 || DestY != 0)
    {
        // cool(SrcX,
        //      SrcY,
        //      DestX,
        //      DestY);
        int DiffX=SrcX-DestX;
        int DiffY=SrcY-DestY;        
        if (SrcX == DestX)
        {
            cout << "True" << endl;
        }
        else if (SrcY == DestY)
        {
            cout << "True" << endl;
        }
        else if(DiffX+DiffY==0  || DiffX-DiffY==0)
        {
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
        cin >> SrcX;
        cin >> SrcY;
        cin >> DestX;
        cin >> DestY;
    }
}