//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chest");
    addAlias("wooden chest");
    addAlias("storage chest");
    addAlias("trunk");

    addAdjectives(({ "large", "wooden", "carved", "old", "sturdy", "broad",
        "plain", "functional", "heavy", "iron-bound" }));

    addDescriptionTemplate("a ##Adjective## chest with iron bands and a heavy lid");

    addItemTemplate(
        "This chest is a large, sturdy box made from thick wood and bound with "
        "iron bands. The lid is heavy and fitted with a simple lock, and the "
        "sides are carved with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden chest sits against the wall, its lid closed"
    );
    addDimLightDescriptionTemplate(
        "a chest is visible in the gloom, its outline large and boxy"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a chest can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a chest is present, but details are lost in "
        "the darkness"
    );
}
