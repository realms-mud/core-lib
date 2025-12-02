//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("monastery steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("monastery");

    addAdjectives(({ "worn smooth by generations of sandaled feet",
        "carved with simple, unadorned lines",
        "that connect levels in quiet dignity",
        "polished by countless hours of prayer",
        "built with humble craftsmanship",
        "that echo with whispered devotions",
        "showing the patina of centuries of use",
        "constructed from locally quarried stone" }));

    addDescriptionTemplate("monastery steps ##Adjective## "
        "provide access in austere simplicity");
    addSomeLightDescriptionTemplate("monastery steps ##Adjective## "
        "connect levels with quiet dignity");
    addNearDarkDescriptionTemplate("simple stone steps can be felt "
        "in humble service");
    addLowLightDescriptionTemplate("plain monastery steps "
        "link floors with austere functionality");
    addDimLightDescriptionTemplate("monastery steps ##Adjective## "
        "connect levels with spiritual purpose");
    addSourceOfLight(1);

    addItemTemplate("The monastery steps embody the principles of their "
        "builders - simple, functional, and without ostentation. Carved "
        "from local stone by the brothers themselves, each step shows "
        "the wear of generations of faithful feet. The construction avoids "
        "unnecessary decoration, focusing instead on durability and purpose. "
        "The smooth surfaces speak of countless passages by those devoted "
        "to contemplation and service.");
}
