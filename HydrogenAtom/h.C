#include <TVector3.h>
#include <cmath>

double WaveFunction(double r, double theta, double phi)
{
    //TVector3 *waveFunctionCartesian = new TVector3(r*sin(theta)*cos(phi), r*sin(theta)+sin(phi), r*cos(phi));
    double radical = sqrt(1-r);//1/sqrt(TMath::Pi())*((1/5.29177210903e-11)); //* exp(2.9, -r/5.29177210903e-11))); //((2.9)^(-r/5.29177210903e-11)));
    double sphericalHarmonic = 0.5*sqrt(1/TMath::Pi());

    //cout << r << endl;

    return radical * sphericalHarmonic;
}

void h()
{
    TGraph2D *g = new TGraph2D();

    int count = 1;

    for (float i = 0; i < 1; i+=0.1){
        for (float j = 0; j < 2 * TMath::Pi(); j+=0.1){
            for (float k = 0; k < 2 * TMath::Pi(); k+=0.1){
                g->SetPoint(g->GetN(), i * sin(j)*cos(k), i * sin(j)*sin(k), WaveFunction(i, j, k));
            }
        }
    }
    TCanvas *c1 = new TCanvas();

    g->Draw("surf1");

}

