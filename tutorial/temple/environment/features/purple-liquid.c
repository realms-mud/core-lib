//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("purple liquid");
    addAdjectives(({ "thick, glowing", "luminous, roiling", 
        "viscous, incandescent" }));

    addDescriptionTemplate("that a ##Adjective## purple liquid fills the room, "
        "occasion ripples gyrating along the visible surface where a path "
        "has been sliced through it. The liquid is held at bay from the "
        "path by some unseen barrier - or perhaps, despite its appearance, "
        "it is as solid as rock. It is impossible to tell for sure - the "
        "constant bursts of lightning coursing through the  substance are "
        "enough to keep even the most foolhardy away");
    addSourceOfLight(10);

    addItemTemplate("the liquid appears to be purple and, while water-like, "
        "also appears to be significantly more viscous. It pulsates with "
        "energies, occasionally small bolts of purple lightning playing "
        "along the visible surface");

    addAlias("liquid");
}
