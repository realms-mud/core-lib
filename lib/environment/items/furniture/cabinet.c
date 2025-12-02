//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cabinet");
    addAlias("wooden cabinet");

    addAdjectives(({ "sturdy", "wooden", "carved", "tall", "ornate",
        "panelled", "heavy", "old", "functional" }));

    addDescriptionTemplate("a ##Adjective## cabinet with iron hinges and a heavy latch");

    addItemTemplate(
        "This cabinet is built from thick oak, its doors set with "
        "wrought iron hinges and a heavy latch. The panels are carved with "
        "simple geometric designs, and the interior offers ample storage for "
        "dishes, linens, or valuables."
    );

    addSomeLightDescriptionTemplate(
        "a wooden cabinet stands against the wall, its doors closed and "
        "surface worn by years of use"
    );
    addDimLightDescriptionTemplate(
        "a sturdy cabinet is visible in the gloom, its outline broad and "
        "imposing"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a cabinet can be made out, little more than a "
        "shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a cabinet is present, but details are lost "
        "in the darkness"
    );
}
