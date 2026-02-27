//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("feeding trough");
    addAlias("manger");
    addAlias("feed trough");
    addAlias("hay rack");

    addAdjectives(({ "wooden", "long", "rough-hewn", "well-chewed",
        "old", "sturdy", "straw-filled", "battered", "gnawed", "low" }));

    addDescriptionTemplate("a ##Adjective## feeding trough for animals");

    addItemTemplate(
        "The feeding trough is a long wooden box raised on squat legs, "
        "its rim gnawed and splintered by the teeth of impatient livestock. "
        "Wisps of hay and scattered grain litter its bottom and the ground "
        "around it. The wood is darkened with age and animal slobber."
    );

    addSomeLightDescriptionTemplate(
        "a wooden feeding trough sits nearby, scattered with hay and grain"
    );
    addDimLightDescriptionTemplate(
        "a long low trough is visible, its contents indistinct"
    );
    addLowLightDescriptionTemplate(
        "a long low shape suggests a feeding trough"
    );
    addNearDarkDescriptionTemplate(
        "the scent of hay and grain suggests a feeding trough is near"
    );
}
