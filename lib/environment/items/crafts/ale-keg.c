//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ale keg");
    addAlias("keg");
    addAlias("beer keg");
    addAlias("tapped keg");

    addAdjectives(({ "wooden", "tapped", "small", "iron-banded",
        "sweating", "cool", "well-used", "stout", "foamy", "damp" }));

    addDescriptionTemplate("a ##Adjective## ale keg tapped and ready to pour");

    addItemTemplate(
        "The ale keg is a stout wooden cask, smaller than a wine barrel "
        "but heavy with its contents. A wooden tap is hammered into the "
        "front, and a damp ring on the bar beneath it shows where many "
        "a tankard has been filled. The wood sweats with condensation "
        "and the air around it smells of yeast and hops."
    );

    addSomeLightDescriptionTemplate(
        "an ale keg sits on the bar, its tap dripping and ready"
    );
    addDimLightDescriptionTemplate(
        "a small barrel with a tap is visible on the bar"
    );
    addLowLightDescriptionTemplate(
        "a small barrel-shaped object sits on the bar"
    );
    addNearDarkDescriptionTemplate(
        "the smell of ale and hops fills the air near the bar"
    );
}
