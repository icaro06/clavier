#include "password.h"

/***************************  DEFINITIONS   *************************************/
/********************************************************************************/

/********************************************************************************/
/********************************************************************************/

Clavier::Clavier(wxFrame* parent):wxPanel(parent){//Constructeur principal

	showButtons();//Print Buttons
}

/********************************************************************************/
void Clavier::showButtons(){

    wxSize taille(50,50);//Taille touche 
    
    //Sizers   rows,cols
    wxBoxSizer* fenetreSizer  = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer* clavier = new  wxFlexGridSizer(ROWS,COLS,0,0);//Array clavier rows,cols
   
	/************************************************************************************************************************/	
	
	//Cree  wxPanel en fonction de la taille d'un bouton
    wxPanel* fenetre=new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize( (taille.x) * clavier->GetCols(),taille.y*clavier->GetCols()));
    
 	/************************************************************************************************************************/        
	initialiceClavier(fenetre,taille);
    /************************************************************************************************************************/    
    
    //Ajoute des touches au wxFlexSizer clavier                  
    for (auto touche :touches){clavier->Add(touche,wxEXPAND);		}
    
    /************************************************************************************************************************/  
 
	//Ajoute le clavier au sizer principal
    fenetreSizer->Add(clavier);//Ajoute wxBoxSizer HOzl VERTICAL

	//La fenetre wxPanel utilisse le sizer wxBoxSizer fenetre sizer 
	fenetre->SetSizer(fenetreSizer);    	
}


/********************************************************************************/
void Clavier::keyPressed(wxCommandEvent& event){
	cout <<" key " <<event.GetId()<< " = "<<idToButtonLabel(event.GetId())<<endl;//OK 
		//cout <<" key " <<event.GetLabel()<<endl;
}

/********************************************************************************/
void Clavier::initialiceClavier(wxPanel* fenetre,wxSize taille){
	
    //Buttons , cree un vector de differentes  touches ... un clavier
	
	for (char bouton='0';bouton<='9';bouton++){//Cree touches  numeriques
		touches.push_back(new wxButton(fenetre,wxID_ANY,bouton,wxDefaultPosition,taille));
		id.push_back(key{touches.back()->GetLabel(),touches.back()->GetId()});		
	}
	
	//Touches alphabet
	
	for (auto bouton:touch){
		touches.push_back(new wxButton(fenetre,wxID_ANY,bouton,wxDefaultPosition,taille));
		id.push_back(key{touches.back()->GetLabel(),touches.back()->GetId()});
		}	
}

/********************************************************************************/
wxString Clavier::idToButtonLabel(int _id){//retourne label du bouton 
	for (auto bouton:id){if (bouton.id==_id){return bouton.nom;}		}
	return "";
}
/********************************************************************************/
/********************************************************************************/

