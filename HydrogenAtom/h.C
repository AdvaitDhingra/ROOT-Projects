#include <TVector3.h>
#include <cmath>

double WaveFunction(double x, double y)
{
    double r = sqrt(x * x + y * y);

    double w = (1/pow((4*sqrt(2*TMath::Pi())* 1), 1.5)) * (2 - (r / 1)*pow(TMath::E(), -r/2));

    return w*w;
    
}

void h()
{
    TH2F *hist = new TH2F("Hydrogen Atom", "H", 1000, -15, 15, 1000, -15, 15);

    int count = 1;

    for (float i = -15; i < 15; i+=0.01){
        for (float j = -15; j < 15; j+=0.01){
            hist->Fill(i, j, WaveFunction(i, j));
        }
    }
    TCanvas *c1 = new TCanvas("c1", "Schrödinger's Hydrogen Atom", 700, 700);
    hist->Draw("colz");

}

