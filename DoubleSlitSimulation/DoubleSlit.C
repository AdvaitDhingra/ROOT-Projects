#include <TMath.h>

void DoubleSlit()
{
	double pi = TMath::Pi();
	double e = TMath::E();

	TRandom2 *rand = new TRandom2();
	
    TF1 *difraction = new TF1("Difraction", "TMath::Gaus(x, 0)", -3, 3);

	TF1 *interference = new TF1("Both", "TMath::Gaus(x, 0) + cos(4*x) ", -4, 4);
	
	
	TGraph *bothSlitsOpen = new TGraph();
	
	for (float i = -3; i < 3; i+=0.001)
	{
		bothSlitsOpen->SetPoint(bothSlitsOpen->GetN(), interference->GetRandom(), rand->Rndm()+1);
	}		
	
	TCanvas *c1 = new TCanvas();
	bothSlitsOpen->SetTitle("Electron Position when both slits are open");
	bothSlitsOpen->Draw("A*");
	//interference->Draw();


}	