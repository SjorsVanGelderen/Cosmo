(*
   Example of using the F# Cosmo bindings
*)

module Program

open System.Runtime.InteropServices

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int MeaningOfLife();

[<DllImport("Cosmo", CallingConvention = CallingConvention.Cdecl)>]
extern int StringLength(string message);

[<EntryPoint>]
let main args =
    printfn "%A, %A" <| MeaningOfLife () <| StringLength "Papua"
    0
