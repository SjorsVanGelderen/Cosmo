/*
  The Cosmo bindings
  Copyright 2017, Sjors van Gelderen
*/

using System;
using System.Runtime.InteropServices;

namespace Cosmo
{
    public static class Cosmo
    {
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern int Init();
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern void Terminate();
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern void DrawLine(double x0, double y0, double x1, double y1);
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern void DrawRectangle(double x, double y, double w, double h);
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern void DrawImage(string filename, double w, double h);
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	public static extern int Update();
    }
}
