#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <vector>
#include <array>

#define ROWS 5
#define COLS 10 
#define TBUTTON 50,50

using namespace std;

struct key {string nom;int id;};
/********************************************************************************/

class Clavier:public wxPanel{
	
	wxString text;
		
	public:
	vector <wxButton*> touches;//Touche clavier	

	const array <string,10*3> touch {{"Q","W","E","R","T","Y","U","I","O","P",
									"CAPS","A","S","D","F","G","H","J","K","L",
									"SHIFT","<","Z","X","C","V","B","N","M","@"}};
	vector <key> id;
	
	Clavier (wxFrame* parent); //Constructor 
	void showButtons();
   //EVT_MENU(wxID_ANY,    MiFrame::OnClick)
	void keyPressed(wxCommandEvent& event);
				
	private:
    /*Macro para informar a wxWidgets de la gestion de eventos
    *Declara la tabla de eventos en esta clase ,mas abajo
    * la implemento entre BEGIN_ y END_EVENT_TABLE
    */
    DECLARE_EVENT_TABLE()			
};
/********************************************************************************/

const wxWindowIDRef ID_BOT1 = wxWindow::NewControlId();

/********************************************************************************/



BEGIN_EVENT_TABLE(Clavier, wxPanel)

// some useful events
/*
 EVT_MOTION(wxImagePanel::mouseMoved)
 EVT_LEFT_DOWN(wxImagePanel::mouseDown)
 EVT_LEFT_UP(wxImagePanel::mouseReleased)
 EVT_RIGHT_DOWN(wxImagePanel::rightClick)
 EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
 EVT_KEY_DOWN(wxImagePanel::keyPressed)
 EVT_KEY_UP(wxImagePanel::keyReleased)
 EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
 */

//Procesa un wxEVT_ wxID_ANY
//Al anadir un EVT_BUTTON a una EVENT_TABLE se intercepta un wxCommandEvent generador por un wxButton
//Internamente el boton intercepta EVT_LEFT_DOWN generando el e evento como resultado
EVT_BUTTON(wxID_ANY,Clavier::keyPressed) //   EVT_BUTTON(wxID_OK,     MiFrame::OnButtonOk)

END_EVENT_TABLE()


/********************************************************************************/

#include "password.cpp"

/********************************************************************************/

/********************************************************************************/
#endif
