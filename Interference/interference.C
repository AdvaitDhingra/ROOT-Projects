#include <TMath.h>

void interference()
{

    float pi = TMath::Pi();

    TGraph *wave1 = new TGraph();
    TGraph *wave2 = new TGraph();

    TGraph *waveCombined = new TGraph();

    for (float i = 0; i < 2 * pi; i+= 0.1)
    {
    	
    	float first = sin(2*i);
    	float second = -sin(2*i);
    	
        wave1->SetPoint(wave1->GetN(), i, first);
        wave2->SetPoint(wave2->GetN(), i, second);

        waveCombined->SetPoint(waveCombined->GetN(), i,  first + second);
    }

    TCanvas *c1 = new TCanvas();
    wave1->SetTitle("sin");
    wave1->Draw();
    TCanvas *c2 = new TCanvas();
    wave2->Draw();
    wave2->SetTitle("cos");
    TCanvas *c3 = new TCanvas();
    waveCombined->SetTitle("both");
    waveCombined->Draw();
}
