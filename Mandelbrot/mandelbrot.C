void mandelbrot()
{
	TGraph *mand = new TGraph();
	
	TH2F *mandel = new TH2F("Mandelbrot Set", "Set", 500, -2, 0.75, 500, -1.5, 1.5);
	
	for (float i = -3; i < 2; i+=0.001)
	{
		for (float j = -3; j <2; j+=0.001)
		{
			TComplex point(i, j);
			TComplex z = point;
			int iter = 0;
			while (z.Rho() <2 )
			{
				z = z*z + point;
				mandel->Fill(i, j);
				iter++;
				if (iter>100)
					break;
			}
		}
	}
	TCanvas *c1 = new TCanvas();
	mandel->SetContour(99);
	mandel ->Draw("colz");
	
	c1->Print("Mandelbrot.png");
	
}
