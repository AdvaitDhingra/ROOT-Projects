//
// Created by AdvaitD on 22/02/2021.
// Display the wavefunction and amplitude of an electron in a box
//

#include <TMath.h>
#include <math.h>



float pi = TMath::Pi();

float L = 100; // m

int nx, ny, n;

double x[100], y[100], z[11];


float roundval(float var)
{
    float value = (int)(var*1000+.5);
    return (float)value/1000;
}
float waveFunction2D(float energyLevelx, float energyLevely, float lengthx, float lengthy)
{

    	float wave = ((roundval (sin(energyLevelx * (lengthx/L) *pi))) )*(roundval (sin(energyLevely * (lengthy/L) *pi)));
    	
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
    cout << "Enter a value for n in y direction:" << endl;
    cin >> ny;
    
	
	TGraph *two = new TGraph();
	
    TGraph2D *WaveFunctionTwo = new TGraph2D();
    TGraph2D *AmpTwo = new TGraph2D();
	
	TGraph2D *spare = new TGraph2D();
	
	
	int count = 0;
    for (int j = 0; j <= L+1; j++ )
    {
        for (int k = 0; k <= L+1; k++)
        {
        		float wave = waveFunction2D(nx, ny, j, k);
            	//WaveFunctionTwo->SetPoint(count, j, k, wave);
            	WaveFunctionTwo->SetPoint(count, j, k, wave);
            	AmpTwo->SetPoint(count, j, k, wave*wave);
            	if (j == 0 || k == 0 || j == L || k == L)
            		cout << waveFunction2D(nx, ny, 0, 1) << endl;
            	count++;

        }
    }
    TCanvas *c1 = new TCanvas();
    WaveFunctionTwo->SetTitle("Wavefunction");
    WaveFunctionTwo->SetNpx(150);
    WaveFunctionTwo->SetNpy(150);
    WaveFunctionTwo->Draw("AP");
    TCanvas *c2 = new TCanvas();
    AmpTwo->GetXaxis()->SetTitle("x");
    AmpTwo->GetYaxis()->SetTitle("y");
    AmpTwo->Draw("surf1");
    
    c1->Print("wavefunction.png");
    c2->Print("amplitude.png");
}
