//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tictacfrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   PicX = new Graphics::TBitmap;
   PicO = new Graphics::TBitmap;
   PicX->LoadFromResourceName(int(HInstance), "BITMAP1");
   PicO->LoadFromResourceName(int(HInstance), "BITMAP2");

   player = GamePiece::pl1; //X
   StaticText1->Caption = "";
   TicTacBrd.resize(3, 3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender){Close();}
void __fastcall TForm1::putPlayer(TObject *Sender)
{
   TImage* Image = static_cast<TImage*>(Sender);
   point pos;
   if(Image->Name == "Image1")pos = point(0,0);
   else if(Image->Name == "Image2")pos = point(0,1);
   else if(Image->Name == "Image3")pos = point(0,2);
   else if(Image->Name == "Image4")pos = point(1,0);
   else if(Image->Name == "Image5")pos = point(1,1);
   else if(Image->Name == "Image6")pos = point(1,2);
   else if(Image->Name == "Image7")pos = point(2,0);
   else if(Image->Name == "Image8")pos = point(2,1);
   else if(Image->Name == "Image9")pos = point(2,2);


   if(TicTacBrd[pos].occupied || StaticText1->Caption != "")
      return;

   if(player == GamePiece::pl1) //X
      Image->Picture->Assign(PicX);
   else //O
      Image->Picture->Assign(PicO);

   TicTacBrd[pos].piece = &pieces[(3*pos.x)+pos.y];
   TicTacBrd[pos].occupied = true;//above: Triunary
   TicTacBrd[pos].piece->changePlyr(player);

   switch(winner())
   {
      case GamePiece::pl1: //X
         StaticText1->Caption = "X is the Winner";
         break;

      case GamePiece::pl2: //O
         StaticText1->Caption = "O is the Winner";
         break;

      case GamePiece::none:
         if(boardFull())
            StaticText1->Caption = "It was a draw";
   }

   player = (player == GamePiece::pl1) ? GamePiece::pl2 : GamePiece::pl1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearBoard(TObject *Sender)
{
   Image1->Picture->Bitmap = NULL;
   Image2->Picture->Bitmap = NULL;
   Image3->Picture->Bitmap = NULL;
   Image4->Picture->Bitmap = NULL;
   Image5->Picture->Bitmap = NULL;
   Image6->Picture->Bitmap = NULL;
   Image7->Picture->Bitmap = NULL;
   Image8->Picture->Bitmap = NULL;
   Image9->Picture->Bitmap = NULL;

   TicTacBrd.clear();

   for(int i = 0; i<9; i++)
      pieces[i] = GamePiece();

   StaticText1->Caption = "";

   player = GamePiece::pl1;
}

//---------------------------------------------------------------------------
//determines if there is a winner.
GamePiece::status TForm1::winner()
{
   /*
   GamePiece::status temp;
   if(TicTacBrd[point(0,0)].piece != NULL)
   {
      temp = TicTacBrd[point(0,0)].piece.getPlyr();
      if(TicTacBrd[point(0,1)].piece.getPlyr() == temp &&
         TicTacBrd[point(0,2)].piece.getPlyr() == temp
      ) return temp;

      if(TicTacBrd[point(1,0)].piece.getPlyr() == temp &&
         TicTacBrd[point(2,0)].piece.getPlyr() == temp
      ) return temp;
   }

   if(TicTacBrd[point(1,1)].piece != NULL)
   }
      temp = TicTacBrd[point(1,1)].piece.getPlyr();
      if(TicTacBrd[point(1,0)].piece.getPlyr() == temp &&
         TicTacBrd[point(1,2)].piece.getPlyr() == temp
      ) return temp;

      if(TicTacBrd[point(0,1)].piece.getPlyr() == temp &&
         TicTacBrd[point(2,1)].piece.getPlyr() == temp
      ) return temp;

      if(TicTacBrd[point(0,0)].piece.getPlyr() == temp &&
         TicTacBrd[point(2,2)].piece.getPlyr() == temp
      ) return temp;

      if(TicTacBrd[point(0,2)].piece.getPlyr() == temp &&
         TicTacBrd[point(2,0)].piece.getPlyr() == temp
      ) return temp;
   }

   if(TicTacBrd[point(2,2)].piece !=NULL)
   }

   */
   if(pieces[0].getPlyr() != GamePiece::none)
   {
      if(pieces[1].getPlyr() == pieces[0].getPlyr() &&
         pieces[2].getPlyr() == pieces[0].getPlyr()
      ) return pieces[0].getPlyr();

      if(pieces[3].getPlyr() == pieces[0].getPlyr() &&
         pieces[6].getPlyr() == pieces[0].getPlyr()
      ) return pieces[0].getPlyr();
   }

   if(pieces[8].getPlyr() != GamePiece::none)
   {
      if(pieces[6].getPlyr() == pieces[8].getPlyr() &&
         pieces[7].getPlyr() == pieces[8].getPlyr()
      ) return pieces[8].getPlyr();

      if(pieces[2].getPlyr() == pieces[8].getPlyr() &&
         pieces[5].getPlyr() == pieces[8].getPlyr()
      ) return pieces[8].getPlyr();
   }
   if(pieces[4].getPlyr() != GamePiece::none)
   {
      if(pieces[0].getPlyr() == pieces[4].getPlyr() &&
         pieces[8].getPlyr() == pieces[4].getPlyr()
      ) return pieces[4].getPlyr();

      if(pieces[2].getPlyr() == pieces[4].getPlyr() &&
         pieces[6].getPlyr() == pieces[4].getPlyr()
      ) return pieces[4].getPlyr();

      if(pieces[1].getPlyr() == pieces[4].getPlyr() &&
         pieces[7].getPlyr() == pieces[4].getPlyr()
      ) return pieces[4].getPlyr();

      if(pieces[3].getPlyr() == pieces[4].getPlyr() &&
         pieces[5].getPlyr() == pieces[4].getPlyr()
      ) return pieces[4].getPlyr();
   }
   return GamePiece::none;
}
//---------------------------------------------------------------------------

bool TForm1::boardFull()
{
   for(int i=0; i<3; i++)
      for(int j=0; j<3; j++)
         if(!TicTacBrd[point(i, j)].occupied) return false;

   return true;
}
