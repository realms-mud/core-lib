//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ballista");
    addAlias("siege ballista");
    addAlias("bolt thrower");

    addItemTemplate(
        "The ballista is a large siege engine, its wooden frame supporting a "
        "powerful torsion mechanism. A long groove holds massive bolts, and a "
        "crank is used to draw back the arm. The weapon is aimed at distant "
        "targets, ready to unleash deadly force. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a ballista is barely visible, its form lost in the "
        "shadows"
    );
    addLowLightDescriptionTemplate(
        "a ballista stands in the gloom, its frame and arm just visible"
    );
    addDimLightDescriptionTemplate(
        "the ballista is faintly illuminated, its torsion mechanism and arm "
        "just visible"
    );
    addSomeLightDescriptionTemplate(
        "the ballista is clearly visible, its construction and deadly purpose "
        "apparent"
    );
    addAdjectives(({ "large", "wooden", "torsion", "siege", "mounted" }));
    addDescriptionTemplate("a ##Adjective## ballista aimed at the field");
}
