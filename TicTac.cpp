//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("TicTac.res");
USEFORM("tictacfrm.cpp", Form1);
USELIB("..\Lib\games\GamesLib.lib");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
