//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spring votive stones");
    addAlias("votive stones");
    addAlias("prayer stones");
    addAdjectives(({ "stacked", "weathered", "small", "carefully placed" }));
    addDescriptionTemplate("##Adjective## stones beside the spring");
    addNearDarkDescriptionTemplate("a small cairn beside running water");
    addLowLightDescriptionTemplate("stones balanced beside the spring");
    addDimLightDescriptionTemplate(
        "a neat stack of flat stones above the waterline");
    addSomeLightDescriptionTemplate(
        "a cairn of flat stones with tokens tucked between them");
    addItemTemplate("The stones are balanced rather than mortared, "
        "each one placed by a different hand. A blue thread, a "
        "child's carved bird, and a copper button have been left "
        "between the layers. The spring runs clear beneath them; "
        "none of the offerings have been taken.");
}
