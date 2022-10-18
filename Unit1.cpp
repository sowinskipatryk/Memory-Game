//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int memory[1000];
int level=0;
int clicks=0;
bool gameStarted = false;

void disableButtons()
{
        Form1->Image1->Enabled=false;
        Form1->Image2->Enabled=false;
        Form1->Image3->Enabled=false;
        Form1->Image4->Enabled=false;
        Form1->Image5->Enabled=false;
        Form1->Image1->Cursor=crDefault;
        Form1->Image2->Cursor=crDefault;
        Form1->Image3->Cursor=crDefault;
        Form1->Image4->Cursor=crDefault;
        Form1->Image5->Cursor=crDefault;
}

void enableButtons()
{
        Form1->Image1->Enabled=true;
        Form1->Image2->Enabled=true;
        Form1->Image3->Enabled=true;
        Form1->Image4->Enabled=true;
        Form1->Image5->Enabled=true;
        Form1->Image1->Cursor=crHandPoint;
        Form1->Image2->Cursor=crHandPoint;
        Form1->Image3->Cursor=crHandPoint;
        Form1->Image4->Cursor=crHandPoint;
        Form1->Image5->Cursor=crHandPoint;
}

void loadGrayscaleImages()
{
        Form1->Image1->Picture->LoadFromFile("img/cplusplusgray.bmp");
        Form1->Image2->Picture->LoadFromFile("img/javascriptgray.bmp");
        Form1->Image3->Picture->LoadFromFile("img/javagray.bmp");
        Form1->Image4->Picture->LoadFromFile("img/cgray.bmp");
        Form1->Image5->Picture->LoadFromFile("img/pythongray.bmp");
}

void countdown()
{
        Application->ProcessMessages();
        Sleep(300);
        Form1->Label1->Caption="Three";
        sndPlaySound("snd/three.wav", SND_ASYNC);

        Application->ProcessMessages();
        Sleep(2000);
        Form1->Label1->Caption="Two";
        sndPlaySound("snd/two.wav", SND_ASYNC);

        Application->ProcessMessages();
        Sleep(1500);
        Form1->Label1->Caption="One";
        sndPlaySound("snd/one.wav", SND_ASYNC);

        Application->ProcessMessages();
        Sleep(1500);
        Form1->Label1->Caption="Watch carefully!";
        sndPlaySound("snd/start.wav", SND_ASYNC);
        
        Application->ProcessMessages();
        Sleep(1500);
}

void showPattern()
{
        disableButtons();

        Application->ProcessMessages();
        Sleep(1500);

        Form1->Label1->Caption="Watch carefully!";

        Application->ProcessMessages();
        Sleep(500);

        level++;
        for (int i=0; i<level; i++)
        {
                switch(memory[i])
                {
                        case 1:
                        {
                                sndPlaySound("snd/cplusplus.wav", SND_ASYNC);
                                Form1->Image6->Visible=true;
                        } break;

                        case 2:
                        {
                                sndPlaySound("snd/javascript.wav", SND_ASYNC);
                                Form1->Image7->Visible=true;
                        } break;

                        case 3:
                        {
                                sndPlaySound("snd/java.wav", SND_ASYNC);
                                Form1->Image8->Visible=true;
                        } break;

                        case 4:
                        {
                                sndPlaySound("snd/c.wav", SND_ASYNC);
                                Form1->Image9->Visible=true;
                        } break;

                        case 5:
                        {
                                sndPlaySound("snd/python.wav", SND_ASYNC);
                                Form1->Image10->Visible=true;
                        } break;
                }

                Application->ProcessMessages();
                Sleep(1500);

                Form1->Image6->Visible=false;
                Form1->Image7->Visible=false;
                Form1->Image8->Visible=false;
                Form1->Image9->Visible=false;
                Form1->Image10->Visible=false;

                Application->ProcessMessages();
                Sleep(300);
        }

        enableButtons();
        Form1->Label1->Caption = "Did you catch it?";
        clicks=0;

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        randomize();
        for(int i=0; i<sizeof(memory); i++)
        {
                memory[i] = random(5)+1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startButtonClick(TObject *Sender)
{
        if(!gameStarted)
        {
                startButton->Visible=false;
                gameStarted = true;
                disableButtons();
                countdown();
                showPattern();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
        if(gameStarted)
        {
            clicks++;
            if(memory[clicks-1]!=1)
            {
                level--;
                Label1->Caption="Game over! You scored "+IntToStr(level)+" points";
                sndPlaySound("snd/end.wav", SND_ASYNC);
                gameStarted=false;
                disableButtons();
            }
            if (clicks==level)
            {
                Label1->Caption="Good job!";
                loadGrayscaleImages();
                showPattern();
            }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
        if(gameStarted)
        {
            clicks++;
            if(memory[clicks-1]!=2)
            {
                level--;
                Label1->Caption="Game over! You scored "+IntToStr(level)+" points";
                sndPlaySound("snd/end.wav", SND_ASYNC);
                gameStarted=false;
                disableButtons();
            }
            if (clicks==level)
            {
                Label1->Caption="Good job!";
                loadGrayscaleImages();
                showPattern();
            }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
        if(gameStarted)
        {
            clicks++;
            if(memory[clicks-1]!=3)
            {
                level--;
                Label1->Caption="Game over! You scored "+IntToStr(level)+" points";
                sndPlaySound("snd/end.wav", SND_ASYNC);
                gameStarted=false;
                disableButtons();

            }
            if (clicks==level)
            {
                Label1->Caption="Good job!";
                loadGrayscaleImages();
                showPattern();
            }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
        if(gameStarted)
        {
            clicks++;
            if(memory[clicks-1]!=4)
            {
                level--;
                Label1->Caption="Game over! You scored "+IntToStr(level)+" points";
                sndPlaySound("snd/end.wav", SND_ASYNC);
                gameStarted=false;
                disableButtons();
            }
            if (clicks==level)
            {
                Label1->Caption="Good job!";
                loadGrayscaleImages();
                showPattern();
            }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
        if(gameStarted)
        {
            clicks++;
            if(memory[clicks-1]!=5)
            {
                level--;
                Label1->Caption="Game over! You scored "+IntToStr(level)+" points";
                sndPlaySound("snd/end.wav", SND_ASYNC);
                gameStarted=false;
                disableButtons();
            }
            if (clicks==level)
            {
                Label1->Caption="Good job!";
                loadGrayscaleImages();
                showPattern();
            }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image1->Picture->LoadFromFile("img/cplusplus.bmp");
        sndPlaySound("snd/cplusplus.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image1->Picture->LoadFromFile("img/cplusplusgray.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image2->Picture->LoadFromFile("img/javascript.bmp");
        sndPlaySound("snd/javascript.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image2->Picture->LoadFromFile("img/javascriptgray.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image3->Picture->LoadFromFile("img/java.bmp");
        sndPlaySound("snd/java.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image3->Picture->LoadFromFile("img/javagray.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image4->Picture->LoadFromFile("img/c.bmp");
        sndPlaySound("snd/c.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image4->Picture->LoadFromFile("img/cgray.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image5->Picture->LoadFromFile("img/python.bmp");
        sndPlaySound("snd/python.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Image5->Picture->LoadFromFile("img/pythongray.bmp");
}
//---------------------------------------------------------------------------
