//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cave");

    addAdjectives(({
        "natural cavern with rough stone walls and uneven floors",
        "damp cave where water drips steadily from stalactites overhead",
        "winding cave passage carved by ancient waters through solid rock",
        "expansive underground chamber with towering rock formations",
        "narrow cave tunnel with jagged walls that glisten with moisture",
        "echoing cavern where every sound reverberates off the stone"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black cave where complete darkness swallows everything and "
        "only the sound of dripping water hints at the vast space around you"
    );

    addLowLightDescriptionTemplate(
        "a cave shrouded in deep shadow, where only vague shapes of rock "
        "formations and uneven ground can be discerned in the gloom"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where faint light reveals glistening "
        "stone surfaces and casts eerie shadows across the cavern walls"
    );

    addSomeLightDescriptionTemplate(
        "a ##Adjective##, where natural light illuminates crystalline "
        "formations, flowing stone, and the rough texture of ancient bedrock"
    );
}