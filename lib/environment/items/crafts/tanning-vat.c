//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tanning vat");
    addAlias("bark vat");
    addAlias("soaking vat");
    addAlias("tanning pit");

    addAdjectives(({ "large", "reeking", "wooden", "stained",
        "bubbling", "dark", "deep", "foul-smelling", "old", "iron-banded" }));

    addDescriptionTemplate("a ##Adjective## tanning vat filled with dark liquid");

    addItemTemplate(
        "The tanning vat is a deep wooden tub filled with a dark, "
        "foul-smelling liquid — a brew of water, bark, and other agents "
        "used to cure raw hides into leather. Skins are submerged within, "
        "weighed down with stones. The stench is powerful enough to make "
        "the eyes water."
    );

    addSomeLightDescriptionTemplate(
        "a tanning vat stands open, its dark liquid surface barely moving"
    );
    addDimLightDescriptionTemplate(
        "a large vat of dark liquid is visible, its smell unmistakable"
    );
    addLowLightDescriptionTemplate(
        "a large tub of some liquid sits in the work area"
    );
    addNearDarkDescriptionTemplate(
        "an overpowering smell of tanning chemicals pervades the area"
    );
}
