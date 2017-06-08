(*
   Example of using the F# Cosmo bindings
*)

module Program

open Microsoft.FSharp.Math

// The bindings
open System.Runtime.InteropServices

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int Init();

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void Terminate();

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void DrawLine(double x0, double y0, double x1, double y1);

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern void DrawRectangle(double x, double y, double w, double h);

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int Update();

// The main loop
let rec loop theta =
    // Draw primitives
    DrawLine (256.0,
              256.0,
              256.0 + (cos theta) * 128.0,
              256.0 + (sin theta) * 128.0)
    
    DrawRectangle (32.0, 32.0, 512.0, 256.0)
    
    // Flip the screen and poll events
    if (Update ()) = 0 then
        // Recursively continue the loop until the exit flag is set
        loop <| theta + 0.01

[<EntryPoint>]
let main args =
    // Start Cosmo
    Init () |> ignore

    // Run a logic loop
    loop 0.0

    // Terminate Cosmo
    Terminate ()
    
    0
