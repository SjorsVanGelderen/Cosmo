(*
Example of using the F# Cosmo bindings
Copyright 2017, Sjors van Gelderen
*)

module Program

open Cosmo

// The main loop
let rec loop theta =
    // Draw primitives
    Cosmo.DrawImage ("image.png", 0.0, 0.0)
    
    Cosmo.DrawLine (256.0,
                    256.0,
                    256.0 + (cos theta) * 128.0,
                    256.0 + (sin theta) * 128.0)
    
    Cosmo.DrawRectangle (32.0, 32.0, 512.0, 256.0)
    
    // Flip the screen and poll events
    if (Cosmo.Update ()) = 0 then
        // Recursively continue the loop until the exit flag is set
        loop <| theta + 0.01

[<EntryPoint>]
let main args =
    // Start Cosmo
    Cosmo.Init () |> ignore

    // Run a logic loop
    loop 0.0

    // Terminate Cosmo
    Cosmo.Terminate ()
    
    0
