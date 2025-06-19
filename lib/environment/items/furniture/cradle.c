//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cradle");
    addAlias("baby cradle");
    addAlias("wooden cradle");
    addAlias("rocking cradle");

    addAdjectives(({ "wooden", "small", "rocking", "carved", "old", "worn",
        "plain", "decorated", "sturdy", "gentle" }));

    addDescriptionTemplate("a ##Adjective## cradle with curved rockers");

    addItemTemplate(
        "This cradle is made from smooth wood, with curved rockers that allow "
        "it to gently sway. The sides are carved with simple patterns, and the "
        "interior is just large enough for an infant."
    );

    addSomeLightDescriptionTemplate(
        "a wooden cradle stands near the hearth, its rockers gently curved"
    );
    addDimLightDescriptionTemplate(
        "a cradle is visible in the gloom, its outline small and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a cradle can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a cradle is present, but details are lost in "
        "the darkness"
    );
}
