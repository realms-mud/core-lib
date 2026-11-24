//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("calcite rib");
    addAlias("limestone rib");
    addAlias("mineral rib");

    addDescriptionTemplate("a pale calcite rib along the cave wall");
    addItemTemplate(
        "A raised seam of calcite divides the limestone wall. Old water "
        "marks darken its lower edge, and the smooth stone reflects any "
        "light back toward the tunnel."
    );

    addNearDarkDescriptionTemplate(
        "a raised seam in the limestone");
    addLowLightDescriptionTemplate(
        "a pale rib running along the cave wall");
    addDimLightDescriptionTemplate(
        "a calcite seam with dark waterlines at its base");
    addSomeLightDescriptionTemplate(
        "a smooth calcite rib dividing the limestone wall");
}
