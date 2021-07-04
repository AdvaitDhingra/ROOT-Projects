#include <TMath.h>

void DoubleSlit()
{

	double wavelength;
	double d = 0.0005;
	double l = 0.05;

	cout << "Wavelength in Metres:" << endl;

	cin >> wavelength;

	TH1F *pattern = new TH1F("Interference Pattern", "Pattern", 50, -0.00000000005, 0.00000000005);



	for (int i = 0; i < 5; i++) {
		pattern->Fill(l*i*d*wavelength);
	}
	for (int j = -1; j > -5; j--) {
		pattern->Fill(l*j*d*wavelength);
	}


	pattern->Draw();


}
