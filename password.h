#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <vector>

#define ROWS 5
#define COLS 10 
#define TBUTTON 50,50

using namespace std;
/********************************************************************************/
class Clavier:public wxPanel{
		wxString text;
		
		public:
		vector <wxButton*> touches;//Touche clavier		
		Clavier (wxFrame* parent); //Constructor 
		void showButtons();
};

/********************************************************************************/
const wxWindowIDRef ID_BOT1 = wxWindow::NewControlId();
#include "password.cpp"

#endif
