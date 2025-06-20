//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("archery target");

    addItemTemplate(
        "The archery target is a sturdy, circular bundle of tightly bound straw, "
        "its surface painted with concentric rings in red, blue, and gold. "
        "Several arrows are already embedded in the target, some clustered near "
        "the center, others scattered toward the edges. The target is propped "
        "securely against a stack of hay bales, which help absorb stray shots. "
        "The ground nearby is trampled and littered with broken shafts and "
        "feathers. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of an archery target is barely visible, with only the "
        "faintest glint from arrowheads"
    );
    addLowLightDescriptionTemplate(
        "a dim archery target stands backed by hay bales, its rings hard to "
        "distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "the archery target is faintly illuminated, its painted rings and a "
        "few embedded arrows just visible"
    );
    addSomeLightDescriptionTemplate(
        "the archery target is clearly visible, with colored rings and several "
        "arrows protruding from its surface"
    );
    addAdjectives(({ "circular", "painted", "straw", "training", "bullseye" }));
    addDescriptionTemplate("a ##Adjective## archery target with concentric rings");
}
