/*
  Example of using the Cosmo C# bindings
*/

using System;
using System.Runtime.InteropServices;

namespace CosmoBindings
{
    static class Program
    {
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern int Init();

	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern void Terminate();

	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern void DrawLine(double x0, double y0, double x1, double y1);

	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern void DrawRectangle(double x, double y, double w, double h);

	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern void DrawImage(string filename, double w, double h);
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern int Update();
	
	static void DrawPrimitives(double theta)
	    {
		// Draw primitives
		DrawImage("image.png", 0.0, 0.0);
		
		DrawLine(256.0,
			 256.0, 
			 256.0 + Math.Cos(theta) * 128.0,
			 256.0 + Math.Sin(theta) * 128.0);
		
		DrawRectangle(32.0, 32.0, 512.0, 256.0);
	    }
	
	static void Main()
	    {
		// Start Cosmo
		Init();

		// Run a logic loop
		bool done = false;
		double theta = 0;
		while(!done)
		{
		    // Draw something
		    DrawPrimitives(theta);
		    theta += 0.01;
		    
		    // Flip the screen and poll events
		    done = Update() != 0;
		}

		// Terminate Cosmo
		Terminate();
	    }
    }
}
