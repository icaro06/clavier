//Antonio Villanueva Segura login pasword AXIOME CONCEPT

#include "password.h"
using namespace std;
//#define RESOLUTION 800,600
#define RESOLUTION 500,200

/********************************************************************************/
/********************************************************************************/
// Arranque en wxWidgets 
class Run: public wxApp
{
    wxFrame *frame;
    Clavier* panel;//public wxPanel 
    
public:

	//Main wxWidgetss
    bool OnInit()
    {
        // Primero inicializamos todos los Handlers graficos 
        wxInitAllImageHandlers();
 
		//Crea el frame
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        frame = new wxFrame(NULL, wxID_ANY, wxT("password"), wxPoint(50,50), wxSize(RESOLUTION),wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER);//Frame
        
        // Panel de dibujo ,llama el constructor de wxImagePanel que carga una imagen ....
        panel = new Clavier(frame);
        
        sizer->Add(panel, 1);//Fondo pantalla ;

        frame->SetSizer(sizer);
        frame->Show();
        return true;
    } 
};
 
 
 /*Implementacion , MiApp
*Cuando se crea el objeto MiApp se asigna a la variable global wxTheApp
* pero mejor que hacer un CAST emplear el MACRO  DECLARE_APP despues de
* la declaracion de la clase , wxGetApp retorna una ref. al objeto MiApp
*/
DECLARE_APP(Run)
 
//Macro que Proporciona a wxWidgets los medios de crear el objeto MiApp
IMPLEMENT_APP(Run)
 


/********************************************************************************/

