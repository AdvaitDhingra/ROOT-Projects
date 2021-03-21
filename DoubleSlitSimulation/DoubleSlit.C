#include <TMath.h>

void DoubleSlit()
{
	double pi = TMath::Pi();
	double e = TMath::E();
	
    TF1 *difraction = new TF1("Difraction", "TMath::Gaus(x, 0)", -3, 3);
	TF1 *interference = new TF1("Interference", "sin(8*x)", -3, 3);
	
	
	TGraph *gr = new TGraph();
	
	for (float i = -3; i < 3; i+=0.01)
	{
		gr->SetPoint(gr->GetN(), i, difraction->Eval(i) + interference->Eval(i));
	}		
	
	TCanvas *c1 = new TCanvas();
	gr->Draw("A*");
}