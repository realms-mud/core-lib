//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("press");
    addAlias("linen press");
    addAlias("wooden press");
    addAlias("cabinet");

    addAdjectives(({ "wooden", "broad", "carved", "old", "sturdy", "panelled",
        "plain", "functional", "tall", "heavy" }));

    addDescriptionTemplate("a ##Adjective## press with shelves for linens");

    addItemTemplate(
        "This press is a broad wooden cabinet with shelves for storing linens "
        "or clothing. The doors are panelled and fitted with iron handles, and "
        "the wood is carved with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden press stands against the wall, its doors closed"
    );
    addDimLightDescriptionTemplate(
        "a press is visible in the gloom, its outline broad and tall"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a press can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a press is present, but details are lost in "
        "the darkness"
    );
}
