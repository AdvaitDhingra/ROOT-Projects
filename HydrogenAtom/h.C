#include <TVector3.h>
#include <cmath>

double WaveFunction(double x, double y)
{
    //TVector3 *waveFunctionCartesian = new TVector3(r*sin(theta)*cos(phi), r*sin(theta)+sin(phi), r*cos(phi));
    //double radical = sqrt(1-r);//1/sqrt(TMath::Pi())*((1/5.29177210903e-11)); //* exp(2.9, -r/5.29177210903e-11))); //((2.9)^(-r/5.29177210903e-11)));
    //double sphericalHarmonic = 0.5*sqrt(1/TMath::Pi());

    //cout << r << endl;

    //return radical * sphericalHarmonic;


    double r = sqrt(x * x + y * y);

    double w = (1/pow((4*sqrt(2*TMath::Pi())* 1), 1.5)) * (2 - (r / 1)*pow(TMath::E(), -r/2));

    return w*w;
    
}

void h()
{
    TGraph2D *g = new TGraph2D();

    TGraph *gr = new TGraph();

    TH2F *hist = new TH2F("Hydrogen Atom", "H", 1000, -15, 15, 1000, -15, 15);

    int count = 1;

    //for (float i = 0; i < 1; i+=0.1){
      //  for (float j = 0; j < 2 * TMath::Pi(); j+=0.1){
        //    for (float k = 0; k < 2 * TMath::Pi(); k+=0.1){
          //      g->SetPoint(g->GetN(), i * sin(j)*cos(k), i * sin(j)*sin(k), WaveFunction(i, j, k));
            //    gr->SetPoint(gr->GetN(), )
            //}
        //}
    //}

    for (float i = -15; i < 15; i+=0.01){
        for (float j = -15; j < 15; j+=0.01){
            //gr->SetPoint(gr->GetN(), i, j, WaveFunction(i, j));
            //count++;
            hist->Fill(i, j, WaveFunction(i, j));
        }
    }
    TCanvas *c1 = new TCanvas("c1", "Schrödinger's Hydrogen Atom", 700, 700);
    hist->Draw("colz");
    //g->Draw("surf1");

}

