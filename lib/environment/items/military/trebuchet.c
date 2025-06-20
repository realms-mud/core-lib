//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trebuchet");
    addAlias("siege engine");
    addAlias("counterweight trebuchet");

    addAdjectives(({ "massive", "wooden", "counterweighted", "siege", "towering" }));
    addDescriptionTemplate("a ##Adjective## trebuchet with a long throwing arm and sling");

    addItemTemplate(
        "The trebuchet is a massive siege engine, its wooden frame reinforced "
        "with iron bands. A long throwing arm is balanced by a heavy "
        "counterweight, and a sling hangs ready to hurl stones at distant "
        "walls. Ropes and pulleys are arranged for loading and firing. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a trebuchet is barely visible, its bulk looming in the "
        "darkness"
    );
    addLowLightDescriptionTemplate(
        "a trebuchet stands in the gloom, its arm and frame little more than "
        "shadows"
    );
    addDimLightDescriptionTemplate(
        "the trebuchet is faintly illuminated, its massive arm and counterweight "
        "just visible"
    );
    addSomeLightDescriptionTemplate(
        "the trebuchet is clearly visible, its ropes and sling ready for use"
    );
    addDescriptionTemplate(
        "sunlight shines on the trebuchet, highlighting its impressive size and "
        "engineering"
    );
}
