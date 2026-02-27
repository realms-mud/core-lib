//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("specimen jar");
    addAlias("jar");
    addAlias("glass jar");
    addAlias("preserving jar");

    addAdjectives(({ "glass", "sealed", "murky", "labeled", "dusty",
        "old", "stoppered", "curious", "dark", "strange" }));

    addDescriptionTemplate("a ##Adjective## specimen jar on a shelf");

    addItemTemplate(
        "The specimen jar is a thick glass vessel sealed with a wax-coated "
        "cork, its contents suspended in a yellowish preserving liquid. The "
        "glass is slightly warped with age, and a faded paper label is "
        "pasted to the front in a careful hand. What floats within is "
        "difficult to identify with certainty."
    );

    addSomeLightDescriptionTemplate(
        "a specimen jar sits on a shelf, something suspended in murky liquid"
    );
    addDimLightDescriptionTemplate(
        "a glass jar of murky liquid glints faintly on a shelf"
    );
    addLowLightDescriptionTemplate(
        "a glass shape glints faintly on a shelf"
    );
    addNearDarkDescriptionTemplate(
        "the faint scent of preserving spirits comes from a shelf nearby"
    );
}
