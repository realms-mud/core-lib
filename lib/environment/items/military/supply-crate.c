//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("supply crate");
    addAlias("crate");
    addAlias("supply box");

    addAdjectives(({ "wooden", "sturdy", "sealed", "heavy", "military" }));
    addDescriptionTemplate("a ##Adjective## supply crate marked with military insignia");

    addItemTemplate(
        "The supply crate is a heavy wooden box, reinforced with iron bands. "
        "Stenciled markings indicate its contents-arrows, rations, or other "
        "military necessities. The lid is secured with a stout rope."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a supply crate is barely visible, its markings lost in "
        "the darkness"
    );
    addLowLightDescriptionTemplate(
        "a supply crate sits in the gloom, its shape just discernible"
    );
    addDimLightDescriptionTemplate(
        "the supply crate is faintly illuminated, its iron bands and rope "
        "bindings just visible"
    );
    addSomeLightDescriptionTemplate(
        "the supply crate is clearly visible, its markings and sturdy "
        "construction apparent"
    );
    addDescriptionTemplate(
        "sunlight shines on the supply crate, making its markings and "
        "reinforcements stand out"
    );
}
