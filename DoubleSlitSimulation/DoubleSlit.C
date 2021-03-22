#include <TMath.h>

void DoubleSlit()
{
	double pi = TMath::Pi();
	double e = TMath::E();

	TRandom2 *rand = new TRandom2();
	
    TF1 *difraction = new TF1("Difraction", "TMath::Gaus(x, 0)", -3, 3);
	TF1 *interference = new TF1("Interference", "sin(8*x)", -3, 3);

	TF1 *both = new TF1("Both", "TMath::Gaus(x, 0) + sin(8*x) ", -4, 4);
	
	
	TGraph *bothSlitsOpen = new TGraph();
	TGraph *leftOpen = new TGraph();
	TGraph *rightOpen = new TGraph();
	
	for (float i = -3; i < 3; i+=0.001)
	{
		bothSlitsOpen->SetPoint(bothSlitsOpen->GetN(), both->GetRandom(), rand->Rndm()+1);
		leftOpen->SetPoint(leftOpen->GetN(), rand->Rndm()-2, rand->Rndm());
		rightOpen->SetPoint(rightOpen->GetN(), rand->Rndm()+1, rand->Rndm());
		//gr->SetPoint(gr->GetN(), i, difraction->Eval(i) + interference->Eval(i));
	}		
	
	TCanvas *c1 = new TCanvas();
	bothSlitsOpen->SetTitle("Electron Position when both slits are open");
	bothSlitsOpen->Draw("A*");

	TCanvas *c2 = new TCanvas();
	leftOpen->SetTitle("Left Slit is open and right slit is closed");
	leftOpen->GetXaxis()->SetRangeUser(-4, 4);
	leftOpen->Draw("A*");

	TCanvas *c3 = new TCanvas();
	rightOpen->SetTitle("Right Slit is open and left slit is closed");
	rightOpen->GetXaxis()->SetRangeUser(-4, 4);
	rightOpen->Draw("A*");

}