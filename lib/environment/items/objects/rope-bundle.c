//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rope bundle");
    addAlias("rope");
    addAlias("hemp rope");
    addAlias("coil of rope");

    addAdjectives(({ "thick", "hemp", "coiled", "frayed", "heavy",
        "new", "well-used", "tarred", "rough", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## bundle of rope coiled on the ground");

    addItemTemplate(
        "The rope is a heavy coil of hemp, its fibers twisted into thick "
        "cordage strong enough to haul timber or moor a boat. The ends "
        "are bound with twine to prevent fraying, and the whole bundle "
        "smells of tar and hemp oil. It lies in a neat coil on the ground."
    );

    addSomeLightDescriptionTemplate(
        "a coil of thick rope lies on the ground, heavy and well-made"
    );
    addDimLightDescriptionTemplate(
        "a coil of rope is visible on the ground"
    );
    addLowLightDescriptionTemplate(
        "a coiled shape lies on the ground"
    );
    addNearDarkDescriptionTemplate(
        "the rough smell of hemp and tar comes from the ground nearby"
    );
}
