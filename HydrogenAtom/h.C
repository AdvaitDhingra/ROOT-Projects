#include <TVector3.h>
#include <cmath>

double WaveFunction(double x, double y)
{
    double r = sqrt(x * x + y * y);

    double w = (1/pow((4*sqrt(2*TMath::Pi())* 1), 1.5)) * (2 - (r / 1)*pow(TMath::E(), (-1 * r)/2));

    return w*w;

}

void h()
{
    TH2F *hist = new TH2F("Hydrogen Atom", "H", 1000, -10, 10, 1000, -10, 10);
    TGraph2D *g = new TGraph2D();

    int count = 1;

    for (float i = -10; i < 10; i+=0.01){
        for (float j = -10; j < 10; j+=0.01){
            hist->Fill(i, j, WaveFunction(i, j));
            g->SetPoint(g->GetN(), i, j, WaveFunction(i, j));
        }
    }
    //gStyle->SetPalette(53);
    TCanvas *c1 = new TCanvas("c1", "Schrödinger's Hydrogen Atom", 700, 700);
    hist->Draw("colz");

    TCanvas *c2 = new TCanvas("c2", "Schrödinger's Hydrogen Atom 3D", 700, 700);
    g->Draw("surf1");

}

