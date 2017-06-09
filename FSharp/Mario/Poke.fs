(*
The Poke bindings
Copyright 2017, Sjors van Gelderen
*)

module Poke

open System.Runtime.InteropServices

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern int Init()

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern void Terminate()

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern void Poll()

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern bool KeyPressed(int key)

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern bool KeyReleased(int key)

[<DllImport("Poke", CallingConvention = CallingConvention.Cdecl)>]
extern bool KeyHeld(int key)
