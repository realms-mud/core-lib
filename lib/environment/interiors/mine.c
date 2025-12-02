//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mine");

    addAdjectives(({
        "worked mine shaft with timber supports and pickaxe marks on the walls",
        "abandoned mining tunnel where old equipment lies scattered and forgotten",
        "narrow mine passage hewn through layers of rock and mineral veins",
        "expansive underground excavation with exposed ore seams in the walls",
        "dusty mine chamber where the air is thick with rock dust and stillness",
        "cramped mining tunnel shored up with weathered wooden beams"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black mine shaft where complete darkness surrounds you and "
        "only the faint scent of earth and old timber marks the worked passage"
    );

    addLowLightDescriptionTemplate(
        "a mine shrouded in deep shadow, where timber supports and rough-hewn "
        "walls are barely visible in the consuming darkness"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where lantern light reveals tool marks "
        "on stone, exposed mineral veins, and the geometry of deliberate excavation"
    );

    addSomeLightDescriptionTemplate(
        "a ##Adjective##, where sufficient light shows the evidence of labor - "
        "pickaxe scars, timber bracing, discarded tools, and glittering mineral deposits"
    );
}