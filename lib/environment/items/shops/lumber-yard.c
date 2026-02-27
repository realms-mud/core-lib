//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lumber yard interior");

    addItemTemplate(
        "The lumber yard's shopfront opens onto a broad yard stacked with "
        "timber. Inside, the office space is rustic but organized. Sample "
        "planks of oak, pine, ash, and exotic darkwood lean against the "
        "walls, each marked with a price tag. A counter holds measuring "
        "tools, a hand adze, and a ledger listing current stock. Through "
        "a wide doorway, the yard itself is visible: stacks of seasoning "
        "lumber sorted by type and thickness, a pit saw for cutting beams, "
        "and a wagon bay for loading. The rich, resinous smell of fresh-cut "
        "wood and sawdust permeates everything."
    );

    addNearDarkDescriptionTemplate(
        "the lumber yard's office is dark, the sample planks along the "
        "walls invisible, though the strong scent of cut wood remains"
    );
    addLowLightDescriptionTemplate(
        "the lumber office is dimly lit, the sample planks just pale "
        "shapes leaning against the shadowed walls"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the sample planks and the counter with its "
        "tools, the timber yard visible as stacked shapes through the door"
    );
    addSomeLightDescriptionTemplate(
        "the lumber office is bright enough to read the price tags on the "
        "sample planks and see the sorted timber stacks in the yard beyond"
    );
    addDescriptionTemplate(
        "light fills the lumber office and streams into the yard, showing "
        "the warm grain of the sample planks and the neatly stacked timber"
    );
}
