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
	private static extern int MeaningOfLife();
	
	[DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)]
	private static extern int StringLength(string message);
	
	static void Main()
	    {
		Console.WriteLine("{0}", MeaningOfLife());
		Console.WriteLine("{0}", StringLength("Papua"));
	    }
    }
}
