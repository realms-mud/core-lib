//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("herb drying rack");
    addAlias("drying rack");
    addAlias("herb rack");
    addAlias("wooden drying rack");

    addAdjectives(({ "wooden", "upright", "broad", "old", "plain", "functional",
        "tall", "well-made", "carved", "worn" }));

    addDescriptionTemplate("a ##Adjective## herb drying rack with hanging bundles");

    addItemTemplate(
        "This herb drying rack is made from wooden poles and crossbars, with "
        "bundles of herbs hanging from strings. The frame is upright and "
        "sturdy, set near the hearth or in a warm corner."
    );

    addSomeLightDescriptionTemplate(
        "a wooden herb drying rack stands near the hearth, herbs hanging in bunches"
    );
    addDimLightDescriptionTemplate(
        "a drying rack is visible in the gloom, its outline upright and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a drying rack can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a drying rack is present, but details are lost "
        "in the darkness"
    );
}
