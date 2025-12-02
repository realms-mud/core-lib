//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wooden hall");

    addAdjectives(({
        "serene wooden hall, nestled among towering trees and thick foliage",
        "earthy hall, its walls woven with vines and branches, blending with the forest",
        "natural sanctuary built from wood and stone, where vines wrap around every corner",
        "wooden hall surrounded by the whispers of the forest, the scent of fresh pine in the air",
        "peaceful hall, the wooden beams entwined with creeping ivy and moss",
        "forest hall, its structure seamlessly integrated with the living trees around it"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a dim hall, the outlines of wooden walls and vines barely visible in the low light, the faint rustling of leaves outside");
    addLowLightDescriptionTemplate("a softly lit hall, the warm glow of lanterns reflecting off wooden walls and vine-covered beams");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the shadows shifting as the vines sway gently in the breeze");
    addSomeLightDescriptionTemplate("a softly illuminated ##Adjective##, where light filters through the leaves outside and casts patterns on the wooden floor");
}
