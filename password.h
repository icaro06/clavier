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

/********************************************************************************/
#define TTOUCHE 50,50

/********************************************************************************/

class Clavier:public wxPanel{			
	public:		
	Clavier (wxFrame* parent); //constructeur par défaut
				
	private:
	void showButtons();//Affiche les boutons dans une fenêtre wxPanel
	void keyPressed(wxCommandEvent& event);//Touche enfoncée
	void initialiceClavier(wxPanel* fenetre,wxSize taille);//initialice Touches clavier et ID
	
	vector <wxButton*> touches;//vecteur de wxButtons touche(s)  clavier	
	//array pour definir un clavier	QWERTY
	const array <string,10*3> touch {{"Q","W","E","R","T","Y","U","I","O","P",
									"CAPS","A","S","D","F","G","H","J","K","L",
									"SHIFT","<","Z","X","C","V","B","N","M","@"}};
    DECLARE_EVENT_TABLE()			
};
/********************************************************************************/

const wxWindowIDRef ID_BOT1 = wxWindow::NewControlId();

/********************************************************************************/

BEGIN_EVENT_TABLE(Clavier, wxPanel)
	EVT_BUTTON(wxID_ANY,Clavier::keyPressed) //   EVT_BUTTON(wxID_OK,     MiFrame::OnButtonOk)
END_EVENT_TABLE()


/********************************************************************************/

#include "password.cpp"

/********************************************************************************/

/********************************************************************************/
#endif
