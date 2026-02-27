//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bucket");
    addAlias("pail");
    addAlias("wooden bucket");
    addAlias("water bucket");

    addAdjectives(({ "wooden", "battered", "iron-banded", "leaky",
        "sturdy", "old", "dented", "well-used", "damp", "mossy" }));

    addDescriptionTemplate("a ##Adjective## bucket sitting on the ground");

    addItemTemplate(
        "The bucket is made of wooden staves bound with iron bands, its "
        "interior stained dark from years of carrying water, slops, and "
        "whatever else needed hauling. The rope handle is frayed but "
        "still serviceable."
    );

    addSomeLightDescriptionTemplate(
        "a wooden bucket sits on the ground, its iron bands dull with use"
    );
    addDimLightDescriptionTemplate(
        "a bucket is visible on the ground, its shape round and squat"
    );
    addLowLightDescriptionTemplate(
        "a small round shape on the ground might be a bucket"
    );
    addNearDarkDescriptionTemplate(
        "something small and round sits on the ground nearby"
    );
}
