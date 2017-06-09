(*
The Cosmo bindings
Copyright 2017, Sjors van Gelderen
*)

module Cosmo

open System.Runtime.InteropServices

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int Init()

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void Terminate()

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void DrawLine(double x0, double y0, double x1, double y1)

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void DrawRectangle(double x, double y, double w, double h)

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void DrawImage(string filename, double x, double y)

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int Update()
