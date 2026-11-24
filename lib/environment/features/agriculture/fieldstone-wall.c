//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fieldstone wall");
    addAlias("stone wall");
    addAlias("town wall");
    addDescriptionTemplate("a low wall of fitted fieldstone");
    addNearDarkDescriptionTemplate("a dark ridge of stone");
    addLowLightDescriptionTemplate("a low stone wall bordering the road");
    addDimLightDescriptionTemplate("a weathered fieldstone wall");
    addSomeLightDescriptionTemplate("a carefully fitted wall of fieldstone");
    addItemTemplate("The wall is built from local fieldstone, its broad "
        "base braced by smaller wedge stones. Repairs of newer pale rock "
        "mark the sections closest to the town road. It is low enough to "
        "see over from the fields, but wide enough to stop a cart.");
}
