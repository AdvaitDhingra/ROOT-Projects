//
// Created by AdvaitD on 22/02/2021.
// Display the wavefunction and amplitude of an electron in a box
//

float hBar = 4.135667696e-15;

float pi = 3.141592653589;

float m = 510998.95; // MeV/c

float L = 100; // m

float a = 1000;

float b = 1000;

int nx, ny, n;

float wavefunction(float energyLevel, float length)
{
    float wave = sqrt(2/L) * sin(energyLevel*pi/L * length);

    return wave;
}
float amplitude(float wave)
{
    return wave * wave;
}
float waveFunction2D(float energyLevelx, float energyLevely, float lengthx, float lengthy)
{
    float wave = 2/L * sin(energyLevelx * pi * lengthx/L) * sin(energyLevely*pi*lengthy/L);

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
    cout << " Enter a value forn in y direction:" << endl;
    cin >> ny;

    //TH1F *values = new TH1F("Values", "Values", 100, 0, L);

    //double xs[1000], ys[1000];

    //TGraph2D *WaveFunction2D = new TGraph();
    //TGraph2D *Amplitude2D = new TGraph();
    TGraph2D *WaveFunctionTwo = new TGraph2D();
    TGraph2D *AmpTwo = new TGraph2D();

    TGraph* WaveFunction = new TGraph();
    TGraph* Amplitude = new TGraph();

    //for (int i = 0; i < L; i++)
    //{
      //  WaveFunction->SetPoint(WaveFunction->GetN(), i, wavefunction(1, i));
      //  Amplitude->SetPoint(Amplitude->GetN(), i, amplitude(wavefunction(1, i)));

    //}
    int count = 0;
    for (int j = 0; j < L; j++ )
    {
        for (int k = 0; k < L; k++)
        {
            WaveFunctionTwo->SetPoint(count, j, k, waveFunction2D(nx, ny, j, k));
            AmpTwo->SetPoint(count, j, k, Amplitude2D(waveFunction2D(nx, ny, j, k)));
            count++;
        }
    }
    //TCanvas *c1 = new TCanvas();
    //WaveFunction->SetTitle("Wave Function");
    //WaveFunction->Draw();
    //TCanvas *c2 = new TCanvas();
    //Amplitude->SetTitle("Amplitude");
    //Amplitude->Draw();
    TCanvas *c3 = new TCanvas();
    gStyle->SetPalette(1);
    WaveFunctionTwo->SetTitle("Wavefunction");
    WaveFunctionTwo->Draw("surf1");
    TCanvas *c4 = new TCanvas();
    gStyle->SetPalette(1);
    AmpTwo->SetTitle("Amplitude");
    AmpTwo->Draw("surf1");

    c3->Print("wavefunction.png");
    c4->Print("amplitude.png");
}