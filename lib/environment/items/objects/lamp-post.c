//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lamp post");
    addAlias("street lamp");
    addAlias("lamppost");
    addAlias("street lantern");

    addAdjectives(({ "iron", "tall", "ornate", "weathered", "sturdy",
        "wrought-iron", "soot-blackened", "old", "elegant", "functional" }));

    addDescriptionTemplate("a ##Adjective## lamp post standing by the road");

    addActiveSourceOfLight(8,
        "a lamp post casts a warm pool of light across the road"
    );

    addItemTemplate(
        "The lamp post is a tall iron standard topped with a glass-paned "
        "lantern housing. The iron is worked into simple scrollwork where "
        "the arm meets the post, and the glass is darkened with soot. A "
        "small hook and chain allow the lamp to be lowered for tending."
    );

    addSomeLightDescriptionTemplate(
        "a tall lamp post stands by the road, its lantern glowing warmly"
    );
    addDimLightDescriptionTemplate(
        "a lamp post is visible, its lantern casting a feeble glow"
    );
    addLowLightDescriptionTemplate(
        "a tall iron post stands by the road, its lamp barely flickering"
    );
    addNearDarkDescriptionTemplate(
        "a faint point of light atop a tall post marks a street lamp"
    );
}
