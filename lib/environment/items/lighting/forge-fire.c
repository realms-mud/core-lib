//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forge fire");
    addAlias("forge");
    addAlias("smithy fire");
    suppressEntryMessage();

    addDescriptionTemplate(
        "the forge fire is cold, its bed of coals blackened and still"
    );
    addActiveSourceOfLight(10,
        "the forge fire blazes with intense heat, its coals glowing white-hot "
        "and lighting the smithy"
    );

    addFireDescriptions(({
        "the forge fire is cold, its bed of coals blackened and still",
        "is a forge fire with faintly glowing embers among the coals",
        "is a forge fire where occasional flickers of red flame dance among the embers",
        "is a forge fire with small flames licking at the remains of charcoal",
        "is a forge fire where flames steadily consume the fuel, crackling softly",
        "is a forge fire where flames dance around the coals, casting a harsh, bright glow",
        "is a forge fire with a strong blaze that sends sparks flying as it burns",
        "is a forge fire with a vigorous, white-hot blaze that roars in the smithy",
        "the forge fire blazes with intense heat, lighting the smithy with a fierce glow"
        }));

    addItemTemplate(
        "The forge fire is set in a stone hearth, surrounded by tools and "
        "anvils. The air shimmers with heat, and the scent of hot metal lingers. "
        "##UseDescriptionSet##"
    );
}
