//---------------------------------------------------------------------------

#ifndef tictacfrmH
#define tictacfrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>

//My Headers
#include <GBoard.h>//"..\lib\games\GBoard.h"
using namespace Games;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TBevel *Bevel1;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TBevel *Bevel4;
        TMainMenu *MainMenu1;
        TMenuItem *Game1;
        TMenuItem *New1;
        TMenuItem *Exit1;
        TStaticText *StaticText1;
        void __fastcall putPlayer(TObject *Sender);
        void __fastcall ClearBoard(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
private:
        // User declarations
   	GameBoard TicTacBrd;
        GamePiece pieces[9];
        GamePiece::status player;
        TImage* images[9];

        Graphics::TBitmap* PicX;
        Graphics::TBitmap* PicO;

        GamePiece::status winner();
        bool boardFull();

public:
        // User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
