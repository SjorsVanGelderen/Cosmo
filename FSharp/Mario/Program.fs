(*
Example of using the F# Cosmo bindings
Copyright 2017, Sjors van Gelderen
*)

module Program

open Cosmo
open Poke

(************************
Helpers
************************)

let constrain value min max =
    if value < min then
        min
    elif value > max then
        max
    else
        value


(************************
Body
************************)

type Body =
    {
        x  : double
        y  : double
        vx : double
        vy : double
    }

let bodyZero : Body =
    {
        x  = 0.0
        y  = 0.0
        vx = 0.0
        vy = 0.0
    }

let updateBody (body : Body) =
    {
        x  = constrain (body.x + body.vx) 0.0 320.0
        y  = constrain (body.y + body.vy) 0.0 240.0
        vx = body.vx * 0.8
        vy = body.vy * 0.8
    }


(************************
Mario
************************)

type Direction = Left | Right

type Mario =
    {
        body      : Body
        direction : Direction
    }

let marioZero : Mario =
    {
        body      = bodyZero
        direction = Left
    }

let updateMario (mario : Mario) = { mario with body = updateBody mario.body }

let drawMario (mario : Mario) = Cosmo.DrawImage ("mario.png", mario.body.x, mario.body.y)


(************************
Brick
************************)

type Brick =
    {
        body   : Body
        bumped : bool
    }

let brickZero : Brick =
    {
        body   = bodyZero
        bumped = false
    }

let updateBrick (brick : Brick) = { brick with body = updateBody brick.body }

let drawBrick (brick : Brick) = Cosmo.DrawImage ("brick.png", brick.body.x, brick.body.y)


(************************
Loop
************************)

let rec loop (mario : Mario) (brick : Brick) =
    Cosmo.DrawImage ("world.png", 0.0, 0.0)
    drawMario mario
    drawBrick brick

    Poke.Poll()

    if Poke.KeyPressed(37) then
        printfn "Key pressed"

    if Poke.KeyReleased(37) then
        printfn "Key released"

    if Poke.KeyHeld(37) then
        printfn "Key held down"
    
    if (Cosmo.Update ()) = 0 then
        let mario = updateMario mario
        let brick = updateBrick brick
        
        loop <| mario <| brick


(************************
Start
************************)

[<EntryPoint>]
let main args =
    if (Cosmo.Init ()) < 0 then
        printfn "Failed to initialize Cosmo"
    
    if (Poke.Init()) < 0 then
        printfn "Failed to initialize Poke"
    
    loop { marioZero with body = { marioZero.body with vx = 10.0 } } brickZero
    
    Cosmo.Terminate ()
    Poke.Terminate ()
    
    0
