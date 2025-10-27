//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dungeon");

    addAdjectives(({
        "dank dungeon corridor with crumbling stone walls and iron-barred cells",
        "oppressive underground chamber reeking of mold and decay",
        "forbidding dungeon passage lit by guttering torches on rusted brackets",
        "grim stone cell with heavy chains bolted to the damp walls",
        "claustrophobic dungeon tunnel where moisture seeps through ancient mortar",
        "dreary underground vault filled with the echoes of suffering"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black dungeon where absolute darkness presses in from all sides "
        "and the smell of damp stone and old suffering fills the stale air"
    );

    addLowLightDescriptionTemplate(
        "a dungeon shrouded in oppressive gloom, where only the faintest outlines "
        "of barred cells and stone walls can be seen in the darkness"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where flickering torchlight reveals "
        "stained stone, rusty chains, and the occasional glint of iron bars"
    );

    addSomeLightDescriptionTemplate(
        "a ##Adjective##, where torchlight illuminates the harsh reality "
        "of hewn stone walls, iron fixtures, and the grim remnants of captivity"
    );
}