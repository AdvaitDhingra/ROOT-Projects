#include <TMath.h>

void interference()
{
    TGraph *wave1 = new TGraph();
    TGraph *wave2 = new TGraph();

    TGraph *waveCombined = new TGraph();

    for (int i = 0; i < 2 * TMath::Pi(); i+= 0.1)
    {
        wave1->SetPoint(wave1->GetN(), i, sin(i));
        wave2->SetPoint(wave2->GetN(), i, cos(i));

        waveCombined->SetPoint(waveCombined->GetN(), i,  sin(i) + cos(i));
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