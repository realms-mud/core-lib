//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("artifact pedestal");
    addAlias("pedestal");
    addAlias("display stand");
    addAlias("exhibit base");

    addAdjectives(({ "wooden", "polished", "sturdy", "prominent",
        "centerpiece" }));

    addDescriptionTemplate("##Adjective## pedestal displaying a significant "
        "historical artifact");

    addItemTemplate("The wooden stand is positioned to draw attention to the "
        "important artifact it holds, with a small descriptive plaque attached "
        "to its front");

    addSomeLightDescriptionTemplate("a polished wooden pedestal supporting a "
        "notable item of historical significance");

    addDimLightDescriptionTemplate("a stand of some sort with what appears to "
        "be an artifact positioned on top");

    addLowLightDescriptionTemplate("the silhouette of a display stand with "
        "something resting on it");

    addNearDarkDescriptionTemplate("a vague shape that might be supporting "
        "something of importance");
}
