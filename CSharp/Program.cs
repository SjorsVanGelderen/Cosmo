/*
  Example of using the Cosmo C# bindings
  Copyright 2017, Sjors van Gelderen
*/

using System;
using Cosmo;

namespace CosmoBindings
{
    static class Program
    {
	static void DrawPrimitives(double theta)
	    {
		// Draw primitives
		Cosmo.Cosmo.DrawImage("image.png", 0.0, 0.0);
		
		Cosmo.Cosmo.DrawLine(256.0,
			       256.0, 
			       256.0 + Math.Cos(theta) * 128.0,
			       256.0 + Math.Sin(theta) * 128.0);
		
		Cosmo.Cosmo.DrawRectangle(32.0, 32.0, 512.0, 256.0);
	    }
	
	static void Main()
	    {
		// Start Cosmo
		Cosmo.Cosmo.Init();

		// Run a logic loop
		bool done = false;
		double theta = 0;
		while(!done)
		{
		    // Draw something
		    DrawPrimitives(theta);
		    theta += 0.01;
		    
		    // Flip the screen and poll events
		    done = Cosmo.Cosmo.Update() != 0;
		}

		// Terminate Cosmo
		Cosmo.Cosmo.Terminate();
	    }
    }
}
