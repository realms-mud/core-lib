//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("coffer");
    addAlias("small chest");
    addAlias("lockbox");
    addAlias("wooden coffer");

    addAdjectives(({ "small", "wooden", "carved", "old", "sturdy", "ornate",
        "plain", "functional", "heavy", "iron-bound" }));

    addDescriptionTemplate("a ##Adjective## coffer with a heavy iron lock");

    addItemTemplate(
        "This coffer is a small, sturdy box made from thick wood and bound with "
        "iron bands. The lid is fitted with a heavy lock, and the sides are "
        "carved with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden coffer sits on the floor, its lid closed and locked"
    );
    addDimLightDescriptionTemplate(
        "a coffer is visible in the gloom, its outline small and boxy"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a coffer can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a coffer is present, but details are lost in "
        "the darkness"
    );
}
