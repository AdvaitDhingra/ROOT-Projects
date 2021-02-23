//
// Created by AdvaitD on 22/02/2021.
// Display the wavefunction and amplitude of an electron in a box
//

#include <TMath.h>
#include <math.h>


float pi = TMath::Pi();

float L = 100; // m

int nx, ny, n;

float roundval(float var)
{
    float value = (int)(var*100+.5);
    return (float)value/100;
}
float waveFunction2D(float energyLevelx, float energyLevely, float lengthx, float lengthy)
{
    float wave = (2/L) * ( roundval(sin(energyLevelx * (lengthx/L) *pi)) )*( roundval(sin(energyLevely * (lengthy/L) *pi)));
    return wave;

}
float Amplitude2D(float wave)
{
    float amp =  wave * wave;

    return amp;

}
void electrons()
{
    cout << "Enter a value for n in x direction:" << endl;
    cin >> nx;
    cout << " Enter a value for n in y direction:" << endl;
    cin >> ny;

    TGraph2D *WaveFunctionTwo = new TGraph2D();
    TGraph2D *AmpTwo = new TGraph2D();

    int count = 0;
    for (int j = 0; j <= L; j++ )
    {
        for (int k = 0; k <= L; k++)
        {
            WaveFunctionTwo->SetPoint(count, j, k, waveFunction2D(nx, ny, j, k));
            AmpTwo->SetPoint(count, j, k, Amplitude2D(waveFunction2D(nx, ny, j, k)));
            count++;


        }
    }
    TCanvas *c1 = new TCanvas();
    gStyle->SetPalette(1);
    WaveFunctionTwo->SetTitle("Wavefunction");
    WaveFunctionTwo->Draw("surf1");
    TCanvas *c2 = new TCanvas();
    gStyle->SetPalette(1);
    AmpTwo->SetTitle("Amplitude");
    AmpTwo->GetXaxis()->SetTitle("x");
    AmpTwo->GetYaxis()->SetTitle("y");
    AmpTwo->Draw("surf1");
    c1->Print("wavefunction.png");
    c2->Print("amplitude.png");
}
