//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hay bale");
    addAlias("bale");
    addAlias("straw bale");
    addAlias("bale of hay");

    addAdjectives(({ "golden", "dusty", "large", "tightly-bound",
        "weathered", "fresh", "dry", "sweet-smelling", "stacked",
        "sun-warmed" }));

    addDescriptionTemplate("a ##Adjective## hay bale bound with rough twine");

    addItemTemplate(
        "The hay bale is tightly packed and bound with coarse twine, its "
        "golden stalks poking out at every angle. It smells of dry grass "
        "and summer sun, and loose wisps of hay scatter in the faintest "
        "breeze. A few field mice have probably made their homes within."
    );

    addSomeLightDescriptionTemplate(
        "a hay bale sits nearby, golden and fragrant in the light"
    );
    addDimLightDescriptionTemplate(
        "a large bale of hay is visible, pale against the ground"
    );
    addLowLightDescriptionTemplate(
        "a large pale shape suggests a bale of hay or straw"
    );
    addNearDarkDescriptionTemplate(
        "the sweet scent of dried hay suggests a bale is nearby"
    );
}
