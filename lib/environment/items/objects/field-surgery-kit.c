//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("field surgery kit");
    addAlias("surgical supplies");
    addAlias("bandages");
    addAlias("field kit");

    addAdjectives(({ "neat", "well-stocked", "canvas", "military" }));

    addDescriptionTemplate("a ##Adjective## field surgery kit");
    addItemTemplate(
        "The canvas kit holds folded linen, clean bandages, needles, "
        "thread, a narrow pair of shears, and small stoppered jars. "
        "Everything is wrapped separately to keep the supplies dry "
        "and ready for a hurried dressing."
    );

    addSomeLightDescriptionTemplate(
        "an open field kit with clean bandages and surgical tools");
    addDimLightDescriptionTemplate(
        "a canvas medical kit beside the cot");
    addLowLightDescriptionTemplate(
        "a small canvas case with several wrapped bundles");
    addNearDarkDescriptionTemplate(
        "a low case near the bed");
}
